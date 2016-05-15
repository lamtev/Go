#include <QtWidgets>
#include <QVector>
#include <QString>
#include <QDebug>

#include <iostream>

#include "Counter.h"

int main( int argc, char** argv )
{
    QApplication goGUI{ argc, argv };
    QWidget wgt;

    QPushButton* pcmdStartGame = new QPushButton{ "Start game" };
    QPushButton* pcmdHelp = new QPushButton{ "Help" };
    QPushButton* pcmdSettings = new QPushButton{ "Settings" };
    QPushButton* pcmdExit = new QPushButton{ "Exit" };

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->setMargin(5);
    phbxLayout->setSpacing(5);
    phbxLayout->addWidget(pcmdHelp);
    phbxLayout->addWidget(pcmdExit);

    pvbxLayout->setMargin(5);
    pvbxLayout->setSpacing(5);
    pvbxLayout->addWidget(pcmdStartGame);
    pvbxLayout->addWidget(pcmdSettings);
    pvbxLayout->addLayout(phbxLayout);
    wgt.setLayout(pvbxLayout);

    wgt.show();

    qDebug() <<  goGUI.metaObject()->superClass()->superClass()->superClass()->className();

    return goGUI.exec();
}
