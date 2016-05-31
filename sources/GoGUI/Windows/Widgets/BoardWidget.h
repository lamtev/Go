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

class BoardWidget : public QFrame {
 Q_OBJECT

 public:
  explicit BoardWidget(const int BOARD_DIAG = 19, QWidget *parent = nullptr) noexcept;

 protected:
  void paintEvent(QPaintEvent *paintEvent) override;

 private:
  const int BOARD_DIAG;
  const int BOARD_HEIGHT;
  const int POINT_HEIGHT;
  const int DELTA;
  const QRect BOARD_RECT;

  QPalette *boardPalette;

  void configureBoardPalette();
  void drawBoard(QPainter &painter) const noexcept;

 signals:

 private slots:

};


#endif //GO_BOARDWIDGET_H
