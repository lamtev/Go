#include <QtWidgets>
#include <QDebug>

#include <iostream>


int main( int argc, char** argv )
{
    QApplication goGUI{ argc, argv };

    QSplitter spl{ Qt::Vertical };
    QTextEdit* ptxt1 = new QTextEdit;
    QTextEdit* ptxt2 = new QTextEdit;
    spl.addWidget(ptxt1);
    spl.addWidget(ptxt2);

    ptxt1->setPlainText(
        "GoGUI 1\n"
        "GoGUI 2\n"
        "GoGUI 3\n"
        "GoGUI 4\n"
        "GoGUI 5\n"
        "GoGUI 6\n"
        "GoGUI 7\n"
        "GoGUI 8\n"
        "GoGUI 9\n"
        "GoGUI 10\n"
    );
    ptxt2->setPlainText(ptxt1->toPlainText());

    spl.resize(200, 200);
    spl.show();

    qDebug() <<  goGUI.metaObject()->superClass()->superClass()->superClass()->className();

    return goGUI.exec();
}
