//
// Created by root on 17.10.2017.
//

#include "Port_sniffer.h"

#include <sstream>
#include <iostream>
#include <thread>

using namespace Tins;
using namespace std;

Port_sniffer::Port_sniffer(string interface, MAC_table *table, Filters *filters) {
    this->interface = interface;
    this->macTable = table;
    this->filters = filters;
}

Port_sniffer::Port_sniffer(MAC_table *table, Filters *filters) {
    this->macTable = table;
    this->filters = filters;
}

vector<string> Port_sniffer::getAllInterfaceNames() {
    vector<string> list;
    for (const NetworkInterface& iface : NetworkInterface::all()) {
        list.push_back(iface.name());
    }
    return list;
}

string Port_sniffer::get_port() {
    return this->interface;
}

void Port_sniffer::set_port(string port) {
    this->interface = port;
}

void Port_sniffer::set_other_port(string interface) {
    this->other_interface = interface;
}

void Port_sniffer::setInterface(string interface, string other_int) {
    set_port(interface);
    set_other_port(other_int);
    set_interface_info();
}

string Port_sniffer::parse_pdu_type(PDU::PDUType type) {
    if (type == PDU::ETHERNET_II) return "Ethernet_II";
    if (type == PDU::DOT3) return "Ethernet_802.3";
    if (type == PDU::DOT11) return "Ethernet_802.11";
    if (type == PDU::LLC) return "Ethernet_802.3_LLC";
    if (type == PDU::SNAP) return "Ethernet_802.3_SNAP";
    if (type == PDU::TCP) return "TCP";
    if (type == PDU::IP) return "IPv4";
    if (type == PDU::ARP) return "ARP";
    if (type == PDU::ICMP) return "ICMP";
    if (type == PDU::DNS) return "DNS";
    if (type == PDU::UDP) return "UDP";
    if (type == PDU::DHCP) return "DHCP";
    if (type == PDU::LOOPBACK) return "LOOPBACK";
    if (type == PDU::IPv6) return "IPv6";
    if (type == PDU::STP) return "STP";
    return "UNKNOWN"; // if other unknown protocol is found
}

QVector<PDU::PDUType> Port_sniffer::get_PDUTypes(PDU *frame) {
    QVector<PDU::PDUType> list;
    // ICMP
    auto icmpFrame = frame->find_pdu<ICMP>();
    if (icmpFrame && icmpFrame->pdu_type() == PDU::PDUType::ICMP) list.push_back(PDU::PDUType::ICMP);
    // TCP && HTTP
    auto tcpFrame = frame->find_pdu<TCP>();
    if (tcpFrame && tcpFrame->pdu_type() == PDU::PDUType::TCP) {
        if (tcpFrame->sport() == 80 || tcpFrame->dport() == 80) {
            list.push_back(PDU::PDUType::USER_DEFINED_PDU); // is HTTP protocol
        }
        list.push_back(PDU::PDUType::TCP);
    }
    // UDP
    auto udpFrame = frame->find_pdu<UDP>();
    if (udpFrame && udpFrame->pdu_type() == PDU::PDUType::UDP) list.push_back(PDU::PDUType::UDP);
    // ETHERNET 2
    auto ethFrame = frame->find_pdu<EthernetII>();
    if (ethFrame && ethFrame->pdu_type() == PDU::PDUType::ETHERNET_II) list.push_back(PDU::PDUType::ETHERNET_II);
    // ARP
    auto arpFrame = frame->find_pdu<ARP>();
    if (arpFrame && arpFrame->pdu_type() == PDU::PDUType::ARP) list.push_back(PDU::PDUType::ARP);
    // IP
    auto ipFrame = frame->find_pdu<IP>();
    if (ipFrame && ipFrame->pdu_type() == PDU::PDUType::IP) list.push_back(PDU::PDUType ::IP);

    return list;
}

