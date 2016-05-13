#include <QtWidgets>
#include <QVector>

int main( int argc, char** argv )
{
    QApplication goGUI{ argc, argv };
    const QVector<const char*> vec{
        "GUI is almost done!",
        "AHAHAHAHA",
        "Go"
    };

    QLabel label1{ vec[0] };
    label1.show();

    QLabel label2{ vec[1] };
    label2.show();

    QLabel label3{ vec[2] };
    label3.show();

    return goGUI.exec();
}
