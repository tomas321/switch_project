//
// Created by root on 15.10.2017.
//

#include "MAC_table.h"
#include <iostream>
#include <sstream>
#include <thread>

#define TIMER_LIMIT 10 // entry timer for deleting an entry

using namespace Tins;
using namespace std;

MAC_table::MAC_table(QObject *parent) : QThread(parent) {
    this->global_timer = TIMER_LIMIT;
}

void MAC_table::run() {
    while (1) {
        if (isEmpty())  {
            continue;
        }
        unique_lock<mutex> lock(table_handle_mutex);
        decrement_timers();
        for (auto &entry : table) {
            if (entry.timer == 0) {
                remove_entry(entry.addr);
            }
        }
        lock.unlock();
        sleep(1);
    }
}

bool MAC_table::isEmpty() {
    return !this->table.size();
}

bool MAC_table::has_entry(HWAddress<6> addr, string port) {
    lock_guard<mutex> lock(table_handle_mutex);
    for (auto &entry : this->table) {
        if (entry.addr == addr && entry.port == port) {
            return true;
        }
    }
    //lock.unlock();
    return false;
}

bool MAC_table::add_entry(HWAddress<6> addr, string port) {
    lock_guard<mutex> lock(table_handle_mutex);
    Entry new_entry = {addr, port, global_timer};
    for (auto &entry : this->table) {
        if (addr == entry.addr && port.compare(entry.port) == 0) {
            entry.timer = global_timer;
            emit tableChanged(vectorToQvecStr());
            return false; // if the MAC addr already exists in the table
        }
        if (addr == entry.addr && port.compare(entry.port) != 0) {
            // do this if only port is different => update port
            entry.port = port;
            entry.timer = global_timer;
            //restore_timer(addr); // restore timer for "new" modified entry
            emit tableChanged(vectorToQvecStr());
            return true;
        }
    }
    this->table.push_back(new_entry);
    cout << "ADD: " << new_entry.addr << "\t" << new_entry.port << " " << new_entry.timer << " from thread: " << this_thread::get_id() << endl;
    emit tableChanged(vectorToQvecStr());
    return true;
}

bool MAC_table::remove_entry(HWAddress<6> hw_addr) {
    int pos = 0;
    for (auto &entry : this->table) {
        if (entry.addr == hw_addr) {
            this->table.erase(this->table.begin() + pos);
            cout << "ERASE: " << hw_addr << endl;
            emit tableChanged(vectorToQvecStr());
            return true;
        }
        pos++;
    }
    return false;
}

int MAC_table::remove_entry(string port) {
    lock_guard<mutex> lock(table_handle_mutex);
    int pos = 0;
    int count = 0;
    for (auto &entry_ : this->table) {
        if (entry_.port == port) {
            this->table[pos] = this->table.back();
            this->table.pop_back();
            count++;
        }
        pos++;
    }
    cout << "ERASE: " << count << " ENTRIES REMOVED" << endl;
    //lock.unlock();
    return pos;
}

void MAC_table::clear_table() {
    lock_guard<mutex> lock(table_handle_mutex);
    auto size = this->table.size();
    this->table.clear();
    cout << "ERASE: all " << size << " elements\n";
    emit tableChanged(vectorToQvecStr());
    //lock.unlock();
}

MAC_table::Entry *MAC_table::get_entry(HWAddress<6> addr) {
    lock_guard<mutex> lock(table_handle_mutex);
    for (int i = 0; i < this->table.size(); i++) {
        if (this->table[i].addr == addr) {
            Entry *entry = &this->table[i];
            //lock.unlock();
            return entry;
        }
    }
    return nullptr;
}

vector<MAC_table::Entry> MAC_table::get_entry(string port) {
    lock_guard<mutex> lock(table_handle_mutex);
    vector<MAC_table::Entry> vec;
    for (auto &entry_ : this->table) {
        if (entry_.port == port) {
            vec.push_back(entry_);
        }
    }
    return vec;
}

vector<MAC_table::Entry> MAC_table::get_table() {
    return this->table;
}

unsigned long MAC_table::get_size() {
    return this->table.size();
}

// decrements timers and deletes entries with timer == 0
void MAC_table::decrement_timers() {
    for (auto &entry : this->table) {
        // if the entry timer is 0 after decrementation => remove entry
        if (entry.timer > 0) entry.timer--;
    }
    emit tableChanged(vectorToQvecStr());
}

void MAC_table::restore_timer(HWAddress<6> addr) {
    lock_guard<mutex> lock(table_handle_mutex);
    for (auto &entry : this->table) {
        if (entry.addr == addr) {
            stringstream msg;
            msg << "modified timer for" << entry.addr << endl;
            cout << msg.str();
            entry.timer = global_timer;
        }
    }
    emit tableChanged(vectorToQvecStr());
    //lock.unlock();
}

