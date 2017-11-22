#include <string>
#include <iostream>
#include <sstream>
#include <tins/network_interface.h>

using std::cout;
using std::wcout;
using std::endl;
using std::string;
using std::ostringstream;

using namespace Tins;

int main() {
    // Get all interfaces and iterate over them.
    for (const NetworkInterface& iface : NetworkInterface::all()) {
        string name = iface.name();
        string status = iface.is_up() ? "up" : "down";
        NetworkInterface::Info info = iface.info();

        cout << name;

#ifdef _WIN32
        // If this is running on Windows, also print the friendly name
        wcout << " (" << iface.friendly_name() << ")";
#endif // _WIN32
        cout << ": " << endl;

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
        cout << "   HW address:     " << info.hw_addr << endl
             << "   IP address:     " << info.ip_addr << endl
             << "   IPv6 addresses: " << ipv6_string << endl
             << "   Netmask:        " << info.netmask << endl
             << "   Broadcast:      " << info.bcast_addr << endl
             << "   Iface index:    " << iface.id() << endl
             << "   Status:         " << "interface " << status << endl << endl;
    }

    auto *hw = new HWAddress<6>("s5k6sryk");
    if (hw) cout << "success\n";
}