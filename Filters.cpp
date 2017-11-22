//
// Created by root on 15.11.2017.
//

#include <iostream>
#include <sstream>
#include "Filters.h"

using namespace std;

Filters::Filters(QObject *parent) : QThread(parent) {}

int Filters::addFilter(bool permit, string ipSrc, string ipDst, string hwSrc, string hwDst,
                       string protocol, string interface, string dir, int port) {
    lock_guard<mutex> lock(filters_mutex);
    if (checkAdresses(ipSrc, ipDst, hwSrc, hwDst)) return -1;
    // the addresses are invalid
    int key = getUniqueKey();
    Filter entry = {key, permit, ipSrc, ipDst, hwSrc, hwDst, protocol, interface, dir, port};
    this->filters.push_back(entry);
    stringstream msg;
    msg << "ADD Filer: " << key << "permit: " << permit << "size: " << filters.size() << endl;
    cout << msg.str();
    printFilters();
    QVector<string> result = filtersToStr();
    emit filtersChanged(result);

    return key;
}

int Filters::getUniqueKey() {
    time_t mytime = time((time_t*)0);
    struct tm *my_tm = localtime(&mytime);
    int t = my_tm->tm_year + my_tm->tm_mon + my_tm->tm_mday + my_tm->tm_hour + my_tm->tm_min + my_tm->tm_sec;
    return t % 65536;
}

void Filters::removeFilter(int key) {
    lock_guard<mutex> lock(filters_mutex);
    int pos = 0;
    for (auto &entry : filters) {
        if (entry.key == key) {
            filters.erase(filters.begin() + pos);
            QVector<string> result = filtersToStr();
            emit filtersChanged(result);
            printFilters();
            return;
        }
        pos++;
    }
}

void Filters::clearFilters() {
    lock_guard<mutex> lock(filters_mutex);
    auto size = filters.size();
    cout << "deleted all filters\n";
    filters.clear();
    cout << "filter size: " << filters.size() << endl;
    QVector<string> result = filtersToStr();
    emit filtersChanged(result);
}

Filters::Filter *Filters::getFilter(int key) {
    lock_guard<mutex> lock(filters_mutex);
    for (int i = 0; i < filters.size(); i++) {
        if (filters[i].key == key) {
            return &filters[i];
        }
    }
    return nullptr;
}

int Filters::checkAdresses(string ips, string ipd, string hws, string hwd) {
    try {
        if (ips.compare("") == 0) ips = "0.0.0.0";
        new IPv4Address(ips);
        if (ipd.compare("") == 0) ipd = "0.0.0.0";
        new IPv4Address(ipd);
        if (hws.compare("") == 0) hws = "00:00:00:00:00:00";
        new HWAddress<6>(hws);
        if (hwd.compare("") == 0) hws = "00:00:00:00:00:00";
        new HWAddress<6>(hwd);
    } catch (Tins::invalid_address) {
        return 1;
    }
    return 0;
}



