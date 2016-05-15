#include <QtWidgets>
#include <QVector>
#include <QString>
#include <QDebug>

#include <iostream>

#include "Counter.h"

int main( int argc, char** argv )
{
    QApplication goGUI{ argc, argv };

    QLabel lbl{ "0" };
    QPushButton cmd{ "ADD" };
    Counter counter;

    lbl.show();
    cmd.show();

    QObject::connect(&cmd, SIGNAL(clicked()), &counter, SLOT(slotIncrement()));

    QObject::connect(&counter, SIGNAL(counterChanged(int)), &lbl, SLOT(setNum(int)));

    QObject::connect(&counter, SIGNAL(goodbye()), &goGUI, SLOT(quit()));

    qDebug() <<  goGUI.metaObject()->superClass()->superClass()->superClass()->className();

    return goGUI.exec();
}
