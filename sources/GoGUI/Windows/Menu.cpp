#include "Menu.h"

Menu::Menu(QMainWindow *parent) noexcept : QMainWindow{parent},
                                           menuPalette{new QPalette},
                                           buttonStartGame{new QPushButton{QObject::tr("Start game"), this}},
                                           buttonSettings{new QPushButton{QObject::tr("Settings"), this}},
                                           buttonHelp{new QPushButton{QObject::tr("Help"), this}},
                                           buttonQuit{new QPushButton{QObject::tr("Quit"), this}},
                                           game{nullptr},
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
  configureButtonSettings();
  configureButtonHelp();
  configureButtonQuit();
}

void Menu::configureButtonStartGame() noexcept {
  buttonStartGame->move((width() - buttonStartGame->width())/2,
                   (height() - buttonStartGame->height())/2 - 3*buttonStartGame->height()/2);
  connect(buttonStartGame, SIGNAL(clicked()), SLOT(slotOpenGame()));
}

void Menu::configureButtonSettings() noexcept {
  buttonSettings->move((width() - buttonSettings->width())/2,
                   (height() - buttonSettings->height())/2 - buttonSettings->height()/2);
  connect(buttonSettings, SIGNAL(clicked()), SLOT(slotOpenSettings()));
}

void Menu::configureButtonHelp() noexcept {
  buttonHelp->move((width() - buttonHelp->width())/2,
                   (height() - buttonHelp->height())/2 + buttonHelp->height()/2);
  connect(buttonHelp, SIGNAL(clicked()), SLOT(slotOpenHelp()));
}

void Menu::configureButtonQuit() noexcept {
  buttonQuit->move((width() - buttonQuit->width())/2,
                   (height() - buttonQuit->height())/2 + 3*buttonQuit->height()/2);
  connect(buttonQuit, SIGNAL(clicked()), SLOT(close()));
}

void Menu::slotOpenGame() noexcept {
  game = new Game{nullptr};
  game->setAttribute(Qt::WA_DeleteOnClose);
  game->move(x(), y());
  close();
  game->show();
}

void Menu::slotOpenSettings() noexcept {
  settings = new Settings{this};
  settings->move(x(), y());
  settings->show();
}

void Menu::slotOpenHelp() noexcept {
  help = new Help{this};
  help->show();
}
