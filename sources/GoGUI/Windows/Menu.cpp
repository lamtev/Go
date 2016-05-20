#include "Menu.h"

Menu::Menu(QWidget *parent) noexcept : QWidget{parent},
                                       menuPalette{new QPalette},
                                       vLayout{new QVBoxLayout{this}},
                                       buttonStartGame{new QPushButton{tr("Start game"), this}},
                                       buttonSettings{new QPushButton{tr("Settings"), this}},
                                       buttonHelp{new QPushButton{tr("Help"), this}},
                                       buttonQuit{new QPushButton{tr("Quit"), this}},
                                       game{nullptr},
                                       settings{nullptr},
                                       help{nullptr} {
  setGeometry(QPixmap{":/smile.jpg"}.rect());
  configurePalette();
  configureVLayout();
  configureButtons();
}

void Menu::configurePalette() noexcept {
  menuPalette->setBrush(backgroundRole(), QBrush{QPixmap{":/smile.jpg"}});
  setPalette(*menuPalette);
}

void Menu::configureVLayout() noexcept {
  vLayout->setMargin(5);
  vLayout->setSpacing(1);
  vLayout->addWidget(buttonStartGame, 0);
  vLayout->addWidget(buttonSettings, 1);
  vLayout->addWidget(buttonHelp, 2);
  vLayout->addWidget(buttonQuit, 3);
  setLayout(vLayout);
}

void Menu::configureButtons() noexcept {
  configureButtonStartGame();
  configureButtonSettings();
  configureButtonHelp();
  configureButtonQuit();
}

void Menu::configureButtonStartGame() noexcept {
  connect(buttonStartGame, SIGNAL(clicked()), SLOT(slotOpenGame()));
}

void Menu::configureButtonSettings() noexcept {
  connect(buttonSettings, SIGNAL(clicked()), SLOT(slotOpenSettings()));
}

void Menu::configureButtonHelp() noexcept {
  connect(buttonHelp, SIGNAL(clicked()), SLOT(slotOpenHelp()));
}

void Menu::configureButtonQuit() noexcept {
  connect(buttonQuit, SIGNAL(clicked()), SLOT(close()));
}

void Menu::slotOpenGame() noexcept {
  game = new Game{this};
  game->show();
}

void Menu::slotOpenSettings() noexcept {
  settings = new Settings{this};
  settings->show();
}

void Menu::slotOpenHelp() noexcept {
  help = new Help{this};
  help->show();
}
