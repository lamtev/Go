#include "BoardWidget.h"

BoardWidget::BoardWidget(const int boardSize, QWidget *parent) noexcept : QFrame{parent},
                                                                          boardSize{boardSize},
                                                                          BOARD_RECT{QPixmap{":/board_background2.jpg"}.rect()},
                                                                          boardPalette{nullptr} {
  setFixedSize(QPixmap{":/board_background2.jpg"}.size());
}

void BoardWidget::paintEvent(QPaintEvent *paintEvent) {
  QFrame::paintEvent(paintEvent);

  QPainter painter{this};
  painter.setRenderHint(QPainter::Antialiasing);

  drawBoard(painter);
}

void BoardWidget::drawBoard(QPainter &painter) const noexcept
{
  painter.drawImage(BOARD_RECT, QImage(":/board_background2.jpg"));
  painter.drawRect(BOARD_RECT);
  painter.setPen(Qt::black);

  int size = 640/(boardSize-1);
  //TODO придумать норм название. и убрать костыли. и магические числа.
  int sz = size*(boardSize-1);

  for (int i = 0; i < boardSize; ++i)
  {
    painter.drawLine(40 + size * i, 40, 40 + size * i, 680);
    painter.drawLine(40,  40 + size * i, 680, 40 + size * i);
  }
}


