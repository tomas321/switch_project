//
// Created by root on 15.10.2017.
//

#ifndef SWITCH_PROJECT_MAC_TABLE_H
#define SWITCH_PROJECT_MAC_TABLE_H


#include <tins/tins.h>
#include <list>
#include <mutex>
#include <QtCore/QThread>
#include <QtGui/QWidgetItem>
#include <QtGui/QListWidgetItem>

using namespace std;
using namespace Tins;

class MAC_table : public QThread {
    Q_OBJECT
private:
    mutex table_handle_mutex;
    unsigned int global_timer;

signals:
    void tableChanged(QVector<string>);
    void entryChanged(QString);

public slots:
    void restore_timer(HWAddress<6> address);
    void clear_table();

public:
    struct Entry {
        HWAddress<6> addr;
        string port;
        unsigned int timer;
    };
    vector<Entry> table;

    explicit MAC_table(QObject *parent = 0);
    bool isEmpty();
    bool has_entry(HWAddress<6> address, string port);
    bool add_entry(HWAddress<6>address, string port);
    bool remove_entry(HWAddress<6> address);
    int remove_entry(string port); // returns the number of removed entries
    Entry *get_entry(HWAddress<6> address);
    vector<Entry> get_entry(string port);
    vector<Entry> get_table();
    unsigned long get_size();
    void decrement_timers();
    void print_MAC_table();
    unsigned int getTimer();
    void setTimer(unsigned int t);
    QVector<QListWidgetItem> tableToQList();
    QVector<string> vectorToQvecStr();
    void run() override;
};


#endif //SWITCH_PROJECT_MAC_TABLE_H
