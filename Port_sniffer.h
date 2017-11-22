//
// Created by root on 17.10.2017.
//

#ifndef SWITCH_PROJECT_PORT_SNIFFER_H
#define SWITCH_PROJECT_PORT_SNIFFER_H

#include <tins/tins.h>
#include <atomic>
#include <QtCore/QThread>
#include "MAC_table.h"
#include "Filters.h"

using namespace Tins;

class Port_sniffer : public QThread {
    Q_OBJECT
private:
    string interface;
    string other_interface;
    SnifferConfiguration config;
    MAC_table *macTable;
    Filters *filters;
    // string dst_interface;
    struct Interface {
        HWAddress<6> hw_addr;
        IPv4Address ip_addr;
        IPv4Address net_mask;
        IPv4Address broadcast;
        string ipv6_addr;
        NetworkInterface::id_type id_type;
        bool status;
    } Interface;

signals:
    void frameSent(QVector<PDU::PDUType>);
    void frameReceived(QVector<PDU::PDUType>);

public slots:
    void setInterface(string interface, string other_int);

public:
    explicit Port_sniffer(MAC_table *table, Filters *filters);
    explicit Port_sniffer(string interface, MAC_table *table, Filters *filters);
    void process_frame(PDU *pdu);
    string get_port();
    void set_port(string interface);
    void set_other_port(string interface);
    string parse_pdu_type(PDU::PDUType type);
    void sniffer_start();
    bool set_interface_info();
    bool send_frame(string dst_interface, EthernetII *frame);
    void set_config_filter(string filter);
    vector<string> getAllInterfaceNames();
    QVector<PDU::PDUType> get_PDUTypes(PDU*);
    void run() override;
};


#endif //SWITCH_PROJECT_PORT_SNIFFER_H
