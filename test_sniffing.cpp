#include <tins/tins.h>
#include <iostream>
#include <string>
#include <getopt.h>
#include <fstream>

using namespace std;
using namespace Tins;

// parse PDU type to string for writing purposes
string parse_pdu_type(PDU::PDUType type) {
    if (type == PDU::ETHERNET_II) return "Ethernet_II";
    if (type == PDU::DOT3) return "IEEE_802.3";
    if (type == PDU::DOT11) return "IEEE_802.11";
    if (type == PDU::TCP) return "TCP";
    if (type == PDU::IP) return "IPv4";
    if (type == PDU::ARP) return "ARP";
    if (type == PDU::ICMP) return "ICMP";
    if (type == PDU::DNS) return "DNS";
    if (type == PDU::UDP) return "UDP";
    if (type == PDU::DHCP) return "DHCP";
    if (type == PDU::LOOPBACK) return "LOOPBACK";
    if (type == PDU::SNAP) return "SNAP";
    if (type == PDU::LLC) return "LLC";
    if (type == PDU::IPv6) return "IPv6";
    if (type == PDU::STP) return "STP";
    return "UNKNOWN"; // if other unknown protocol is found
}

// process packet method which works with the PDU at hand and prints the contents of it
bool process_pkt(PDU &pdu) {
    PacketSender sender("enp3s0");
    auto ethertype = parse_pdu_type(pdu.pdu_type());
    auto layer3_type = parse_pdu_type(pdu.inner_pdu()->pdu_type());
    IP *ip = pdu.find_pdu<IP>();
    EthernetII *eth = pdu.find_pdu<EthernetII>(); // assuming that only etherner II packets are flying



    try {
        sender.send(pdu);
        //return true;
    } catch (socket_write_error) {
        cout << "\tCAUGHT: " << ethertype << "::" << parse_pdu_type(pdu.inner_pdu()->inner_pdu()->pdu_type())
             << "::SIZE " << eth->size() << endl;
    }

    cout << ethertype;
    // check whether ip is not a NULL pointer in case an IP inner PDU was not found
    if (ip) {
        cout << " - dst IPaddr: " << ip->dst_addr()
             << " - src IPaddr: " << ip->src_addr();
    }
    // check whether eth is not a NULL pointer
    if (eth) {
        cout << " - dst MAC_addr: " << eth->dst_addr()
             << " - src MACaddr: " << eth->src_addr();
    }
    cout << " - layer3_type: " <<  layer3_type;
    // check if it contains a known transport protocol
    if (pdu.inner_pdu()->inner_pdu()) {
        auto layer4_type = parse_pdu_type(pdu.inner_pdu()->inner_pdu()->pdu_type());
        cout << " - layer4_type: " << layer4_type;
        if (layer4_type.compare("UDP") == 0) {
            UDP &udp = pdu.rfind_pdu<UDP>();
            cout << " - dst_port: " << udp.dport() << " - src_port: " << udp.sport();
        } else if(layer4_type.compare("TCP") == 0) {
            TCP &tcp = pdu.rfind_pdu<TCP>();
            //cout << " - size: " << eth->size();
        }
    }
    cout << endl;

    return true;
}

// sniffer
void sniffing(string iface) {
    SnifferConfiguration config;
    config.set_promisc_mode(true);
    Sniffer sniffer(iface, config);
    sniffer.sniff_loop(process_pkt);
}

// prints out the help.txt
void read_help() {
    string line;
    ifstream help_r("/home/tomko/Dropbox/Fiit/5.semester/Prepinanie_a_smerovanie_IP/switch_project/help.txt");

    if (help_r.is_open()) {
        while (getline(help_r, line)) {
            cout << line << endl;
        }
        help_r.close();
    } else cout << "ERROR: cant open help.txt" << endl;
}

// lists all of the interfaces (ifconfig -a)
void list_interfaces() {
    for (const NetworkInterface& iface : NetworkInterface::all()) {
        string name = iface.name();
        string status = iface.is_up() ? "up" : "down";
        NetworkInterface::Info info = iface.info();

        cout << name << ": " << endl;

        cout << "   MAC address:    " << info.hw_addr << endl
             << "   IP address:     " << info.ip_addr << endl
             << "   Netmask:        " << info.netmask << endl
             << "   Broadcast:      " << info.bcast_addr << endl
             << "   Iface index:    " << iface.id() << endl
             << "   Iface status:   " << "interface " << status << endl << endl;
    }
}

// short print of the interfaces
void list_interfaces_short() {
    for (const NetworkInterface& iface : NetworkInterface::all()) {
        string name = iface.name();
        string status = iface.is_up() ? "up" : "down";
        NetworkInterface::Info info = iface.info();

        cout << name << ": " << endl;
        cout << "   MAC address:    " << info.hw_addr << endl
             << "   Iface status:   " << "interface " << status << endl << endl;
    }
}

// checks whether a interface is available for sniffing
// if it exists and if its up
bool interface_exists(string iface_) {
    for (const NetworkInterface& iface : NetworkInterface::all()) {
        if (iface.name().compare(iface_) == 0 && iface.is_up()) return true;
    }
    return false;
}

// sends single packet to iface interface
void send_packet(string iface, string data) {
    PacketSender sender(iface);
    EthernetII pkt = EthernetII() / IP() / TCP() / RawPDU(data);
    sender.send(pkt);

    cout << sender.default_interface().name() << endl;
}

int main(int argc, char* const argv[]) {
    int option;
    int opt_index = 0;
    string iface_, data;


    static struct option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {"iflist", no_argument, 0, 'i'},
            {"send", no_argument, 0, 's'}
    };

    // compute program argument
    opterr = 0;
    while ((option = getopt_long(argc, argv, "his:", long_options, &opt_index)) != -1) {
        switch (option) {
            case 'h':
                read_help();
                return 0;
            case 'i':
                list_interfaces();
                return 0;
            case 's':
                list_interfaces_short();
                cout << "interface: ";
                getline(cin, iface_);
                if (interface_exists(iface_)) {
                    cout << "data to send: ";
                    getline(cin, data);
                    send_packet(iface_, data);
                }
                return 0;
            default:
                printf("ERROR: option '%c' is UNKNOWN\n", optopt); // optopt = unknown option
                printf("quitting...\n");
                printf("optind %d\n", optind);
                exit(1);
        }
    }

    string iface;
    list_interfaces_short();

    do {
        cout << ">>> ";
        getline(cin, iface);
    } while (!interface_exists(iface));
    sniffing(iface);

}