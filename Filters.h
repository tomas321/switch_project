//
// Created by root on 15.11.2017.
//

#ifndef SWITCH_PROJECT_FILTERS_H
#define SWITCH_PROJECT_FILTERS_H


#include <QtCore/QArgument>
#include <QtCore/QThread>
#include <QtGui/QWidgetItem>
#include <QtGui/QListWidgetItem>
#include <tins/tins.h>
#include <mutex>

using namespace Tins;
using namespace std;

class Filters : public QThread {
    Q_OBJECT
private:
    mutex filters_mutex;

signals:
    void filtersChanged(QVector<string>);

public slots:
    void clearFilters();
    // function addFilter returns key to filter
    int addFilter(bool permit, string ipSrc, string ipDst, string hwSrc, string hwDst,
                  string protocol, string interface, string dir, int port);
    void removeFilter(int key);

public:
    struct Filter {
        int key;
        bool permit;
        string ip_src;
        string ip_dst;
        string hw_src;
        string hw_dst;
        string protocol;
        string interface; // 1 or 2
        string direction; // in | out | any
        int port; // 0 - 65535 and if any port => port == -1
    };
    vector<Filter> filters;

    Filter *getFilter(int key);
    void printFilters();
    int getUniqueKey();
    QVector<string> filtersToStr();
    int checkAdresses(string, string, string, string);
    int checkFilters(EthernetII*, string interface, string otherInt, bool dir = false);
    PDU::PDUType parsePDUType(string type);
    int checkPort(EthernetII *frame, int port, bool permit);
    explicit Filters(QObject *parent = 0);
};


#endif //SWITCH_PROJECT_FILTERS_H
