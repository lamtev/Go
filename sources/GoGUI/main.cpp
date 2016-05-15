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

    QHBoxLayout* pbhxLayout = new QHBoxLayout;
    pbhxLayout->setMargin(10);
    pbhxLayout->setSpacing(20);
    pbhxLayout->addWidget(pcmdStartGame);
    pbhxLayout->addWidget(pcmdHelp);
    pbhxLayout->addWidget(pcmdSettings);
    pbhxLayout->addWidget(pcmdExit);
    wgt.setLayout(pbhxLayout);
    
    wgt.show();

    qDebug() <<  goGUI.metaObject()->superClass()->superClass()->superClass()->className();

    return goGUI.exec();
}
