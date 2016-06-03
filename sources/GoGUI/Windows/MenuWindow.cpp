#include "MenuWindow.h"

MenuWindow::MenuWindow(QMainWindow *parent) noexcept : QMainWindow{parent},
                                           menuPalette{new QPalette},
                                           buttonStartGame{new QPushButton{QObject::tr("Start game"), this}},
                                           buttonHelp{new QPushButton{QObject::tr("Help"), this}},
                                           buttonQuit{new QPushButton{QObject::tr("Quit"), this}},
                                           settings{nullptr},
                                           help{nullptr} {
  setFixedSize(QPixmap{":/menu_background.jpg"}.size());
  setWindowTitle(QObject::tr("Go"));
  setWindowIcon(QIcon{":/icon100x100.png"});
  configurePalette();
  configureButtons();
}

void MenuWindow::configurePalette() noexcept {
  //menuPalette->setBrush(backgroundRole(), QBrush{QPixmap{":/menu_background.jpg"}});
  //menuPalette->setBrush(backgroundRole(), QBrush{QPixmap{":/menu_background.jpg"}});
  menuPalette->setColor(QPalette::Background, QColor{QRgb{0x00ffff}});
  setPalette(*menuPalette);
}

void MenuWindow::configureButtons() noexcept {
  configureButtonStartGame();
  configureButtonHelp();
  configureButtonQuit();
}

void MenuWindow::configureButtonStartGame() noexcept {
  buttonStartGame->setStyleSheet(pushButtonsStyle);
  buttonStartGame->setFixedSize(175, 50);
  buttonStartGame->move((width() - buttonStartGame->width())/2,
                       (height() - buttonStartGame->height())/2 - buttonStartGame->height());
  connect(buttonStartGame, SIGNAL(clicked()), SLOT(slotOpenSettings()));
}

void MenuWindow::configureButtonHelp() noexcept {
  buttonHelp->setStyleSheet(pushButtonsStyle);
  buttonHelp->setFixedSize(300, 50);
  buttonHelp->move((width() - buttonHelp->width())/2,
                   (height() - buttonHelp->height())/2);
  connect(buttonHelp, SIGNAL(clicked()), SLOT(slotOpenHelp()));
}

void MenuWindow::configureButtonQuit() noexcept {
  buttonQuit->setStyleSheet(pushButtonsStyle);
  buttonQuit->setFixedSize(300, 50);
  buttonQuit->move((width() - buttonQuit->width())/2,
                   (height() - buttonQuit->height())/2 + buttonQuit->height());
  connect(buttonQuit, SIGNAL(clicked()), SLOT(close()));
}

void MenuWindow::slotOpenSettings() noexcept {
  settings = new SettingsWindow{nullptr};
  settings->move(x(), y());
  close();
  settings->show();
}

void MenuWindow::slotOpenHelp() noexcept {
  help = new HelpWindow{this};
  help->show();
}
