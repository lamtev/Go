#ifndef GO_BOARDWIDGET_H
#define GO_BOARDWIDGET_H

#include <QFrame>
#include <QRect>
#include <QDebug>
#include <QPainter>
#include <QVector>
#include <QBrush>
#include <QPaintEvent>
#include <QMoveEvent>
#include <QPainter>
#include <QImage>

#include "../../../GoEngine/GoEngineAPI.h"

class BoardWidget : public QFrame {
 Q_OBJECT

 public:
  explicit BoardWidget(const int BOARD_DIAG = 19, QWidget *parent = nullptr) noexcept;
  ~BoardWidget() noexcept;
  GoEngineAPI *getGo() const noexcept;

 protected:
  void paintEvent(QPaintEvent *paintEvent) noexcept override;
  void update() noexcept;
  void mousePressEvent(QMouseEvent *mouseEvent) override;

 private:
  const QPixmap BACKGROUND;
  const int BOARD_DIAG;
  const int BOARD_HEIGHT;
  const int POINT_HEIGHT;
  const int DELTA;
  const int ACTIVE_BOARD_LEFT;
  const int ACTIVE_BOARD_TOP;
  const int ACTIVE_BOARD_WIDTH;
  const int ACTIVE_BOARD_HEIGHT;
  const QRect ACTIVE_BOARD_RECT;
  const int ACTIVE_ZONE_LEFT;
  const int ACTIVE_ZONE_TOP;
  const int ACTIVE_ZONE_WIDTH;
  const int ACTIVE_ZONE_HEIGHT;
  const QRect ACTIVE_ZONE_RECT;
  const QRect BOARD_RECT;
  QVector<QRect> pointsRects;

  bool isGoConfigured;

  GoEngineAPI *go;

  void drawBoard(QPainter &painter) const noexcept;
  void drawStones(QPainter &painter) noexcept;
  void drawStone(QPainter &painter, const QString& color) const noexcept;
  QPoint determinePointCoordinates(const QPoint &qPoint) const noexcept;
  void configureGo() noexcept;

 signals:

 private slots:

};


#endif //GO_BOARDWIDGET_H
