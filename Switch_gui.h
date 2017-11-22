//
// Created by root on 13.11.2017.
//

#ifndef SWITCH_PROJECT_SWITCH_GUI_H_H
#define SWITCH_PROJECT_SWITCH_GUI_H_H

#include <QtGui/QMainWindow>
#include <QtGui/QListWidgetItem>
#include <QtGui/QTableWidgetItem>
#include "MAC_table.h"
#include "Filters.h"
#include "Port_sniffer.h"

namespace Ui {
    class MainWindow;
}

class Switch_gui : public QMainWindow {
Q_OBJECT
private:
    Ui::MainWindow *ui;
    MAC_table *macTable;
    Port_sniffer *sniffer1;
    Port_sniffer *sniffer2;
    Filters *filters;
    QListWidgetItem *preyItem;
    mutex stats_mutex;
signals:

public slots:
    void handleButton_start();
    void handleButton_modifyTimer();
    void handleButton_clearTable();
    void handleButton_addFilter();
    void handleButton_clearFilters();
    void handleButton_deleteFilter();
    void loadInterfacesCombobox(QStringList interfaces);
    void updateTableView(QVector<string>);
    void updateStats(PDU::PDUType, char, bool);
    void resetStats1();
    void resetStats2();

    void handleS1recv(QVector<PDU::PDUType>);
    void handleS1sent(QVector<PDU::PDUType>);
    void handleS2recv(QVector<PDU::PDUType>);
    void handleS2sent(QVector<PDU::PDUType>);

    void updateFiltersTable(QVector<string>);
    void setPreyItem(QListWidgetItem *preyItem);
public:
    ~Switch_gui();
    explicit Switch_gui(QWidget *parent = 0);
    Ui::MainWindow *getUi();
    void initComponents();
    string parse_pdu_type(QString type);

};

#endif //SWITCH_PROJECT_SWITCH_GUI_H_H
