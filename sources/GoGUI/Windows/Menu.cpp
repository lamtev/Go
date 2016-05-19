#include "Menu.h"

Menu::Menu(QWidget *parent) noexcept : QWidget{parent},
                                       palette{new QPalette},
                                       vLayout{new QVBoxLayout{this}},
                                       btnStartGame{new QPushButton{tr("Start game"), this}},
                                       btnSettings{new QPushButton{tr("Settings"), this}},
                                       btnHelp{new QPushButton{tr("Help"), this}},
                                       btnQuit{new QPushButton{tr("Quit"), this}} {

  setGeometry(QPixmap{":/smile1.jpg"}.rect());

  palette->setBrush(backgroundRole(), QBrush{QPixmap{":/smile1.jpg"}});
  setPalette(*palette);

  vLayout->setMargin(5);
  vLayout->setSpacing(1);
  vLayout->addWidget(btnStartGame,0);
  vLayout->addWidget(btnSettings, 1);
  vLayout->addWidget(btnHelp, 2);
  vLayout->addWidget(btnQuit, 3);
  setLayout(vLayout);
  connectSignals();
}

void Menu::connectSignals() const noexcept {
  connect(btnQuit, SIGNAL(clicked()), SLOT(close()));
}



