#include <QtWidgets/QTabWidget>
#include "Settings.h"

Settings::Settings(QWidget *parent) noexcept : QWidget{parent},
                                               background{nullptr},
                                               settingsPalette{nullptr},
                                               text{new QLabel{this}},
                                               rButton19x19{new QRadioButton{this}},
                                               rButton13x13{new QRadioButton{this}},
                                               rButton7x7{new QRadioButton{this}},
                                               buttonStartGame{new QPushButton{this}},
                                               buttonReturnToMenu{new QPushButton{this}},
                                               buttonQuit{new QPushButton{this}},
                                               boardSize{19},
                                               game{nullptr},
                                               menu{nullptr} {
  setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
  configureSettingsPalette();
  configureText();
  configureButtons();
}

void Settings::configureSettingsPalette() noexcept {
  background = new QPixmap{":/small_window_background.jpg"};
  setFixedSize(background->size());
  settingsPalette = new QPalette;
  settingsPalette->setBrush(backgroundRole(), QBrush{*background});
  setPalette(*settingsPalette);
}

void Settings::configureText() noexcept {
  text->setText(QObject::tr("Chose board size"));
  text->move((width() - text->width())/2,
             (height() - text->height())/2 - 2*text->height());
}

void Settings::configureButtons() noexcept {
  configureRButton19x19();
  configureRButton13x13();
  configureRButton7x7();
  configureButtonStartGame();
  configureButtonReturnToMenu();
  configureButtonQuit();
}

void Settings::configureRButton19x19() noexcept {
  rButton19x19->setText(QObject::tr("19 x 19"));
  rButton19x19->setChecked(true);
  rButton19x19->move((width() - rButton19x19->width())/2,
                     (height() - rButton19x19->height())/2 - rButton19x19->height());
}

void Settings::configureRButton13x13() noexcept {
  rButton13x13->setText(QObject::tr("13 x 13"));
  rButton13x13->move((width() - rButton13x13->width())/2,
                     (height() - rButton13x13->height())/2);
}

void Settings::configureRButton7x7() noexcept {
  rButton7x7->setText(QObject::tr(" 7 x 7"));
  rButton7x7->move((width() - rButton7x7->width())/2,
                     (height() - rButton7x7->height())/2 + rButton7x7->height());
}

void Settings::configureButtonStartGame() noexcept {
  buttonStartGame->setText(QObject::tr("Start game"));
  buttonStartGame->move((width() - buttonStartGame->width())/2 - buttonStartGame->width()/2,
                        (height() - buttonStartGame->height())/2 + 2*buttonStartGame->height());
  connect(buttonStartGame, SIGNAL(clicked()), SLOT(slotOpenGame()));
}

void Settings::configureButtonReturnToMenu() noexcept {
  buttonReturnToMenu->setText(QObject::tr("Return to menu"));
  buttonReturnToMenu->move((width() - buttonReturnToMenu->width())/2 + buttonReturnToMenu->width()/2,
                           (height() - buttonReturnToMenu->height())/2 + 2*buttonReturnToMenu->height());
  connect(buttonReturnToMenu, SIGNAL(clicked()), SLOT(slotReturnToMenu()));
}

void Settings::configureButtonQuit() noexcept {
  buttonQuit->setText(QObject::tr("Quit"));
  connect(buttonQuit, SIGNAL(clicked()), SLOT(close()));
}

void Settings::determineBoardSize() noexcept {
  if (rButton19x19->isChecked()) {
    boardSize = 19;
  }
  else if (rButton13x13->isChecked()) {
    boardSize = 13;
  }
  else if (rButton7x7->isChecked())
  {
    boardSize = 7;
  }
}

void Settings::slotOpenGame() noexcept {
  determineBoardSize();
  game = new Game{boardSize, nullptr};
  close();
  game->show();
}

void Settings::slotReturnToMenu() noexcept {
  menu = new Menu{nullptr};
  close();
  menu->show();
}
