#include <QtWidgets/QGraphicsScene>
#include "Game.h"

Game::Game(const int boardSize, QWidget *parent) noexcept : QWidget{parent, Qt::WindowCloseButtonHint |
                                                                            Qt::WindowMinimizeButtonHint},
                                                            background{new QPixmap{":/menu_background.jpg"}},
                                                            gamePalette{new QPalette},
                                                            boardSize{boardSize} {
  configureGamePalette();
}

void Game::configureGamePalette() noexcept {
  setFixedSize(background->width(), background->height());
  gamePalette->setBrush(backgroundRole(), QBrush{*background});
  setPalette(*gamePalette);
}



