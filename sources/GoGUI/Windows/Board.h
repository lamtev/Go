#ifndef GO_BOARD_H
#define GO_BOARD_H

#include <QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

class Board : public QWidget {
 Q_OBJECT

 public:
  explicit Board(QWidget *parent = nullptr) noexcept;

 private:
  QPalette *boardPalette;

  void configurePalette() noexcept;

 signals:


 private slots:


};


#endif //GO_BOARD_H
