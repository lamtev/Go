#include "Menu.h"

Menu::Menu(QWidget *parent) noexcept : QWidget{parent},
                                       menuPalette{new QPalette},
                                       vLayout{new QVBoxLayout{this}},
                                       buttonStartGame{new QPushButton{QObject::tr("Start game"), this}},
                                       buttonSettings{new QPushButton{QObject::tr("Settings"), this}},
                                       buttonHelp{new QPushButton{QObject::tr("Help"), this}},
                                       buttonQuit{new QPushButton{QObject::tr("Quit"), this}},
                                       startGame{nullptr},
                                       settings{nullptr},
                                       help{nullptr} {
  setGeometry(QPixmap{":/menu_background.jpg"}.rect());
  configurePalette();
  configureButtons();
  configureVLayout();
}

void Menu::configurePalette() noexcept {
  menuPalette->setBrush(backgroundRole(), QBrush{QPixmap{":/menu_background.jpg"}});
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
  connect(buttonStartGame, SIGNAL(clicked()), SLOT(slotOpenStartGame()));
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

void Menu::slotOpenStartGame() noexcept {
  startGame = new StartGame;
  startGame->move((QApplication::desktop()->width() - startGame->width())/2,
                  (QApplication::desktop()->height() - startGame->height())/2);
  startGame->setAttribute(Qt::WA_DeleteOnClose);
  startGame->show();
  qDebug() << "startGame->parent() " << startGame->parent();
}

void Menu::slotOpenSettings() noexcept {
  settings = new Settings{this};
  settings->show();
}

void Menu::slotOpenHelp() noexcept {
  help = new Help{this};
  help->show();
}

