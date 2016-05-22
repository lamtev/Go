#include "Board.h"

Board::Board(QWidget *parent) noexcept : QWidget{parent},
                                         boardPalette{new QPalette} {
  setGeometry(QPixmap{":/board_background.jpg"}.rect());
  configurePalette();
}

void Board::configurePalette() noexcept {
  boardPalette->setBrush(backgroundRole(), QBrush{QPixmap{":/board_background.jpg"}});
  setPalette(*boardPalette);
}