int Filters::checkFilters(EthernetII *frame, string interface, string other_interface, bool sniffedDir) {
    PDU::PDUType type;
    IP *ip_pkt;
    ARP *arp_pkt;
    ICMP *icmp_pkt;
    TCP *tcp_pkt;
    UDP *udp_pkt;
    int retVal;
    lock_guard<mutex> lock(filters_mutex);
    for (vector<Filters::Filter>::reverse_iterator filter = filters.rbegin(); filter != filters.rend(); filter++) {
        // check direction
        stringstream msg;
        msg << "checking filter " << filter->key << "..." << endl;
        //cout << msg.str();
        if (sniffedDir) {
            if (filter->direction.compare("out") == 0) continue; // check next filter for deny
            //else if (filter->direction.compare("any")) cout << "IN ANY";
        } else {
            if (filter->direction.compare("in") == 0) continue;
            //else if (filter->direction.compare("any") == 0)
        }

        if (filter->hw_src.compare(frame->src_addr().to_string()) == 0 || filter->hw_src.compare("") == 0 &&
            filter->hw_dst.compare(frame->dst_addr().to_string()) == 0 || filter->hw_dst.compare("") == 0) {
            // hw addrs
            if (filter->interface.compare(interface) == 0) {
                // hw addrs, interface
                type = parsePDUType(filter->protocol);
                // hw addrs, interface, protocol
                if ((ip_pkt = frame->find_pdu<IP>()) && type == PDU::IP) {
                    if (filter->ip_src.compare(ip_pkt->src_addr().to_string()) == 0 || filter->ip_src.compare("") == 0 &&
                        filter->ip_dst.compare(ip_pkt->dst_addr().to_string()) == 0 || filter->ip_dst.compare("") == 0) {
                        // hw addrs, interface, protocol, ip addrs
//                            if ((retVal = checkPort(frame, filter->port, filter->permit))) return 1;
//                            else if (retVal == 0) return 0;
//                            else continue;
                        //cout << filter->protocol << endl;
                        if (filter->permit) return 1;
                        else return 0;
                    }
                } else if ((arp_pkt = frame->find_pdu<ARP>()) && type == PDU::ARP) {
                    if (filter->ip_src.compare(arp_pkt->sender_ip_addr().to_string()) == 0 || filter->ip_src.compare("") == 0 &&
                        filter->ip_dst.compare(arp_pkt->target_ip_addr().to_string()) == 0 || filter->ip_dst.compare("") == 0) {
                        // hw addrs, interface, protocol, ip addrs
//                            if ((retVal = checkPort(frame, filter->port, filter->permit))) return 1;
//                            else if (retVal == 0) return 0;
//                            else continue;
                        //cout << filter->protocol << endl;
                        if (filter->permit) return 1;
                        else return 0;
                    }
                } else if ((icmp_pkt = frame->find_pdu<ICMP>()) && type == PDU::ICMP && ip_pkt) {
                    if (filter->ip_src.compare(ip_pkt->src_addr().to_string()) == 0 || filter->ip_src.compare("") == 0 &&
                        filter->ip_dst.compare(ip_pkt->dst_addr().to_string()) == 0 || filter->ip_dst.compare("") == 0) {
//                            if ((retVal = checkPort(frame, filter->port, filter->permit))) return 1;
//                            else if (retVal == 0) return 0;
//                            else continue;
                        //cout << filter->protocol << endl;
                        if (filter->permit) return 1;
                        else return 0;
                    }
                } else if ((tcp_pkt = frame->find_pdu<TCP>()) && type == PDU::TCP && ip_pkt) {
                    if (filter->ip_src.compare(ip_pkt->src_addr().to_string()) == 0 || filter->ip_src.compare("") == 0 &&
                        filter->ip_dst.compare(ip_pkt->dst_addr().to_string()) == 0 || filter->ip_dst.compare("") == 0) {
                        // hw addrs, interface, protocol, ip addrs
                        if (filter->port == tcp_pkt->sport() || filter->port == tcp_pkt->dport() || filter->port == -1) {
                            // hw addrs, interface, protocol, ip addrs, port
                            //cout << filter->protocol << endl;
                            //if (80 == tcp_pkt->sport() || 80 == tcp_pkt->dport()) cout << "TCP has port 80\n";
                            if (filter->permit) return 1; // return 1 for permit
                            else return 0; // return 0 filter for deny
                        }
                    }
                } else if ((udp_pkt = frame->find_pdu<UDP>()) && type == PDU::UDP && ip_pkt) {
                    if (filter->ip_src.compare(ip_pkt->src_addr().to_string()) == 0 || filter->ip_src.compare("") == 0 &&
                        filter->ip_dst.compare(ip_pkt->dst_addr().to_string()) == 0 || filter->ip_dst.compare("") == 0) {
                        // hw addrs, interface, protocol, ip addrs
                        if (filter->port == udp_pkt->sport() || filter->port == udp_pkt->dport() || filter->port == -1) {
                            // hw addrs, interface, protocol, ip addrs, port
                            //cout << filter->protocol << endl;
                            //if (80 == udp_pkt->sport() || 80 == udp_pkt->dport()) cout << "UDP has port 80\n";
                            if (filter->permit) return 1; // return 1 for permit
                            else return 0; // return 0 filter for deny
                        }
                    }
                } else if (filter->protocol.compare("any") == 0){
                    // hw addrs, interface, protocol == 'any'  =>  type == PDU::UNKNOWN
                    //cout << "executing ANY\n";
                    ip_pkt = frame->find_pdu<IP>(); // expecting it has an IP header
                    if (!ip_pkt) {
                        arp_pkt = frame->find_pdu<ARP>();
                        ip_pkt = (IP *) arp_pkt;
                        if (!arp_pkt) return 1; // !!!!! implicit permit if no ip or arp packet
                    }
                    if (filter->ip_src.compare(ip_pkt->src_addr().to_string()) == 0 || filter->ip_src.compare("") == 0 &&
                        filter->ip_dst.compare(ip_pkt->dst_addr().to_string()) == 0 || filter->ip_dst.compare("") == 0) {
                        // hw addrs, interface, protocol, ip addrs, port
                        if (filter->permit) return 1;
                        else return 0;
                    }
                }
            }
        }
        // here it jumps to next filter
    }
    // return 0 if no filter satisfies
    // implicit deny
    return 0;
}

