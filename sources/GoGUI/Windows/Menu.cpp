#include "Menu.h"

Menu::Menu(QMainWindow *parent) noexcept : QMainWindow{parent},
                                           menuPalette{new QPalette},
                                           buttonStartGame{new QPushButton{QObject::tr("Start game"), this}},
                                           buttonHelp{new QPushButton{QObject::tr("Help"), this}},
                                           buttonQuit{new QPushButton{QObject::tr("Quit"), this}},
                                           settings{nullptr},
                                           help{nullptr} {
  setFixedSize(QPixmap{":/menu_background.jpg"}.size());
//  setGeometry(QPixmap{":/menu_background.jpg"}.rect());
  configurePalette();
  configureButtons();
}

void Menu::configurePalette() noexcept {
  menuPalette->setBrush(backgroundRole(), QBrush{QPixmap{":/menu_background.jpg"}});
  setPalette(*menuPalette);
}

void Menu::configureButtons() noexcept {
  configureButtonStartGame();
  configureButtonHelp();
  configureButtonQuit();
}

void Menu::configureButtonStartGame() noexcept {
  buttonStartGame->move((width() - buttonStartGame->width())/2,
                       (height() - buttonStartGame->height())/2 - buttonStartGame->height());
  connect(buttonStartGame, SIGNAL(clicked()), SLOT(slotOpenSettings()));
}

void Menu::configureButtonHelp() noexcept {
  buttonHelp->move((width() - buttonHelp->width())/2,
                   (height() - buttonHelp->height())/2);
  connect(buttonHelp, SIGNAL(clicked()), SLOT(slotOpenHelp()));
}

void Menu::configureButtonQuit() noexcept {
  buttonQuit->move((width() - buttonQuit->width())/2,
                   (height() - buttonQuit->height())/2 + buttonQuit->height());
  connect(buttonQuit, SIGNAL(clicked()), SLOT(close()));
}

void Menu::slotOpenSettings() noexcept {
  settings = new Settings{nullptr};
  settings->move((width() - settings->width())/2,
             (height() - settings->height())/2);
  close();
  settings->show();
}

void Menu::slotOpenHelp() noexcept {
  help = new Help{this};
  help->show();
}
