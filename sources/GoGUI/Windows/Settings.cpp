#include "Settings.h"

Settings::Settings(QWidget *parent) noexcept : QWidget{parent} {
  //для тестирования
  QMessageBox mbox;
  mbox.setText(QObject::tr("Setings"));
  mbox.show();
  mbox.exec();
}
