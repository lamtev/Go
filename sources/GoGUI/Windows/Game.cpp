#include "Game.h"

Game::Game(QWidget *parent) noexcept : QWidget{parent} {
  //для тестирования
  QMessageBox mbox;
  mbox.setText(QObject::tr("Game"));
  mbox.show();
  mbox.exec();
}

