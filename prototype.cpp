/**
 * Prototype for implementation of software switch
 * Sends a TCP packet of static configuration to interface with entered raw data
 *
 * used library is libtins
 * download link: libtins.github.io
 * patform: Linux (Ubuntu 16.04)
 * */

#include <tins/tins.h>
#include <iostream>
#include <iomanip>

using namespace Tins;
using namespace std;

class Prototype {
private:
    string iface;
    EthernetII::address_type hw_addr;
    int packets_sent;
public:
    string get_iface();
    EthernetII::address_type get_hw_addr();
    void set_iface(string iface);
    void set_hw_addr(EthernetII::address_type hw_addr);
    int get_numPacketSent();

    Prototype(string iface, EthernetII::address_type hw_addr);
    Prototype();
    ~Prototype();

    bool send_packet(string data);
    void print_packet(EthernetII &pdu);
    bool my_hw_addr(string iface);
    string parse_pdu_type(PDU::PDUType type);
    void list_interfaces_short();
};

// setters and getters
string Prototype::get_iface() { return this->iface; }
EthernetII::address_type Prototype::get_hw_addr() { return this->hw_addr; }
void Prototype::set_iface(string iface) { this->iface = iface; }
void Prototype::set_hw_addr(EthernetII::address_type hw_addr) { this->hw_addr = hw_addr; }
int Prototype::get_numPacketSent() { return this->packets_sent; }

Prototype::Prototype() {}
Prototype::Prototype(string iface, EthernetII::address_type hw_addr) {
    this->iface = iface;
    this->hw_addr = hw_addr;
}
Prototype::~Prototype() { cout << "prototype destroyed\n"; }

string Prototype::parse_pdu_type(PDU::PDUType type) {
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

bool Prototype::send_packet(string data) {
    PacketSender sender;

    cout << "Sending.. ";

    if (my_hw_addr(iface)) {
        cout << "ERROR: interface \"" << this->iface << "\" is not up / doesnt exist\n";
        return false;
    }

    EthernetII eth = EthernetII() / IP("10.0.0.1", "10.0.0.10") / TCP(80, 1500) / RawPDU(data);
    eth.dst_addr(EthernetII::address_type("1F:55:69:E1:C0:87"));
    eth.src_addr(this->hw_addr);
    try {
        sender.send(eth, this->iface);
    } catch (socket_write_error) {
        cout << "ERROR: too large data\n";
        return false;
    }
    print_packet(eth);
    this->packets_sent++;
    return true;
}

bool Prototype::my_hw_addr(string iface) {
    for (const NetworkInterface& iface_ : NetworkInterface::all()) {
        if (iface_.name().compare(iface) == 0 && iface_.is_up()) {
            set_hw_addr(iface_.hw_address());
            return 0;
        }
    }
    return 1;
}

void Prototype::print_packet(EthernetII &pdu) {
    string type = parse_pdu_type(pdu.pdu_type());
    cout << type << ": "
         << pdu.src_addr() << " >> " << pdu.dst_addr() << "\t"
         << pdu.inner_pdu()->find_pdu<IP>()->src_addr() << " >> " << pdu.inner_pdu()->find_pdu<IP>()->dst_addr() << endl;
}

void Prototype::list_interfaces_short() {
    cout << setw(20) << "##INTERFACE##\t\t" << "##HW ADDR##\t\t\t" << "##STATUS##\n\n";
    for (const NetworkInterface& iface : NetworkInterface::all()) {
        string name = iface.name();
        string status = iface.is_up() ? "up" : "down";
        NetworkInterface::Info info = iface.info();

        cout << setw(14) << name << "\t\t" << info.hw_addr << "\t\tinterface " << status << endl;
    }
}

int main() {
    string data, iface;
    Prototype *prototype = new Prototype;

    while (1) {
        prototype->list_interfaces_short();
        cout << "[to quit <q>]\n[to use previous <ENTER>]\ninterface> ";
        getline(cin, iface);
        if (iface.compare("") != 0) prototype->set_iface(iface);
        if (iface.compare("q") == 0) break;
        cout << "data     > ";
        getline(cin, data);
        if (!prototype->send_packet(data)) cout << endl << "frame not sent\n";
        else cout << "sent\n" << endl << endl;
    }
    cout << "frames sent in total: " << prototype->get_numPacketSent() << endl;
    return 0;
}