#include "Settings.h"

Settings::Settings(QWidget *parent) noexcept : QWidget{parent} {
  //для тестирования
  QMessageBox mbox;
  mbox.setText("Setings");
  mbox.show();
  mbox.exec();
}
