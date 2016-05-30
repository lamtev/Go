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

  int size = 680/(boardSize-1);

  for (int i = 0; i < boardSize; ++i)
  {
    painter.drawLine(20 + size * i, 20, 20 + size * i, 700);
    painter.drawLine(20,  20 + size * i, 700, 20 + size * i);
  }
}


