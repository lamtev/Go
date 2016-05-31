#include "BoardWidget.h"

BoardWidget::BoardWidget(const int BOARD_DIAG, QWidget *parent) noexcept :
    QFrame{parent},
    BACKGROUND{QPixmap{":/board_background2.jpg"}},
    BOARD_DIAG{BOARD_DIAG},
    BOARD_HEIGHT{BACKGROUND.height()},
    POINT_HEIGHT{BOARD_HEIGHT/(BOARD_DIAG + 1)},
    DELTA{BOARD_HEIGHT - (BOARD_HEIGHT/(BOARD_DIAG + 1))*(BOARD_DIAG + 1)},
    ACTIVE_BOARD_LEFT{BACKGROUND.rect().left() + POINT_HEIGHT},
    ACTIVE_BOARD_TOP{BACKGROUND.rect().top() + POINT_HEIGHT},
    ACTIVE_BOARD_WIDTH{BACKGROUND.width() - 2*POINT_HEIGHT},
    ACTIVE_BOARD_HEIGHT{BACKGROUND.height() - 2*POINT_HEIGHT},
    ACTIVE_BOARD_RECT{ACTIVE_BOARD_LEFT,
                      ACTIVE_BOARD_TOP,
                      ACTIVE_BOARD_WIDTH,
                      ACTIVE_BOARD_HEIGHT},
    ACTIVE_ZONE_LEFT{ACTIVE_BOARD_LEFT - POINT_HEIGHT/4},
    ACTIVE_ZONE_TOP{ACTIVE_BOARD_TOP - POINT_HEIGHT/4},
    ACTIVE_ZONE_WIDTH{ACTIVE_BOARD_WIDTH + 2*POINT_HEIGHT/4},
    ACTIVE_ZONE_HEIGHT{ACTIVE_BOARD_HEIGHT + 2*POINT_HEIGHT/4},
    ACTIVE_ZONE_RECT{ACTIVE_ZONE_LEFT,
                     ACTIVE_ZONE_TOP,
                     ACTIVE_ZONE_WIDTH,
                     ACTIVE_ZONE_HEIGHT},
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
  drawStones(painter);
}

void BoardWidget::update() noexcept {

  QWidget::update();
}

void BoardWidget::mousePressEvent(QMouseEvent *mouseEvent) {
  if(ACTIVE_ZONE_RECT.contains(mouseEvent->pos()))
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

void BoardWidget::drawStones(QPainter &painter) noexcept {
  //pointsRects.resize(BOARD_DIAG*BOARD_DIAG);

//  for (auto rect : pointsRects) {
//    rect = QRect{};
//  }
  drawStone(painter, "black");
}

void BoardWidget::drawStone(QPainter &painter, const QString& color) const noexcept {
  const char *diagonal;
  switch (BOARD_DIAG) {
    case 19 :
      diagonal = "19";
      break;
    case 13 :
      diagonal = "13";
      break;
    case 7 :
      diagonal = "7";
      break;
    default:
      qDebug() << "Wrong diagonal";
  }
  QRect rect{ACTIVE_BOARD_LEFT - POINT_HEIGHT/2,
             ACTIVE_BOARD_TOP - POINT_HEIGHT/2,
             POINT_HEIGHT,
             POINT_HEIGHT};
  //painter.drawImage(rect, QImage{":/" + color + "_stone_" + diagonal + ".png"});
  painter.drawImage(rect, QImage{":/white_stone.png"});
}

QPoint BoardWidget::determinePointCoordinates(const QPoint &qPoint) const noexcept {
  return QPoint{1, 1};
}
