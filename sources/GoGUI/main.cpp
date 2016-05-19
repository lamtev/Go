#include <QtWidgets>
#include <QDebug>
#include <QTranslator>

#include "Windows/Menu.h"

int main(int argc, char **argv) {
  QApplication goGUI{argc, argv};
  Menu menu{nullptr};

  menu.show();

  return goGUI.exec();
}
