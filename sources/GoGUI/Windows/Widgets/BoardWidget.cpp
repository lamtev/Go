#include "BoardWidget.h"

BoardWidget::BoardWidget(const int BOARD_DIAG, QWidget *parent) noexcept :
    QFrame{parent},
    BOARD_DIAG{BOARD_DIAG},
    BOARD_HEIGHT{QImage{":/board_background2.jpg"}.height()},
    POINT_HEIGHT{BOARD_HEIGHT/(BOARD_DIAG + 1)},
    DELTA{BOARD_HEIGHT - (BOARD_HEIGHT/(BOARD_DIAG + 1))*(BOARD_DIAG + 1)},
    ACTIVE_BOARD_LEFT{QPixmap{":/board_background2.jpg"}.rect().left() + 3*POINT_HEIGHT/4},
    ACTIVE_BOARD_TOP{QPixmap{":/board_background2.jpg"}.rect().top() + 3*POINT_HEIGHT/4},
    ACTIVE_BOARD_RIGHT{QPixmap{":/board_background2.jpg"}.rect().right() - 3*POINT_HEIGHT/2},
    ACTIVE_BOARD_BOTTOM{QPixmap{":/board_background2.jpg"}.rect().bottom() - 3*POINT_HEIGHT/2},
    ACTIVE_BOARD_RECT{ACTIVE_BOARD_LEFT, ACTIVE_BOARD_TOP, ACTIVE_BOARD_RIGHT, ACTIVE_BOARD_BOTTOM},
    BOARD_RECT{QPixmap{":/board_background2.jpg"}.rect()},
    isGoConfigured{false},
    go{nullptr} {
  setFixedSize(QPixmap{":/board_background2.jpg"}.size());
  configureGo();
}

BoardWidget::~BoardWidget() noexcept {
  if(isGoConfigured) {
    delete go;
  }
}

GoEngineAPI *BoardWidget::getGo() const noexcept {
  return go;
}

void BoardWidget::configureGo() noexcept {
  go = new GoEngineAPI;
  go->startGame(BOARD_DIAG, JAPANESE, NIGIRI);
  isGoConfigured = true;
}


void BoardWidget::paintEvent(QPaintEvent *paintEvent) noexcept {
  QFrame::paintEvent(paintEvent);

  QPainter painter{this};
  painter.setRenderHint(QPainter::Antialiasing);

  drawBoard(painter);
}

void BoardWidget::update() noexcept {

  QWidget::update();
}

void BoardWidget::mousePressEvent(QMouseEvent *mouseEvent) {
  if(ACTIVE_BOARD_RECT.contains(mouseEvent->pos()))
  {
    qDebug() << "nice!!!";
    int first = determinePointCoordinates(mouseEvent->pos()).x();
    int second = determinePointCoordinates(mouseEvent->pos()).y();
    //go->putStone(first, second);
  }
  update();
  QWidget::mousePressEvent(mouseEvent);
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

void BoardWidget::drawStone(QPainter &painter, const QString& color) const noexcept {
  painter.drawImage(BOARD_RECT, QImage{":/" + color + "_stone_" + QString{BOARD_DIAG}});
}

QPoint BoardWidget::determinePointCoordinates(const QPoint &qPoint) const noexcept {
  return QPoint{1, 1};
}
