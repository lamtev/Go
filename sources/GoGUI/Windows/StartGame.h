#ifndef GO_STARTGAME_H
#define GO_STARTGAME_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QDebug>

#include "Game.h"

class StartGame : public QWidget {
 Q_OBJECT

 public:
  explicit StartGame(QWidget *parent = nullptr) noexcept;

 private:
  QVBoxLayout *vLayout;
  QGridLayout *gLayout;
  QLabel *text;
  QRadioButton *rButton19x19;
  QRadioButton *rButton13x13;
  QRadioButton *rButton7x7;
  QPushButton *buttonStartGame;
  QPushButton *buttonCancel;

  Game *game;

  void configureVLayout() noexcept;
  void configureGLayout() noexcept;
  void configureButtons() noexcept;
  void configureRButton19x19() noexcept;
  void configureRButton13x13() noexcept;
  void configureRButton7x7() noexcept;
  void configureButtonStartGame() noexcept;
  void configureButtonCancel() noexcept;

 signals:

 private slots:
  void slotStartGame() noexcept;

};

#endif //GO_STARTGAME_H
