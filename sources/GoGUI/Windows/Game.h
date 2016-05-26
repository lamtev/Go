#ifndef GO_GAME_H
#define GO_GAME_H

#include <QWidget>
#include <QMessageBox>
#include <QPalette>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRect>
#include <QLabel>

class Game : public QWidget {
 Q_OBJECT

 public:
  explicit Game(const int boardSize = 19, QWidget *parent = nullptr) noexcept;

 private:
  QPixmap *background;
  QPalette *gamePalette;

  const int boardSize;

  void configureGamePalette() noexcept;


 signals:

 private slots:

};


#endif //GO_GAME_H
