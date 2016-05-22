#include "Game.h"

Game::Game(QWidget *parent) noexcept : QWidget{parent},
                                       engine{new GoEngineAPI} {
  setGeometry(0, 0, 1200, 1200);
  engine->startGame(19, Rules::JAPANESE, ColorDistribution::AGREEMENT);
  engine->putStone(A, 12);
  engine->putStone(B, 13);
  engine->surrender();
  QMessageBox b;
  b.setText(QString{engine->whoWon() == Status::BLACK ? "BLACK" : "WHITE"});
  b.show();
  b.exec();
}
