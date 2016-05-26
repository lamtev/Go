#ifndef GO_BOARDWIDGET_H
#define GO_BOARDWIDGET_H

#include <QFrame>
#include <QDebug>
#include <QPalette>

class BoardWidget : public QFrame {
 Q_OBJECT

 public:
  explicit BoardWidget(const int boardSize = 19, QFrame *parent = nullptr) noexcept;

 private:
  const int boardSize;


 signals:

 private slots:

};


#endif //GO_BOARDWIDGET_H
