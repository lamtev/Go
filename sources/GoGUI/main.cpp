#include <QApplication>

#include "Windows/Menu.h"

int main(int argc, char **argv) {
  QApplication goGUI{argc, argv};
  Menu menu{nullptr};

  menu.move((QApplication::desktop()->width() - menu.width())/2,
            (QApplication::desktop()->height() - menu.height())/2);
  menu.show();

  return goGUI.exec();
}
