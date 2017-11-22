//
// Created by root on 11.11.2017.
//

#include "Switch_gui.h"
#include "ui_switch_GUI.h"

#include <iostream>
#include <sstream>
#include <QtGui/QDialog>
#include <QtGui/QMessageBox>

using namespace std;

Switch_gui::Switch_gui(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    macTable = new MAC_table(this);
    filters = new Filters(this);
    sniffer1 = new Port_sniffer(macTable, filters);
    sniffer2 = new Port_sniffer(macTable, filters);
    ui->modifyTimerText->setText(QString::fromStdString(to_string(macTable->getTimer())));

    initComponents();

    qRegisterMetaType<QVector<string> >("QVector<string>");
    qRegisterMetaType<PDU::PDUType >("PDU::PDUType");
    qRegisterMetaType<QVector<PDU::PDUType> >("QVector<PDU::PDUType>");
    //qRegisterMetaType<vector<string> >("vector<string>");
    // main buttons
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(handleButton_start()));
    connect(ui->modifyTimerButton, SIGNAL(clicked()), this, SLOT(handleButton_modifyTimer()));
    connect(ui->cleartableButton, SIGNAL(clicked()), this, SLOT(handleButton_clearTable()));
    connect(ui->cleartableButton, SIGNAL(clicked()), macTable, SLOT(clear_table()));
    connect(ui->resetStats1_button, SIGNAL(clicked()), this, SLOT(resetStats1()));
    connect(ui->resetStats2_button, SIGNAL(clicked()), this, SLOT(resetStats2()));
    // mac table signals
    connect(macTable, SIGNAL(tableChanged(QVector<string>)), this, SLOT(updateTableView(QVector<string>)));

    // sniffer signals
    // if port 1 receives frame => its sent by same sniffer but through port 2
    connect(sniffer1, SIGNAL(frameReceived(QVector<PDU::PDUType>)), this, SLOT(handleS1recv(QVector<PDU::PDUType>)));
    connect(sniffer1, SIGNAL(frameSent(QVector<PDU::PDUType>)), this, SLOT(handleS2sent(QVector<PDU::PDUType>)));
    connect(sniffer2, SIGNAL(frameReceived(QVector<PDU::PDUType>)), this, SLOT(handleS2recv(QVector<PDU::PDUType>)));
    connect(sniffer2, SIGNAL(frameSent(QVector<PDU::PDUType>)), this, SLOT(handleS1sent(QVector<PDU::PDUType>)));

    // filters' buttons
    connect(ui->addFilterButton, SIGNAL(clicked()), this, SLOT(handleButton_addFilter()));
    connect(ui->clearFiltersButton, SIGNAL(clicked()), this, SLOT(handleButton_clearFilters()));
    connect(ui->deleteFilterButton, SIGNAL(clicked()), this, SLOT(handleButton_deleteFilter()));
    connect(ui->filterTable, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(setPreyItem(QListWidgetItem*)));
    connect(filters, SIGNAL(filtersChanged(QVector<string>)), this, SLOT(updateFiltersTable(QVector<string>)));
}

Ui::MainWindow* Switch_gui::getUi() {
    return this->ui;
}

Switch_gui::~Switch_gui() {
    delete ui;
}

void Switch_gui::initComponents() {
    QStringList interfaces;
    vector<string> list = sniffer1->getAllInterfaceNames();
    for (auto &item : list) {
        interfaces << QString::fromStdString(item);
    }
    loadInterfacesCombobox(interfaces);
    ui->deleteFilterButton->setDisabled(true);
}

string Switch_gui::parse_pdu_type(QString type) {
    return type.toStdString();
}

