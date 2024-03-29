/********************************************************************************
** Form generated from reading UI file 'switch_GUIS20382.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SWITCH_GUIS20382_H
#define SWITCH_GUIS20382_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow : public QMainWindow
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
    QGroupBox *stats1Group;
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
    QPushButton *resetStats1_button;
    QGroupBox *stats2Group;
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
    QPushButton *resetStats2_button;
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
    QListWidget *filterTable;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1450, 866);
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
        stats1Group = new QGroupBox(centralwidget);
        stats1Group->setObjectName(QString::fromUtf8("stats1Group"));
        stats1Group->setGeometry(QRect(560, 30, 251, 421));
        stats1Group->setAutoFillBackground(false);
        stats1Group->setStyleSheet(QString::fromUtf8(""));
        stats1Group->setFlat(false);
        stats1Group->setCheckable(false);
        stats1Group->setChecked(false);
        label_4 = new QLabel(stats1Group);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 60, 21, 17));
        label_5 = new QLabel(stats1Group);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 60, 31, 17));
        ipCountIN = new QLCDNumber(stats1Group);
        ipCountIN->setObjectName(QString::fromUtf8("ipCountIN"));
        ipCountIN->setGeometry(QRect(100, 140, 51, 23));
        ipCountIN->setSegmentStyle(QLCDNumber::Flat);
        eth2CountOUT = new QLCDNumber(stats1Group);
        eth2CountOUT->setObjectName(QString::fromUtf8("eth2CountOUT"));
        eth2CountOUT->setGeometry(QRect(170, 90, 51, 23));
        eth2CountOUT->setSegmentStyle(QLCDNumber::Flat);
        ipCountOUT = new QLCDNumber(stats1Group);
        ipCountOUT->setObjectName(QString::fromUtf8("ipCountOUT"));
        ipCountOUT->setGeometry(QRect(170, 140, 51, 23));
        ipCountOUT->setSegmentStyle(QLCDNumber::Flat);
        arpCountOUT = new QLCDNumber(stats1Group);
        arpCountOUT->setObjectName(QString::fromUtf8("arpCountOUT"));
        arpCountOUT->setGeometry(QRect(170, 190, 51, 23));
        arpCountOUT->setSegmentStyle(QLCDNumber::Flat);
        arpCountIN = new QLCDNumber(stats1Group);
        arpCountIN->setObjectName(QString::fromUtf8("arpCountIN"));
        arpCountIN->setGeometry(QRect(100, 190, 51, 23));
        arpCountIN->setSegmentStyle(QLCDNumber::Flat);
        tcpCountIN = new QLCDNumber(stats1Group);
        tcpCountIN->setObjectName(QString::fromUtf8("tcpCountIN"));
        tcpCountIN->setGeometry(QRect(100, 240, 51, 23));
        tcpCountIN->setSegmentStyle(QLCDNumber::Flat);
        eth2CountIN = new QLCDNumber(stats1Group);
        eth2CountIN->setObjectName(QString::fromUtf8("eth2CountIN"));
        eth2CountIN->setGeometry(QRect(100, 90, 51, 23));
        eth2CountIN->setSegmentStyle(QLCDNumber::Flat);
        udpCountOUT = new QLCDNumber(stats1Group);
        udpCountOUT->setObjectName(QString::fromUtf8("udpCountOUT"));
        udpCountOUT->setGeometry(QRect(170, 290, 51, 23));
        udpCountOUT->setSegmentStyle(QLCDNumber::Flat);
        udpCountIN = new QLCDNumber(stats1Group);
        udpCountIN->setObjectName(QString::fromUtf8("udpCountIN"));
        udpCountIN->setGeometry(QRect(100, 290, 51, 23));
        udpCountIN->setSegmentStyle(QLCDNumber::Flat);
        tcpCountOUT = new QLCDNumber(stats1Group);
        tcpCountOUT->setObjectName(QString::fromUtf8("tcpCountOUT"));
        tcpCountOUT->setGeometry(QRect(170, 240, 51, 23));
        tcpCountOUT->setSegmentStyle(QLCDNumber::Flat);
        label_6 = new QLabel(stats1Group);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 90, 71, 17));
        label_7 = new QLabel(stats1Group);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 140, 68, 17));
        label_8 = new QLabel(stats1Group);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 190, 68, 17));
        label_14 = new QLabel(stats1Group);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 240, 68, 17));
        label_15 = new QLabel(stats1Group);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 290, 68, 17));
        icmpCountIN = new QLCDNumber(stats1Group);
        icmpCountIN->setObjectName(QString::fromUtf8("icmpCountIN"));
        icmpCountIN->setGeometry(QRect(100, 340, 51, 23));
        icmpCountIN->setSegmentStyle(QLCDNumber::Flat);
        icmpCountOUT = new QLCDNumber(stats1Group);
        icmpCountOUT->setObjectName(QString::fromUtf8("icmpCountOUT"));
        icmpCountOUT->setGeometry(QRect(170, 340, 51, 23));
        icmpCountOUT->setSegmentStyle(QLCDNumber::Flat);
        label_16 = new QLabel(stats1Group);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 340, 68, 17));
        httpCountIN = new QLCDNumber(stats1Group);
        httpCountIN->setObjectName(QString::fromUtf8("httpCountIN"));
        httpCountIN->setGeometry(QRect(100, 390, 51, 23));
        httpCountIN->setSegmentStyle(QLCDNumber::Flat);
        httpCountOUT = new QLCDNumber(stats1Group);
        httpCountOUT->setObjectName(QString::fromUtf8("httpCountOUT"));
        httpCountOUT->setGeometry(QRect(170, 390, 51, 23));
        httpCountOUT->setSegmentStyle(QLCDNumber::Flat);
        label_17 = new QLabel(stats1Group);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 390, 68, 17));
        resetStats1_button = new QPushButton(stats1Group);
        resetStats1_button->setObjectName(QString::fromUtf8("resetStats1_button"));
        resetStats1_button->setGeometry(QRect(170, 10, 61, 27));
        stats2Group = new QGroupBox(centralwidget);
        stats2Group->setObjectName(QString::fromUtf8("stats2Group"));
        stats2Group->setGeometry(QRect(940, 30, 251, 421));
        stats2Group->setAutoFillBackground(false);
        stats2Group->setStyleSheet(QString::fromUtf8(""));
        stats2Group->setFlat(false);
        stats2Group->setCheckable(false);
        stats2Group->setChecked(false);
        label_18 = new QLabel(stats2Group);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(120, 60, 21, 17));
        label_19 = new QLabel(stats2Group);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(180, 60, 31, 17));
        ipCountIN_2 = new QLCDNumber(stats2Group);
        ipCountIN_2->setObjectName(QString::fromUtf8("ipCountIN_2"));
        ipCountIN_2->setGeometry(QRect(100, 140, 51, 23));
        ipCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        eth2CountOUT_2 = new QLCDNumber(stats2Group);
        eth2CountOUT_2->setObjectName(QString::fromUtf8("eth2CountOUT_2"));
        eth2CountOUT_2->setGeometry(QRect(170, 90, 51, 23));
        eth2CountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        ipCountOUT_2 = new QLCDNumber(stats2Group);
        ipCountOUT_2->setObjectName(QString::fromUtf8("ipCountOUT_2"));
        ipCountOUT_2->setGeometry(QRect(170, 140, 51, 23));
        ipCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        arpCountOUT_2 = new QLCDNumber(stats2Group);
        arpCountOUT_2->setObjectName(QString::fromUtf8("arpCountOUT_2"));
        arpCountOUT_2->setGeometry(QRect(170, 190, 51, 23));
        arpCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        arpCountIN_2 = new QLCDNumber(stats2Group);
        arpCountIN_2->setObjectName(QString::fromUtf8("arpCountIN_2"));
        arpCountIN_2->setGeometry(QRect(100, 190, 51, 23));
        arpCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        tcpCountIN_2 = new QLCDNumber(stats2Group);
        tcpCountIN_2->setObjectName(QString::fromUtf8("tcpCountIN_2"));
        tcpCountIN_2->setGeometry(QRect(100, 240, 51, 23));
        tcpCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        eth2CountIN_2 = new QLCDNumber(stats2Group);
        eth2CountIN_2->setObjectName(QString::fromUtf8("eth2CountIN_2"));
        eth2CountIN_2->setGeometry(QRect(100, 90, 51, 23));
        eth2CountIN_2->setSegmentStyle(QLCDNumber::Flat);
        udpCountOUT_2 = new QLCDNumber(stats2Group);
        udpCountOUT_2->setObjectName(QString::fromUtf8("udpCountOUT_2"));
        udpCountOUT_2->setGeometry(QRect(170, 290, 51, 23));
        udpCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        udpCountIN_2 = new QLCDNumber(stats2Group);
        udpCountIN_2->setObjectName(QString::fromUtf8("udpCountIN_2"));
        udpCountIN_2->setGeometry(QRect(100, 290, 51, 23));
        udpCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        tcpCountOUT_2 = new QLCDNumber(stats2Group);
        tcpCountOUT_2->setObjectName(QString::fromUtf8("tcpCountOUT_2"));
        tcpCountOUT_2->setGeometry(QRect(170, 240, 51, 23));
        tcpCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        label_20 = new QLabel(stats2Group);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 90, 71, 17));
        label_21 = new QLabel(stats2Group);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 140, 68, 17));
        label_22 = new QLabel(stats2Group);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 190, 68, 17));
        label_23 = new QLabel(stats2Group);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 240, 68, 17));
        label_24 = new QLabel(stats2Group);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 290, 68, 17));
        icmpCountIN_2 = new QLCDNumber(stats2Group);
        icmpCountIN_2->setObjectName(QString::fromUtf8("icmpCountIN_2"));
        icmpCountIN_2->setGeometry(QRect(100, 340, 51, 23));
        icmpCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        icmpCountOUT_2 = new QLCDNumber(stats2Group);
        icmpCountOUT_2->setObjectName(QString::fromUtf8("icmpCountOUT_2"));
        icmpCountOUT_2->setGeometry(QRect(170, 340, 51, 23));
        icmpCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        label_25 = new QLabel(stats2Group);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 340, 68, 17));
        httpCountIN_2 = new QLCDNumber(stats2Group);
        httpCountIN_2->setObjectName(QString::fromUtf8("httpCountIN_2"));
        httpCountIN_2->setGeometry(QRect(100, 390, 51, 23));
        httpCountIN_2->setSegmentStyle(QLCDNumber::Flat);
        httpCountOUT_2 = new QLCDNumber(stats2Group);
        httpCountOUT_2->setObjectName(QString::fromUtf8("httpCountOUT_2"));
        httpCountOUT_2->setGeometry(QRect(170, 390, 51, 23));
        httpCountOUT_2->setSegmentStyle(QLCDNumber::Flat);
        label_26 = new QLabel(stats2Group);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 390, 68, 17));
        resetStats2_button = new QPushButton(stats2Group);
        resetStats2_button->setObjectName(QString::fromUtf8("resetStats2_button"));
        resetStats2_button->setGeometry(QRect(170, 10, 61, 27));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(470, 460, 941, 341));
        filterpermitComboBox = new QComboBox(groupBox_5);
        filterpermitComboBox->setObjectName(QString::fromUtf8("filterpermitComboBox"));
        filterpermitComboBox->setGeometry(QRect(710, 60, 71, 27));
        filter_interfaceComboBox = new QComboBox(groupBox_5);
        filter_interfaceComboBox->setObjectName(QString::fromUtf8("filter_interfaceComboBox"));
        filter_interfaceComboBox->setGeometry(QRect(500, 60, 51, 27));
        filterdirectionComboBox = new QComboBox(groupBox_5);
        filterdirectionComboBox->setObjectName(QString::fromUtf8("filterdirectionComboBox"));
        filterdirectionComboBox->setGeometry(QRect(120, 60, 51, 27));
        filterprotocolComboBox = new QComboBox(groupBox_5);
        filterprotocolComboBox->setObjectName(QString::fromUtf8("filterprotocolComboBox"));
        filterprotocolComboBox->setGeometry(QRect(280, 60, 71, 27));
        filterprotocolComboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 26, 81, 21));
        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(410, 26, 71, 21));
        filter_hwsrcText = new QLineEdit(groupBox_5);
        filter_hwsrcText->setObjectName(QString::fromUtf8("filter_hwsrcText"));
        filter_hwsrcText->setGeometry(QRect(120, 20, 141, 27));
        filter_ipsrcText = new QLineEdit(groupBox_5);
        filter_ipsrcText->setObjectName(QString::fromUtf8("filter_ipsrcText"));
        filter_ipsrcText->setGeometry(QRect(500, 20, 141, 27));
        filter_ipdstText = new QLineEdit(groupBox_5);
        filter_ipdstText->setObjectName(QString::fromUtf8("filter_ipdstText"));
        filter_ipdstText->setGeometry(QRect(640, 20, 141, 27));
        filter_hwdstText = new QLineEdit(groupBox_5);
        filter_hwdstText->setObjectName(QString::fromUtf8("filter_hwdstText"));
        filter_hwdstText->setGeometry(QRect(260, 20, 141, 27));
        addFilterButton = new QPushButton(groupBox_5);
        addFilterButton->setObjectName(QString::fromUtf8("addFilterButton"));
        addFilterButton->setGeometry(QRect(850, 80, 71, 31));
        deleteFilterButton = new QPushButton(groupBox_5);
        deleteFilterButton->setObjectName(QString::fromUtf8("deleteFilterButton"));
        deleteFilterButton->setGeometry(QRect(710, 300, 99, 27));
        clearFiltersButton = new QPushButton(groupBox_5);
        clearFiltersButton->setObjectName(QString::fromUtf8("clearFiltersButton"));
        clearFiltersButton->setGeometry(QRect(820, 300, 99, 27));
        label_29 = new QLabel(groupBox_5);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(410, 60, 61, 31));
        label_30 = new QLabel(groupBox_5);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(20, 60, 61, 31));
        filter_portText = new QLineEdit(groupBox_5);
        filter_portText->setObjectName(QString::fromUtf8("filter_portText"));
        filter_portText->setGeometry(QRect(620, 60, 71, 27));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(590, 60, 31, 31));
        filterTable = new QListWidget(groupBox_5);
        filterTable->setObjectName(QString::fromUtf8("filterTable"));
        filterTable->setGeometry(QRect(10, 120, 911, 171));
        filterTable->setBatchSize(200);
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(220, 60, 68, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1450, 25));
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
        label_2->setText(QApplication::translate("MainWindow", "interface 1:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "interface 2:", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("MainWindow", "Start switching", 0, QApplication::UnicodeUTF8));
        stats1Group->setTitle(QApplication::translate("MainWindow", "Interface 1 Stats", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "IN", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "OUT", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Ethernet II", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "ARP", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "TCP", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "UDP", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "ICMP", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "HTTP", 0, QApplication::UnicodeUTF8));
        resetStats1_button->setText(QApplication::translate("MainWindow", "reset", 0, QApplication::UnicodeUTF8));
        stats2Group->setTitle(QApplication::translate("MainWindow", "Interface 2 Stats", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "IN", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "OUT", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Ethernet II", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "ARP", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "TCP", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "UDP", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "ICMP", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "HTTP", 0, QApplication::UnicodeUTF8));
        resetStats2_button->setText(QApplication::translate("MainWindow", "reset", 0, QApplication::UnicodeUTF8));
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
                << QApplication::translate("MainWindow", "any", 0, QApplication::UnicodeUTF8)
                << QApplication::translate("MainWindow", "in", 0, QApplication::UnicodeUTF8)
                << QApplication::translate("MainWindow", "out", 0, QApplication::UnicodeUTF8)
        );
        filterprotocolComboBox->clear();
        filterprotocolComboBox->insertItems(0, QStringList()
                << QApplication::translate("MainWindow", "any", 0, QApplication::UnicodeUTF8)
                << QApplication::translate("MainWindow", "TCP", 0, QApplication::UnicodeUTF8)
                << QApplication::translate("MainWindow", "UDP", 0, QApplication::UnicodeUTF8)
                << QApplication::translate("MainWindow", "ICMP", 0, QApplication::UnicodeUTF8)
                << QApplication::translate("MainWindow", "ARP", 0, QApplication::UnicodeUTF8)
                << QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8)
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
        label_10->setText(QApplication::translate("MainWindow", "protocol", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SWITCH_GUIS20382_H
