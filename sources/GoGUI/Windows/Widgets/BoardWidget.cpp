#include "BoardWidget.h"

BoardWidget::BoardWidget(const int BOARD_DIAG, QWidget *parent) noexcept :
    QFrame{parent},
    BOARD_DIAG{BOARD_DIAG},
    BOARD_HEIGHT{QImage{":/board_background2.jpg"}.height()},
    POINT_HEIGHT{BOARD_HEIGHT/(BOARD_DIAG + 1)},
    BOARD_RECT{QPixmap{":/board_background2.jpg"}.rect()},
    DELTA{BOARD_HEIGHT - (BOARD_HEIGHT/(BOARD_DIAG + 1))*(BOARD_DIAG + 1)},
    boardPalette{nullptr} {
  setFixedSize(QPixmap{":/board_background2.jpg"}.size());
}

void BoardWidget::paintEvent(QPaintEvent *paintEvent) {
  QFrame::paintEvent(paintEvent);

  QPainter painter{this};
  painter.setRenderHint(QPainter::Antialiasing);

  drawBoard(painter);
}

void BoardWidget::drawBoard(QPainter &painter) const noexcept {
  painter.drawImage(BOARD_RECT, QImage{":/board_background2.jpg"});
  painter.drawRect(BOARD_RECT);
  painter.setPen(Qt::black);

  for (int i = 0; i < BOARD_DIAG; ++i) {
    QPoint fromVertical{POINT_HEIGHT*(i+1), POINT_HEIGHT};
    QPoint toVertical{POINT_HEIGHT*(i+1), BOARD_HEIGHT - POINT_HEIGHT - DELTA};
    painter.drawLine(fromVertical, toVertical);

    QPoint fromHorizontal{POINT_HEIGHT,  POINT_HEIGHT*(i+1)};
    QPoint toHorizontal{BOARD_HEIGHT - POINT_HEIGHT - DELTA, POINT_HEIGHT*(i+1)};
    painter.drawLine(fromHorizontal, toHorizontal);
  }
}


