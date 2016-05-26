#include "Game.h"

Game::Game(const int boardSize, QWidget *parent) noexcept : QWidget{parent},
                                       engine{new GoEngineAPI} {
  setWindowFlags(Qt::Window);
  QPixmap b{":/menu_background.jpg"};
  setFixedSize(b.size());
  engine->startGame(19, Rules::JAPANESE, ColorDistribution::AGREEMENT);
  engine->putStone(A, 12);
  engine->putStone(B, 13);
  engine->surrender();
}

