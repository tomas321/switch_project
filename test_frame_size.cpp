#include <tins/tins.h>
#include <iostream>
#include <string>

using namespace std;
using namespace Tins;

void test_frame_size() {
    PacketSender sender("lo");
    unsigned int i = 0;
    while (++i) {
        vector<char> data (1000+i*100, 66);
        TCP pkt = TCP() / RawPDU(string(data.begin(), data.end()));
        EthernetII eth = EthernetII() / IP() / pkt;
        cout << i << ". sending... " << eth.size() << " of data" << endl;
        try {
            sender.send(eth);
//            sender.send(pkt);
        } catch (socket_write_error) {
            cout << "too long msg\n";
            return;
        }
    }
}

void send_packet(string iface, string data) {
    PacketSender sender(iface);
    EthernetII pkt = EthernetII() / IP() / TCP() / RawPDU(data);
    pkt.dst_addr(EthernetII::address_type("dc:a9:71:3f:a5:57"));
    pkt.src_addr(EthernetII::address_type("6c:62:6d:34:14:11"));
    IP ippkt = IP() / TCP() / RawPDU(data);
    sender.send(pkt);

    cout << sender.default_interface().name() << endl;
}

int main() {
    vector<char> data (5000, 91);
    test_frame_size();
//    for (int i = 0; i < 100; i++) send_packet("enp3s0", string(data.begin(), data.end()) + "SIOCSARP: Network is unreachable");
    return 0;
}