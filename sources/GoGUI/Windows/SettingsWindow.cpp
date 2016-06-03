#include <QtWidgets/QTabWidget>
#include "SettingsWindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) noexcept : QWidget{parent, Qt::WindowStaysOnTopHint},
                                               background{new QPixmap{":/menu_background.jpg"}},
                                               settingsPalette{new QPalette},
                                               text{new QLabel{this}},
                                               rButton19x19{new QRadioButton{this}},
                                               rButton13x13{new QRadioButton{this}},
                                               rButton7x7{new QRadioButton{this}},
                                               buttonStartGame{new QPushButton{this}},
                                               buttonReturnToMenu{new QPushButton{this}},
                                               buttonQuit{new QPushButton{this}},
                                               boardDiag{19},
                                               game{nullptr},
                                               menu{nullptr} {
  setWindowTitle(QObject::tr("Go"));
  setWindowIcon(QIcon{":/icon100x100.png"});
  configureSettingsPalette();
  configureText();
  configureButtons();
}

void SettingsWindow::configureSettingsPalette() noexcept {
  setFixedSize(background->size());
  //settingsPalette->setBrush(backgroundRole(), QBrush{*background});
  settingsPalette->setColor(QPalette::Background, QColor{QRgb{0x00ffff}});
  setPalette(*settingsPalette);
}

void SettingsWindow::configureText() noexcept {
  text->setText(QObject::tr("Chose board size"));
  text->setFixedSize(275, 35);
  text->setStyleSheet(textStyle);
  text->move((width() - text->width())/2,
             (height() - text->height())/2 - 2*text->height());
}

void SettingsWindow::configureButtons() noexcept {
  configureRButton19x19();
  configureRButton13x13();
  configureRButton7x7();
  configureButtonStartGame();
  configureButtonReturnToMenu();
  configureButtonQuit();
}

void SettingsWindow::configureRButton19x19() noexcept {
  rButton19x19->setText(QObject::tr("19 x 19"));
  rButton19x19->setStyleSheet(rButtonsStyle);
  rButton19x19->setChecked(true);
  rButton19x19->move((width() - rButton19x19->width())/2,
                     (height() - rButton19x19->height())/2 - rButton19x19->height());
}

void SettingsWindow::configureRButton13x13() noexcept {
  rButton13x13->setText(QObject::tr("13 x 13"));
  rButton13x13->setStyleSheet(rButtonsStyle);
  rButton13x13->move((width() - rButton13x13->width())/2,
                     (height() - rButton13x13->height())/2);
}

void SettingsWindow::configureRButton7x7() noexcept {
  rButton7x7->setText(QObject::tr(" 7 x 7"));
  rButton7x7->setStyleSheet(rButtonsStyle);
  rButton7x7->move((width() - rButton7x7->width())/2,
                     (height() - rButton7x7->height())/2 + rButton7x7->height());
}

void SettingsWindow::configureButtonStartGame() noexcept {
  buttonStartGame->setText(QObject::tr("Start game"));
  buttonStartGame->setStyleSheet(pushButtonsStyle);
  buttonStartGame->setFixedSize(250, 35);
  buttonStartGame->move((width() - buttonStartGame->width())/2 - buttonStartGame->width(),
                        (height() - buttonStartGame->height())/2 + 2*buttonStartGame->height());
  connect(buttonStartGame, SIGNAL(clicked()), SLOT(slotOpenGame()));
}

void SettingsWindow::configureButtonReturnToMenu() noexcept {
  buttonReturnToMenu->setText(QObject::tr("Return to menu"));
  buttonReturnToMenu->setStyleSheet(pushButtonsStyle);
  buttonReturnToMenu->setFixedSize(250, 35);
  buttonReturnToMenu->move((width() - buttonReturnToMenu->width())/2,
                           (height() - buttonReturnToMenu->height())/2 + 2*buttonReturnToMenu->height());
  connect(buttonReturnToMenu, SIGNAL(clicked()), SLOT(slotReturnToMenu()));
}

void SettingsWindow::configureButtonQuit() noexcept {
  buttonQuit->setText(QObject::tr("Quit"));
  buttonQuit->setStyleSheet(pushButtonsStyle);
  buttonQuit->setFixedSize(250, 35);
  buttonQuit->move((width() - buttonQuit->width())/2 + buttonQuit->width() + 23,
                   (height() - buttonQuit->height())/2 + 2*buttonQuit->height());
  connect(buttonQuit, SIGNAL(clicked()), SLOT(close()));
}

void SettingsWindow::determineBoardSize() noexcept {
  if (rButton19x19->isChecked()) {
    boardDiag = 19;
  }
  else if (rButton13x13->isChecked()) {
    boardDiag = 13;
  }
  else if (rButton7x7->isChecked())
  {
    boardDiag = 7;
  }
}

void SettingsWindow::slotOpenGame() noexcept {
  determineBoardSize();
  game = new GameWindow{boardDiag, nullptr};
  close();
  game->move(x(), y());
  game->show();
}

void SettingsWindow::slotReturnToMenu() noexcept {
  menu = new MenuWindow{nullptr};
  close();
  menu->show();
}
