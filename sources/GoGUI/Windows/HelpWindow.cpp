#include "HelpWindow.h"

HelpWindow::HelpWindow(QWidget *parent) noexcept : QWidget{parent}{
  //для тестирования
  QMessageBox mbox;
  mbox.setText(QObject::tr("Help"));
  mbox.show();
  mbox.exec();
}

