#include <QApplication>
#include <QTranslator>
#include "Windows/Menu.h"

int main(int argc, char **argv) {
  QApplication goGUI{argc, argv};

  QTranslator* ptranslator = new QTranslator{nullptr};
  ptranslator->load(QString{"i18n_"} +
                    QLocale::system().name());

  goGUI.installTranslator(ptranslator);

  Menu menu{nullptr};
  menu.move((QApplication::desktop()->width() - menu.width())/2,
            (QApplication::desktop()->height() - menu.height())/2);
  menu.show();

  return goGUI.exec();
}
