#include "Menu.h"

Menu::Menu(QWidget *parent) noexcept : QWidget{parent},
                                       palette{new QPalette},
                                       vLayout{new QVBoxLayout{this}},
                                       btnStartGame{new QPushButton{tr("Start game"), this}},
                                       btnSettings{new QPushButton{tr("Settings"), this}},
                                       btnHelp{new QPushButton{tr("Help"), this}},
                                       btnQuit{new QPushButton{tr("Quit"), this}},
                                       game{Q_NULLPTR},
                                       settings{Q_NULLPTR},
                                       help{Q_NULLPTR} {

  setGeometry(QPixmap{":/smile1.jpg"}.rect());
  configurePalette();
  configureVLayout();
  configureButtons();
  connectSignals();
}

void Menu::connectSignals() const noexcept {
  connect(btnStartGame, SIGNAL(clicked()), SLOT(slotOpenGame()));
  connect(btnSettings, SIGNAL(clicked()), SLOT(slotOpenSettings()));
  connect(btnHelp, SIGNAL(clicked()), SLOT(slotOpenHelp()));
  connect(btnQuit, SIGNAL(clicked()), SLOT(close()));
}

void Menu::configurePalette() noexcept {
  palette->setBrush(backgroundRole(), QBrush{QPixmap{":/smile1.jpg"}});
  setPalette(*palette);
}

void Menu::configureVLayout() noexcept {
  vLayout->setMargin(5);
  vLayout->setSpacing(1);
  vLayout->addWidget(btnStartGame, 0);
  vLayout->addWidget(btnSettings, 1);
  vLayout->addWidget(btnHelp, 2);
  vLayout->addWidget(btnQuit, 3);
  setLayout(vLayout);
}

void Menu::configureButtons() noexcept {}

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
