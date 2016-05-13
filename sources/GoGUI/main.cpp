#include <QtWidgets>

int main( int argc, char** argv )
{
    QApplication goGUI{ argc, argv };
    QLabel label{ "GoGUI" };

    label.show();

    return goGUI.exec();
}
