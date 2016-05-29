#include "BoardWidget.h"

BoardWidget::BoardWidget(const int boardSize, QFrame *parent) noexcept : QFrame{parent},
                                                                         boardSize{boardSize},
                                                                         boardPalette{nullptr} {
  setFixedSize(QPixmap{":/board_background.jpg"}.size());
}
