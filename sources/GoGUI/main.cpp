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

    QBoxLayout* pbxLayout = new QBoxLayout{ QBoxLayout::TopToBottom };
    pbxLayout->addWidget(pcmdStartGame, 1);
    pbxLayout->addWidget(pcmdHelp, 2);
    pbxLayout->addWidget(pcmdSettings, 3);
    pbxLayout->addWidget(pcmdExit, 4);
    wgt.setLayout(pbxLayout);

    wgt.resize(300, 200);
    wgt.show();

    qDebug() <<  goGUI.metaObject()->superClass()->superClass()->superClass()->className();

    return goGUI.exec();
}