/********************************************
************ MAC table handlers *************
********************************************/
void Switch_gui::updateStats(PDU::PDUType type, char port, bool dirIn) {
    lock_guard<mutex> lock(stats_mutex);
    if (type == PDU::ETHERNET_II) {
//        return "Ethernet_II";
        if (port == 1) {
            if (dirIn) ui->eth2CountIN->display(ui->eth2CountIN->intValue() + 1);
            else ui->eth2CountOUT->display(ui->eth2CountOUT->intValue() + 1);
        } else if (port == 2) {
            if (dirIn) ui->eth2CountIN_2->display(ui->eth2CountIN_2->intValue() + 1);
            else ui->eth2CountOUT_2->display(ui->eth2CountOUT_2->intValue() + 1);
        }
    } else if (type == PDU::TCP) {
//        return "TCP";
        if (port == 1) {
            if (dirIn) ui->tcpCountIN->display(ui->tcpCountIN->intValue() + 1);
            else ui->tcpCountOUT->display(ui->tcpCountOUT->intValue() + 1);
        } else if (port == 2) {
            if (dirIn) ui->tcpCountIN_2->display(ui->tcpCountIN_2->intValue() + 1);
            else ui->tcpCountOUT_2->display(ui->tcpCountOUT_2->intValue() + 1);
        }
    } else if (type == PDU::IP) {
//        return "IPv4";
        if (port == 1) {
            if (dirIn) ui->ipCountIN->display(ui->ipCountIN->intValue() + 1);
            else ui->ipCountOUT->display(ui->ipCountOUT->intValue() + 1);
        } else if (port == 2) {
            if (dirIn) ui->ipCountIN_2->display(ui->ipCountIN_2->intValue() + 1);
            else ui->ipCountOUT_2->display(ui->ipCountOUT_2->intValue() + 1);
        }
    } else if (type == PDU::ARP) {
//        return "ARP";
        if (port == 1) {
            if (dirIn) ui->arpCountIN->display(ui->arpCountIN->intValue() + 1);
            else ui->arpCountOUT->display(ui->arpCountOUT->intValue() + 1);
        } else if (port == 2) {
            if (dirIn) ui->arpCountIN_2->display(ui->arpCountIN_2->intValue() + 1);
            else ui->arpCountOUT_2->display(ui->arpCountOUT_2->intValue() + 1);
        }
    } else if (type == PDU::ICMP) {
//        return "ICMP";
        if (port == 1) {
            if (dirIn) ui->icmpCountIN->display(ui->icmpCountIN->intValue() + 1);
            else ui->icmpCountOUT->display(ui->icmpCountOUT->intValue() + 1);
        } else if (port == 2) {
            if (dirIn) ui->icmpCountIN_2->display(ui->icmpCountIN_2->intValue() + 1);
            else ui->icmpCountOUT_2->display(ui->icmpCountOUT_2->intValue() + 1);
        }
    } else if (type == PDU::UDP) {
//        return "UDP";
        if (port == 1) {
            if (dirIn) ui->udpCountIN->display(ui->udpCountIN->intValue() + 1);
            else ui->udpCountOUT->display(ui->udpCountOUT->intValue() + 1);
        } else if (port == 2) {
            if (dirIn) ui->udpCountIN_2->display(ui->udpCountIN_2->intValue() + 1);
            else ui->udpCountOUT_2->display(ui->udpCountOUT_2->intValue() + 1);
        }
    } else if (type == PDU::USER_DEFINED_PDU) {
        // return "HTTP"
        if (port == 1) {
            if (dirIn) ui->httpCountIN->display(ui->httpCountIN->intValue() + 1);
            else ui->httpCountOUT->display(ui->httpCountOUT->intValue() + 1);
        } else if (port == 2) {
            if (dirIn) ui->httpCountIN_2->display(ui->httpCountIN_2->intValue() + 1);
            else ui->httpCountOUT_2->display(ui->httpCountOUT_2->intValue() + 1);
        }
    }
//    return "UNKNOWN"; // if other unknown protocol is found
}

/********************************************
*********** Statistics handlers *************
********************************************/

void Switch_gui::updateTableView(QVector<string> table) {
    ui->macTableList->clear();
    for (auto &item : table) {
        replace(item.begin(), item.end(), ';', '\t');
        ui->macTableList->addItem(QString::fromStdString(item));
    }
}

void Switch_gui::handleS1recv(QVector<PDU::PDUType> qvec) {
    for (auto &type : qvec) updateStats(type, 1, true);
}

void Switch_gui::handleS1sent(QVector<PDU::PDUType> qvec) {
    for (auto &type : qvec) updateStats(type, 1, false);
}

void Switch_gui::handleS2recv(QVector<PDU::PDUType> qvec) {
    for (auto &type : qvec) updateStats(type, 2, true);
}

void Switch_gui::handleS2sent(QVector<PDU::PDUType> qvec) {
    for (auto &type : qvec) updateStats(type, 2, false);
}

void Switch_gui::resetStats1() {
    ui->eth2CountIN->display(0);
    ui->eth2CountOUT->display(0);
    ui->ipCountIN->display(0);
    ui->ipCountOUT->display(0);
    ui->tcpCountIN->display(0);
    ui->tcpCountOUT->display(0);
    ui->udpCountIN->display(0);
    ui->udpCountOUT->display(0);
    ui->arpCountIN->display(0);
    ui->arpCountOUT->display(0);
    ui->icmpCountIN->display(0);
    ui->icmpCountOUT->display(0);
    ui->httpCountIN->display(0);
    ui->httpCountOUT->display(0);
}

