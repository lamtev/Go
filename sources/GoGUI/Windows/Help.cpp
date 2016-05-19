#include "Help.h"

Help::Help(QWidget *parent) noexcept : QWidget{parent}{
  //для тестирования
  QMessageBox mbox;
  mbox.setText("Help");
  mbox.show();
  mbox.exec();
}

