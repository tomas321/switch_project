//
// Created by root on 12.11.2017.
//

#include <QtGui/QApplication>
#include "Switch_gui.h"


int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Switch_gui gui;
    gui.show();

    return application.exec();
}