void Switch_gui::resetStats2() {
    ui->eth2CountIN_2->display(0);
    ui->eth2CountOUT_2->display(0);
    ui->ipCountIN_2->display(0);
    ui->ipCountOUT_2->display(0);
    ui->tcpCountIN_2->display(0);
    ui->tcpCountOUT_2->display(0);
    ui->udpCountIN_2->display(0);
    ui->udpCountOUT_2->display(0);
    ui->arpCountIN_2->display(0);
    ui->arpCountOUT_2->display(0);
    ui->icmpCountIN_2->display(0);
    ui->icmpCountOUT_2->display(0);
    ui->httpCountIN_2->display(0);
    ui->httpCountOUT_2->display(0);
}

void Switch_gui::loadInterfacesCombobox(QStringList interfaces) {
    cout << "loading interface names...\n";
    ui->port1ComboBox->addItems(interfaces);
    ui->port2ComboBox->addItems(interfaces);
}

/********************************************
*********** gui BUTTON handlers *************
********************************************/
void Switch_gui::handleButton_start() {
    string int1 = ui->port1ComboBox->currentText().toStdString();
    string int2 = ui->port2ComboBox->currentText().toStdString();
    sniffer1->setInterface(int1, int2);
    sniffer2->setInterface(int2, int1);
    sniffer1->start();
    sniffer2->start();
    macTable->start();

    stringstream msg;
    msg << "start switching on " << int1 << " <---> " << int2 << endl;
    cout << msg.str();
    ui->startButton->setDisabled(true);

    ui->stats1Group->setTitle(ui->port1ComboBox->currentText() + " stats");
    ui->stats2Group->setTitle(ui->port2ComboBox->currentText() + " stats");
}

void Switch_gui::handleButton_modifyTimer() {
    string timer = ui->modifyTimerText->text().toStdString();
    int u_timer = atoi(timer.c_str());
    macTable->setTimer((unsigned int) u_timer);

    stringstream msg;
    msg << "modify timer to " << u_timer << endl;
    cout << msg.str();
}

void Switch_gui::handleButton_clearTable() {
    ui->macTableList->clear();
    cout << "clear table\n";
}



/********************************************
************* FILTER handlers ***************
********************************************/
void Switch_gui::handleButton_addFilter() {
    bool permit = false;
    string ipSrc, ipDst, hwSrc, hwDst, direction, protocol, port_out, interface;
    int port = -1;

    if (ui->filterpermitComboBox->currentText().compare("permit") == 0) permit = true;
    if (!ui->filter_ipsrcText->text().isEmpty()) ipSrc = ui->filter_ipsrcText->text().toStdString();
    if (!ui->filter_ipdstText->text().isEmpty()) ipDst = ui->filter_ipdstText->text().toStdString();
    if (!ui->filter_hwsrcText->text().isEmpty()) hwSrc = ui->filter_hwsrcText->text().toStdString();
    if (!ui->filter_hwdstText->text().isEmpty()) hwDst = ui->filter_hwdstText->text().toStdString();
    protocol = parse_pdu_type(ui->filterprotocolComboBox->currentText());

    if (ui->filter_interfaceComboBox->currentText().compare("1") == 0) interface = sniffer1->get_port();
    else interface = sniffer2->get_port();

    if (ui->filterdirectionComboBox->currentText().compare("in") == 0) direction = "in";
    else if (ui->filterdirectionComboBox->currentText().compare("out") == 0) direction = "out";
    else direction = "any";

    if (!ui->filter_portText->text().isEmpty()) {
        port_out = ui->filter_portText->text().toStdString();
        try {
            port = stoi(port_out);
        } catch (std::invalid_argument) {
            QMessageBox dialog;
            dialog.information(ui, "Must by number", "port must be number");
            dialog.setFixedSize(150, 70);
            return;
        }
    }
    if (port == -1)  port_out = "any";
    if (filters->addFilter(permit, ipSrc, ipDst, hwSrc, hwDst, protocol, interface, direction, port) == -1) cout << "filter add failed";

    //cout << "add filter\n";
}

void Switch_gui::handleButton_clearFilters() {
    ui->filterTable->clear();
    filters->clearFilters();
    //cout << "clear filters\n";
}

void Switch_gui::handleButton_deleteFilter() {
    string delimiter = " ";
    if (!preyItem) return;
    string filter = preyItem->text().toStdString();
    string s = filter.substr(0, filter.find(delimiter));
    int key = stoi(s);
    filters->removeFilter(key);
    ui->deleteFilterButton->setDisabled(true);

    //cout << "delete filter\n";
}

void Switch_gui::updateFiltersTable(QVector<string> list) {
    ui->filterTable->clear();
    for (auto &entry : list) {
        ui->filterTable->addItem(QString::fromStdString(entry));
    }
}

void Switch_gui::setPreyItem(QListWidgetItem *preyItem) {
    this->preyItem = preyItem;
    ui->deleteFilterButton->setDisabled(false);
}