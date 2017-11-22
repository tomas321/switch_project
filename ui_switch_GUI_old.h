/********************************************************************************
** Form generated from reading UI file 'switch_GUIN22745.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SWITCH_GUIN22745_H
#define SWITCH_GUIN22745_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *cleartableButton;
    QLabel *label;
    QLineEdit *modifyTimerText;
    QPushButton *modifyTimerButton;
    QListWidget *macTableList;
    QGroupBox *groupBox_2;
    QComboBox *port1ComboBox;
    QComboBox *port2ComboBox;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *startButton;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLabel *label_5;
    QLCDNumber *ipCountIN;
    QLCDNumber *eth2CountOUT;
    QLCDNumber *ipCountOUT;
    QLCDNumber *arpCountOUT;
    QLCDNumber *arpCountIN;
    QLCDNumber *tcpCountIN;
    QLCDNumber *eth2CountIN;
    QLCDNumber *udpCountOUT;
    QLCDNumber *udpCountIN;
    QLCDNumber *tcpCountOUT;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_14;
    QLabel *label_15;
    QLCDNumber *icmpCountIN;
    QLCDNumber *icmpCountOUT;
    QLabel *label_16;
    QLCDNumber *httpCountIN;
    QLCDNumber *httpCountOUT;
    QLabel *label_17;
    QLabel *port1Label;
    QGroupBox *groupBox_4;
    QLabel *label_18;
    QLabel *label_19;
    QLCDNumber *ipCountIN_2;
    QLCDNumber *eth2CountOUT_2;
    QLCDNumber *ipCountOUT_2;
    QLCDNumber *arpCountOUT_2;
    QLCDNumber *arpCountIN_2;
    QLCDNumber *tcpCountIN_2;
    QLCDNumber *eth2CountIN_2;
    QLCDNumber *udpCountOUT_2;
    QLCDNumber *udpCountIN_2;
    QLCDNumber *tcpCountOUT_2;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLCDNumber *icmpCountIN_2;
    QLCDNumber *icmpCountOUT_2;
    QLabel *label_25;
    QLCDNumber *httpCountIN_2;
    QLCDNumber *httpCountOUT_2;
    QLabel *label_26;
    QLabel *port2Label;
    QGroupBox *groupBox_5;
    QComboBox *filterpermitComboBox;
    QComboBox *filter_interfaceComboBox;
    QComboBox *filterdirectionComboBox;
    QComboBox *filterprotocolComboBox;
    QLabel *label_27;
    QLabel *label_28;
    QLineEdit *filter_hwsrcText;
    QLineEdit *filter_ipsrcText;
    QLineEdit *filter_ipdstText;
    QLineEdit *filter_hwdstText;
    QPushButton *addFilterButton;
    QPushButton *deleteFilterButton;
    QPushButton *clearFiltersButton;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *filter_portText;
    QLabel *label_9;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1005, 866);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 300, 401, 501));
        cleartableButton = new QPushButton(groupBox);
        cleartableButton->setObjectName(QString::fromUtf8("cleartableButton"));
        cleartableButton->setGeometry(QRect(280, 460, 99, 27));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 81, 31));
        modifyTimerText = new QLineEdit(groupBox);
        modifyTimerText->setObjectName(QString::fromUtf8("modifyTimerText"));
        modifyTimerText->setGeometry(QRect(100, 50, 51, 27));
        modifyTimerButton = new QPushButton(groupBox);
        modifyTimerButton->setObjectName(QString::fromUtf8("modifyTimerButton"));
        modifyTimerButton->setGeometry(QRect(160, 50, 91, 27));
        macTableList = new QListWidget(groupBox);
        macTableList->setObjectName(QString::fromUtf8("macTableList"));
        macTableList->setGeometry(QRect(10, 90, 371, 361));
        macTableList->setModelColumn(0);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 20, 401, 201));
        port1ComboBox = new QComboBox(groupBox_2);
        port1ComboBox->setObjectName(QString::fromUtf8("port1ComboBox"));
        port1ComboBox->setGeometry(QRect(150, 40, 231, 27));
        port2ComboBox = new QComboBox(groupBox_2);
        port2ComboBox->setObjectName(QString::fromUtf8("port2ComboBox"));
        port2ComboBox->setGeometry(QRect(150, 80, 231, 27));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 40, 111, 31));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 80, 111, 31));
        startButton = new QPushButton(groupBox_2);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(248, 150, 131, 41));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(450, 20, 251, 421));
        groupBox_3->setAutoFillBackground(false);
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        groupBox_3->setChecked(false);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 60, 21, 17));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 60, 31, 17));
        ipCountIN = new QLCDNumber(groupBox_3);
        ipCountIN->setObjectName(QString::fromUtf8("ipCountIN"));
        ipCountIN->setGeometry(QRect(100, 140, 41, 23));
        ipCountIN->setSegmentStyle(QLCDNumber::Flat);
        eth2CountOUT = new QLCDNumber(groupBox_3);
        eth2CountOUT->setObjectName(QString::fromUtf8("eth2CountOUT"));
        eth2CountOUT->setGeometry(QRect(170, 90, 41, 23));
        eth2CountOUT->setSegmentStyle(QLCDNumber::Flat);
        ipCountOUT = new QLCDNumber(groupBox_3);
        ipCountOUT->setObjectName(QString::fromUtf8("ipCountOUT"));
        ipCountOUT->setGeometry(QRect(170, 140, 41, 23));
        ipCountOUT->setSegmentStyle(QLCDNumber::Flat);
        arpCountOUT = new QLCDNumber(groupBox_3);
        arpCountOUT->setObjectName(QString::fromUtf8("arpCountOUT"));
        arpCountOUT->setGeometry(QRect(170, 190, 41, 23));
        arpCountOUT->setSegmentStyle(QLCDNumber::Flat);
        arpCountIN = new QLCDNumber(groupBox_3);
        arpCountIN->setObjectName(QString::fromUtf8("arpCountIN"));
        arpCountIN->setGeometry(QRect(100, 190, 41, 23));
        arpCountIN->setSegmentStyle(QLCDNumber::Flat);
        tcpCountIN = new QLCDNumber(groupBox_3);
        tcpCountIN->setObjectName(QString::fromUtf8("tcpCountIN"));
        tcpCountIN->setGeometry(QRect(100, 240, 41, 23));
        tcpCountIN->setSegmentStyle(QLCDNumber::Flat);
        eth2CountIN = new QLCDNumber(groupBox_3);
        eth2CountIN->setObjectName(QString::fromUtf8("eth2CountIN"));
        eth2CountIN->setGeometry(QRect(100, 90, 41, 23));
        eth2CountIN->setSegmentStyle(QLCDNumber::Flat);
        udpCountOUT = new QLCDNumber(groupBox_3);
        udpCountOUT->setObjectName(QString::fromUtf8("udpCountOUT"));
        udpCountOUT->setGeometry(QRect(170, 290, 41, 23));
        udpCountOUT->setSegmentStyle(QLCDNumber::Flat);
        udpCountIN = new QLCDNumber(groupBox_3);
        udpCountIN->setObjectName(QString::fromUtf8("udpCountIN"));
        udpCountIN->setGeometry(QRect(100, 290, 41, 23));
        udpCountIN->setSegmentStyle(QLCDNumber::Flat);
        tcpCountOUT = new QLCDNumber(groupBox_3);
        tcpCountOUT->setObjectName(QString::fromUtf8("tcpCountOUT"));
        tcpCountOUT->setGeometry(QRect(170, 240, 41, 23));
        tcpCountOUT->setSegmentStyle(QLCDNumber::Flat);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 90, 71, 17));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 140, 68, 17));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 190, 68, 17));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 240, 68, 17));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 290, 68, 17));
        icmpCountIN = new QLCDNumber(groupBox_3);
        icmpCountIN->setObjectName(QString::fromUtf8("icmpCountIN"));
        icmpCountIN->setGeometry(QRect(100, 340, 41, 23));
        icmpCountIN->setSegmentStyle(QLCDNumber::Flat);
        icmpCountOUT = new QLCDNumber(groupBox_3);
        icmpCountOUT->setObjectName(QString::fromUtf8("icmpCountOUT"));
        icmpCountOUT->setGeometry(QRect(170, 340, 41, 23));
        icmpCountOUT->setSegmentStyle(QLCDNumber::Flat);
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 340, 68, 17));
        httpCountIN = new QLCDNumber(groupBox_3);
        httpCountIN->setObjectName(QString::fromUtf8("httpCountIN"));
        httpCountIN->setGeometry(QRect(100, 390, 41, 23));
        httpCountIN->setSegmentStyle(QLCDNumber::Flat);
        httpCountOUT = new QLCDNumber(groupBox_3);
        httpCountOUT->setObjectName(QString::fromUtf8("httpCountOUT"));
        httpCountOUT->setGeometry(QRect(170, 390, 41, 23));
        httpCountOUT->setSegmentStyle(QLCDNumber::Flat);
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 390, 68, 17));
        port1Label = new QLabel(groupBox_3);
        port1Label->setObjectName(QString::fromUtf8("port1Label"));
        port1Label->setGeometry(QRect(60, 30, 151, 20));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(740, 20, 251, 421));
        groupBox_4->setAutoFillBackground(false);
        groupBox_4->setStyleSheet(QString::fromUtf8(""));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        groupBox_4->setChecked(false);
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(110, 60, 21, 17));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(180, 60, 31, 17));
        ipCountIN_2 = new QLCDNumber(groupBox_4);
        ipCountIN_2->setObjectName(QString::fromUtf8("ipCountIN_2"));
        ipCountIN_2->setGeometry(QRect(100, 140, 41, 23));
        ipCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        eth2CountOUT_2 = new QLCDNumber(groupBox_4);
        eth2CountOUT_2->setObjectName(QString::fromUtf8("eth2CountOUT_2"));
        eth2CountOUT_2->setGeometry(QRect(170, 90, 41, 23));
        eth2CountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        ipCountOUT_2 = new QLCDNumber(groupBox_4);
        ipCountOUT_2->setObjectName(QString::fromUtf8("ipCountOUT_2"));
        ipCountOUT_2->setGeometry(QRect(170, 140, 41, 23));
        ipCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        arpCountOUT_2 = new QLCDNumber(groupBox_4);
        arpCountOUT_2->setObjectName(QString::fromUtf8("arpCountOUT_2"));
        arpCountOUT_2->setGeometry(QRect(170, 190, 41, 23));
        arpCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        arpCountIN_2 = new QLCDNumber(groupBox_4);
        arpCountIN_2->setObjectName(QString::fromUtf8("arpCountIN_2"));
        arpCountIN_2->setGeometry(QRect(100, 190, 41, 23));
        arpCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        tcpCountIN_2 = new QLCDNumber(groupBox_4);
        tcpCountIN_2->setObjectName(QString::fromUtf8("tcpCountIN_2"));
        tcpCountIN_2->setGeometry(QRect(100, 240, 41, 23));
        tcpCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        eth2CountIN_2 = new QLCDNumber(groupBox_4);
        eth2CountIN_2->setObjectName(QString::fromUtf8("eth2CountIN_2"));
        eth2CountIN_2->setGeometry(QRect(100, 90, 41, 23));
        eth2CountIN_2->setSegmentStyle(QLCDNumber::Flat);
        udpCountOUT_2 = new QLCDNumber(groupBox_4);
        udpCountOUT_2->setObjectName(QString::fromUtf8("udpCountOUT_2"));
        udpCountOUT_2->setGeometry(QRect(170, 290, 41, 23));
        udpCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        udpCountIN_2 = new QLCDNumber(groupBox_4);
        udpCountIN_2->setObjectName(QString::fromUtf8("udpCountIN_2"));
        udpCountIN_2->setGeometry(QRect(100, 290, 41, 23));
        udpCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        tcpCountOUT_2 = new QLCDNumber(groupBox_4);
        tcpCountOUT_2->setObjectName(QString::fromUtf8("tcpCountOUT_2"));
        tcpCountOUT_2->setGeometry(QRect(170, 240, 41, 23));
        tcpCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 90, 71, 17));
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 140, 68, 17));
        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 190, 68, 17));
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 240, 68, 17));
        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 290, 68, 17));
        icmpCountIN_2 = new QLCDNumber(groupBox_4);
        icmpCountIN_2->setObjectName(QString::fromUtf8("icmpCountIN_2"));
        icmpCountIN_2->setGeometry(QRect(100, 340, 41, 23));
        icmpCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        icmpCountOUT_2 = new QLCDNumber(groupBox_4);
        icmpCountOUT_2->setObjectName(QString::fromUtf8("icmpCountOUT_2"));
        icmpCountOUT_2->setGeometry(QRect(170, 340, 41, 23));
        icmpCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 340, 68, 17));
        httpCountIN_2 = new QLCDNumber(groupBox_4);
        httpCountIN_2->setObjectName(QString::fromUtf8("httpCountIN_2"));
        httpCountIN_2->setGeometry(QRect(100, 390, 41, 23));
        httpCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        httpCountOUT_2 = new QLCDNumber(groupBox_4);
        httpCountOUT_2->setObjectName(QString::fromUtf8("httpCountOUT_2"));
        httpCountOUT_2->setGeometry(QRect(170, 390, 41, 23));
        httpCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        label_26 = new QLabel(groupBox_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 390, 68, 17));
        port2Label = new QLabel(groupBox_4);
        port2Label->setObjectName(QString::fromUtf8("port2Label"));
        port2Label->setGeometry(QRect(60, 30, 151, 20));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(430, 460, 541, 341));
        filterpermitComboBox = new QComboBox(groupBox_5);
        filterpermitComboBox->setObjectName(QString::fromUtf8("filterpermitComboBox"));
        filterpermitComboBox->setGeometry(QRect(20, 30, 71, 27));
        filter_interfaceComboBox = new QComboBox(groupBox_5);
        filter_interfaceComboBox->setObjectName(QString::fromUtf8("filter_interfaceComboBox"));
        filter_interfaceComboBox->setGeometry(QRect(160, 30, 51, 27));
        filterdirectionComboBox = new QComboBox(groupBox_5);
        filterdirectionComboBox->setObjectName(QString::fromUtf8("filterdirectionComboBox"));
        filterdirectionComboBox->setGeometry(QRect(280, 30, 51, 27));
        filterprotocolComboBox = new QComboBox(groupBox_5);
        filterprotocolComboBox->setObjectName(QString::fromUtf8("filterprotocolComboBox"));
        filterprotocolComboBox->setGeometry(QRect(340, 30, 71, 27));
        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 70, 81, 17));
        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 100, 71, 17));
        filter_hwsrcText = new QLineEdit(groupBox_5);
        filter_hwsrcText->setObjectName(QString::fromUtf8("filter_hwsrcText"));
        filter_hwsrcText->setGeometry(QRect(120, 60, 141, 27));
        filter_ipsrcText = new QLineEdit(groupBox_5);
        filter_ipsrcText->setObjectName(QString::fromUtf8("filter_ipsrcText"));
        filter_ipsrcText->setGeometry(QRect(120, 90, 141, 27));
        filter_ipdstText = new QLineEdit(groupBox_5);
        filter_ipdstText->setObjectName(QString::fromUtf8("filter_ipdstText"));
        filter_ipdstText->setGeometry(QRect(300, 90, 141, 27));
        filter_hwdstText = new QLineEdit(groupBox_5);
        filter_hwdstText->setObjectName(QString::fromUtf8("filter_hwdstText"));
        filter_hwdstText->setGeometry(QRect(300, 60, 141, 27));
        addFilterButton = new QPushButton(groupBox_5);
        addFilterButton->setObjectName(QString::fromUtf8("addFilterButton"));
        addFilterButton->setGeometry(QRect(450, 86, 71, 31));
        deleteFilterButton = new QPushButton(groupBox_5);
        deleteFilterButton->setObjectName(QString::fromUtf8("deleteFilterButton"));
        deleteFilterButton->setGeometry(QRect(310, 300, 99, 27));
        clearFiltersButton = new QPushButton(groupBox_5);
        clearFiltersButton->setObjectName(QString::fromUtf8("clearFiltersButton"));
        clearFiltersButton->setGeometry(QRect(430, 300, 99, 27));
        label_29 = new QLabel(groupBox_5);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(100, 30, 61, 31));
        label_30 = new QLabel(groupBox_5);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(220, 30, 61, 31));
        filter_portText = new QLineEdit(groupBox_5);
        filter_portText->setObjectName(QString::fromUtf8("filter_portText"));
        filter_portText->setGeometry(QRect(450, 30, 71, 27));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(420, 30, 31, 31));
        tableWidget = new QTableWidget(groupBox_5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 120, 521, 171));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1005, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "MAC table", 0, QApplication::UnicodeUTF8));
        cleartableButton->setText(QApplication::translate("MainWindow", "clear", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "entry timer", 0, QApplication::UnicodeUTF8));
        modifyTimerButton->setText(QApplication::translate("MainWindow", "modify", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Interfaces", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "switch port 1:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "switch port 2:", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("MainWindow", "Start switching", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Port 1 Stats", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "IN", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "OUT", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Ethernet II", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "ARP", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "TCP", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "UDP", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "ICMP", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "HTTP", 0, QApplication::UnicodeUTF8));
        port1Label->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Port 2 Stats", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "IN", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "OUT", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Ethernet II", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "ARP", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "TCP", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "UDP", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "ICMP", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "HTTP", 0, QApplication::UnicodeUTF8));
        port2Label->setText(QString());
#ifndef QT_NO_WHATSTHIS
        groupBox_5->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Filters", 0, QApplication::UnicodeUTF8));
        filterpermitComboBox->clear();
        filterpermitComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "permit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "deny", 0, QApplication::UnicodeUTF8)
        );
        filter_interfaceComboBox->clear();
        filter_interfaceComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
        );
        filterdirectionComboBox->clear();
        filterdirectionComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "in", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "out", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "any", 0, QApplication::UnicodeUTF8)
        );
        filterprotocolComboBox->clear();
        filterprotocolComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "HTTP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ICMP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "UDP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "TCP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ARP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "any", 0, QApplication::UnicodeUTF8)
        );
        label_27->setText(QApplication::translate("MainWindow", "HW address", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "IP address", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        filter_hwsrcText->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        filter_hwsrcText->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        filter_hwsrcText->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        filter_hwsrcText->setInputMask(QString());
        filter_hwsrcText->setText(QString());
        filter_hwsrcText->setPlaceholderText(QApplication::translate("MainWindow", "source", 0, QApplication::UnicodeUTF8));
        filter_ipsrcText->setPlaceholderText(QApplication::translate("MainWindow", "source", 0, QApplication::UnicodeUTF8));
        filter_ipdstText->setPlaceholderText(QApplication::translate("MainWindow", "destination", 0, QApplication::UnicodeUTF8));
        filter_hwdstText->setPlaceholderText(QApplication::translate("MainWindow", "destination", 0, QApplication::UnicodeUTF8));
        addFilterButton->setText(QApplication::translate("MainWindow", "ADD", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deleteFilterButton->setToolTip(QApplication::translate("MainWindow", "delete selected", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleteFilterButton->setText(QApplication::translate("MainWindow", "delete", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        clearFiltersButton->setToolTip(QApplication::translate("MainWindow", "clear filters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        clearFiltersButton->setText(QApplication::translate("MainWindow", "clear", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "interface", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "direction", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "port", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SWITCH_GUIN22745_H