void MAC_table::print_MAC_table() {
    lock_guard<mutex> lock(table_handle_mutex);
    auto mac_table = get_table();
    for (auto &entry : mac_table) {
        cout << entry.timer << " " << entry.addr << "\t" << entry.port << endl;
    }
    cout << "SIZE: " << mac_table.size() << endl;
    //lock.unlock();
}

vector<string> gen_rand_HWaddr(int count) {
    vector<string> addrs;
    char temp[18];
    for (int i = 0; i < count; i++) {
        snprintf(temp, sizeof(temp), "f8:54:78:ca:%02X:%02X", i / 256, i % 256);
        addrs.push_back(string(temp));
    }
    return addrs;
}

void MAC_table::setTimer(unsigned int t) {
    lock_guard<mutex> lock(table_handle_mutex);
    this->global_timer = t;
    //lock.unlock();
}

unsigned int MAC_table::getTimer() {
    return this->global_timer;
}

QVector<string> MAC_table::vectorToQvecStr() {
    QVector<string> qlist;
    for (auto &entry : table) {
        stringstream entryString;
        entryString << entry.addr << ";" << entry.port << ";" << entry.timer;
        qlist.push_back(entryString.str());
    }
    return qlist;
}

QVector<QListWidgetItem> MAC_table::tableToQList() {
    QVector<QListWidgetItem> qlist;
    for (auto &entry : table) {
        stringstream entryString;
        entryString << entry.addr << ";" << entry.port << ";" << entry.timer;
        QString qStr = QString::fromStdString(string(entryString.str()));
        qlist.push_back(QListWidgetItem(qStr));
    }
    return qlist;
}

/*
int test_MAC_table() {
    MAC_table macTable;
    int count = 1000;
    int indeces[10] = {0, 5, 8, 10, 30, 18, 7, 63, 99, 11};

    auto addrs = gen_rand_HWaddr(count);
    // print generated addresses
//    for (auto &addr : addrs) cout << addr << endl;
    // add half of entries with one interface

    for (int i = 0; i < count/2; i++) macTable.add_entry(HWAddress<6>(addrs[i]), "enx00133b9c6839");

    // remove random fifth of entries by address
    for (int i = 0; i < 10; i++) {
        //auto index = rand() % macTable.get_size() - i;
        auto index = indeces[i];
        if (!macTable.remove_entry(HWAddress<6>(addrs[index])))
            return 1; // fails to remove entry
    }
    macTable.print_MAC_table();

    // add other half of entries with other interface
    for (int i = count/2; i < count; i++) macTable.add_entry(HWAddress<6>(addrs[i]), "enp3s0");

    // remove all entries w/ given interface
    if (!macTable.remove_entry(string("enx00133b9c6839"))) return 1;

    macTable.print_MAC_table();
    // clear all table
    while (!macTable.isEmpty()) {
        macTable.decrement_timers();
        //macTable.print_MAC_table();
    }
    // is redundant
//    macTable.clear_table();
    macTable.add_entry(addrs[0], "eth1");
    macTable.add_entry(addrs[1], "eth2");
    macTable.add_entry(addrs[2], "eth1");
    // its quiet for one clock
    macTable.decrement_timers();
    //its quiet for one clock
    macTable.decrement_timers();
    // received packet from addrs[2]
    macTable.restore_timer(addrs[2]);
    cout << "2 DEC + RESET 2\n";
    macTable.print_MAC_table();

    macTable.decrement_timers();
    cout << "1 DEC\n";
    macTable.print_MAC_table();

    macTable.restore_timer(addrs[1]);
    cout << "RESET 1\n";
    macTable.print_MAC_table();

    macTable.decrement_timers();
    macTable.decrement_timers();
    cout << "2 DEC\n";
    macTable.print_MAC_table();
    // adding a known address with new interface will not work until its removed
    if (!macTable.add_entry(addrs[1], "eth3")) cout << "works.\n";
    macTable.clear_table();
    // after clear the MAC table the adding works with a new interface
    if (macTable.add_entry(addrs[1], "eth3")) cout << "works.\n";
     macTable.clear_table();

    //new test with has_entry() testing


    // mac table init
    for (int i = 0; i < 4; i++) macTable.add_entry(HWAddress<6>(addrs[i]), "eth1");
    for (int i = 4; i < 8; i++) macTable.add_entry(HWAddress<6>(addrs[i]), "eth2");

    // frame sniffed from eth1
    if (!macTable.has_entry(HWAddress<6>(addrs[1]), "eth1")) macTable.add_entry(HWAddress<6>(addrs[1]), "eth1"); // rejected
    if (!macTable.has_entry(HWAddress<6>(addrs[1]), "eth2")) macTable.add_entry(HWAddress<6>(addrs[1]), "eth2"); // rejected
    if (!macTable.has_entry(HWAddress<6>(addrs[10]), "eth1")) macTable.add_entry(HWAddress<6>(addrs[10]), "eth1"); // added
    macTable.print_MAC_table();

    return 0;
}*/