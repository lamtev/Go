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
  const int BOARD_DIAG;
  const int BOARD_HEIGHT;
  const int POINT_HEIGHT;
  const int DELTA;
  const int ACTIVE_BOARD_LEFT;
  const int ACTIVE_BOARD_TOP;
  const int ACTIVE_BOARD_RIGHT;
  const int ACTIVE_BOARD_BOTTOM;
  const QRect ACTIVE_BOARD_RECT;
  const QRect BOARD_RECT;
  //const QRect

  bool isGoConfigured;

  GoEngineAPI *go;

  void drawBoard(QPainter &painter) const noexcept;
  void drawStone(QPainter &painter, const QString& color) const noexcept;
  QPoint determinePointCoordinates(const QPoint &qPoint) const noexcept;
  void configureGo() noexcept;

 signals:

 private slots:

};


#endif //GO_BOARDWIDGET_H