int Filters::checkPort(EthernetII *frame, int port, bool permit) {
    TCP *tcp_pkt = frame->find_pdu<TCP>();
    UDP *udp_pkt = frame->find_pdu<UDP>();
    if (tcp_pkt) {
        if (port == tcp_pkt->sport() || port == tcp_pkt->dport() || port == -1) {
            // hw addrs, interface, protocol, ip addrs, port
            if (permit) return 1; // return 1 for permit
            else return 0; // return 0 for deny
        }
    } else if (udp_pkt) {
        if (port == udp_pkt->sport() || port == udp_pkt->dport() || port == -1) {
            // hw addrs, interface, protocol, ip addrs, port
            if (permit) return 1;
            else return 0;
        }
    }
    return -1; // if other transport layer protocol is used => deny
}

PDU::PDUType Filters::parsePDUType(string type) {
    if (type.compare("TCP") == 0) return PDU::TCP;
    if (type.compare("UDP") == 0) return PDU::UDP;
    if (type.compare("ARP") == 0) return PDU::ARP;
    if (type.compare("ICMP") == 0) return PDU::ICMP;
    if (type.compare("IP") == 0) return PDU::IP;
    return PDU::UNKNOWN;
}

void Filters::printFilters() {
    string permit, port_out;
    for (auto &entry : filters) {
        stringstream strEntry;
        if (entry.permit) permit = "permit";
        else permit = "deny";
        if (entry.port == -1) port_out = "any";
        else port_out = to_string(entry.port);
        strEntry << entry.key << " | "
                 << permit << " | "
                 << entry.ip_src << " -> "
                 << entry.ip_dst << " | "
                 << entry.hw_src << " -> "
                 << entry.hw_dst << " | protocol: "
                 << entry.protocol << " | "
                 << entry.interface << " | dir: "
                 << entry.direction << " | port: "
                 << port_out << endl;
        cout << strEntry.str();
    }
}

QVector<string> Filters::filtersToStr() {
    QVector<string> strFilters;
    string permit, port_out, ip_src, ip_dst, hw_src, hw_dst;
    for (auto &entry : filters) {
        stringstream strEntry;
        if (entry.permit) permit = "permit";
        else permit = "deny";
        if (entry.port == -1) port_out = "any";
        else port_out = to_string(entry.port);
        if (entry.ip_src.compare("") == 0) ip_src = "any_src_IP";
        else ip_src = entry.ip_src;
        if (entry.ip_dst.compare("") == 0) ip_dst = "any_dst_IP";
        else ip_dst = entry.ip_dst;
        if (entry.hw_src.compare("") == 0) hw_src = "any_src_HW";
        else hw_src = entry.hw_src;
        if (entry.hw_dst.compare("") == 0) hw_dst = "any_dst_HW";
        else hw_dst = entry.hw_dst;
        strEntry << entry.key << " | "
                 << permit << " | "
                 << ip_src << " -> "
                 << ip_dst << " | "
                 << hw_src << " -> "
                 << hw_dst << " | protocol: "
                 << entry.protocol << " | "
                 << entry.interface << " | dir: "
                 << entry.direction << " | port: "
                 << port_out;
        strFilters.push_back(strEntry.str());
    }
    return strFilters;
}