bool Port_sniffer::set_interface_info() {
    Port_sniffer::Interface;
    for (const NetworkInterface& iface : NetworkInterface::all()) {
        if (iface.name().compare(this->interface) == 0) {
            continue;
        }
        NetworkInterface::Info info = iface.info();

        string ipv6_string;
        if (info.ipv6_addrs.empty()) {
            ipv6_string = "(none)";
        }
        else {
            ostringstream oss;
            for (size_t i = 0; i < info.ipv6_addrs.size(); ++i) {
                const NetworkInterface::IPv6Prefix& prefix = info.ipv6_addrs[i];
                if (i > 0) {
                    oss << ", ";
                }
                oss << prefix.address << "/" << prefix.prefix_length;
            }
            ipv6_string = oss.str();
        }
        Interface.status = iface.is_up();
        Interface.hw_addr = info.hw_addr;
        Interface.ip_addr = info.ip_addr;
        Interface.ipv6_addr = ipv6_string;
        Interface.broadcast = info.bcast_addr;
        Interface.net_mask = info.netmask;

        this->Interface = Interface;
        return true;
    }
    return false;
}

void Port_sniffer::sniffer_start() {
//    while (1) {
//        stringstream msg;
//        msg << "add attempt by " << QThread::currentThread()->currentThreadId() << endl;
//        cout << msg.str();
//        this->macTable->add_entry(HWAddress<6>("11:11:11:11:11:11"), this->interface);
//        this->macTable->add_entry(HWAddress<6>("11:11:11:11:11:22"), this->other_interface);
//
//        sleep(5);
//    }
}

void Port_sniffer::run() {
    stringstream msg;
    cout << "thread "  << this_thread::get_id() <<  " started on " << this->interface << endl;
    this->config.set_promisc_mode(true); // the sniffed frame are passed to the CPU
    this->config.set_immediate_mode(true); // no capturing delay
    this->config.set_direction(PCAP_D_IN);
    Sniffer sniffer(this->interface, this->config);
    while (1) {
        PDU *pdu = sniffer.next_packet();
        process_frame(pdu);
//        msg << "processed frame by " << this_thread::get_id() << endl;
//        cout << msg.str();
    }
}

void Port_sniffer::set_config_filter(string filter) {
    this->config.set_filter(filter);
}

void Port_sniffer::process_frame(PDU *pdu) {
    EthernetII *frame = pdu->find_pdu<EthernetII>();
    if (!frame) {
        cout << "EthernetII not found\n";
        return;
    }
    string dst_interface;
    if (!filters->checkFilters(frame, interface, other_interface, true)) {
        stringstream msg;
        msg << "Frame denied in filters (dir IN) by " << interface << endl;
        //cout << msg.str();
        return;
    }

    emit frameReceived(get_PDUTypes(frame));
    // add to MAC table if possible
    this->macTable->add_entry(frame->src_addr(), this->interface);
    //this->macTable.print_MAC_table();
    // send frame to interface only if
    auto entry = this->macTable->get_entry(frame->dst_addr());
    if (entry == nullptr) {
        // if entry with dst_addr doesnt exist => flood all ports
        send_frame(this->other_interface, frame);
        return;
    } else dst_interface = entry->port;



    // if dst addr is at the same interface => drop the frame
    if (dst_interface.compare(this->interface) != 0) {
        send_frame(dst_interface, frame);
    } else return; // drop frame
}

bool Port_sniffer::send_frame(string dst_interface, EthernetII *frame) {
    if (!filters->checkFilters(frame, dst_interface, interface)) {
        stringstream msg;
        msg << "Frame denied in filters (dir OUT) by " << dst_interface << endl;
        //cout << msg.str();
        return false;
    }

    PacketSender sender;
    sender.send(*frame, dst_interface);
    emit frameSent(get_PDUTypes(frame));
    return true;
}


/*
int main(int argc, char *argv[]) {
    MAC_table *macTable = new MAC_table();
    string port1 = "enp3s0";
    string port2 = "enp3s0";//"enx00133b9c6839";

    // port1 sniffer
    Port_sniffer *port_sniffer_1 = new Port_sniffer(macTable);
    port_sniffer_1->set_port(port1);
    port_sniffer_1->set_other_port(port2);
    port_sniffer_1->set_interface_info();
    // port2 sniffer
    Port_sniffer *port_sniffer_2 = new Port_sniffer(macTable);
    port_sniffer_2->set_port(port2);
    port_sniffer_2->set_other_port(port1);
    port_sniffer_2->set_interface_info();

//    thread t1(&Port_sniffer::sniffer_start, *port_sniffer_1);
//    thread t2(&Port_sniffer::sniffer_start, *port_sniffer_2);
//    t1.join();
//    t2.join();
    return 0;
}*/

