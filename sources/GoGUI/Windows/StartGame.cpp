#include "StartGame.h"

StartGame::StartGame(QWidget *parent) noexcept : QWidget{parent},
                                                 vLayout{new QVBoxLayout{this}},
                                                 gLayout{new QGridLayout{this}},
                                                 text{new QLabel{QObject::tr("Chose board size"), this}},
                                                 rButton19x19{new QRadioButton{QObject::tr("19 x 19"), this}},
                                                 rButton13x13{new QRadioButton{QObject::tr("13 x 13"), this}},
                                                 rButton7x7{new QRadioButton{QObject::tr(" 7 x 7"), this}},
                                                 buttonStartGame{new QPushButton{QObject::tr("Start game"), this}},
                                                 buttonCancel{new QPushButton{QObject::tr("Cancel"), this}},
                                                 game{nullptr} {
  qDebug() << "vLayout->parent() " << vLayout->parent();
  configureButtons();
  configureGLayout();
  configureVLayout();
}

void StartGame::configureVLayout() noexcept {
  vLayout->setMargin(5);
  vLayout->setSpacing(1);
  vLayout->addWidget(text, 0);
  vLayout->addWidget(rButton19x19, 1);
  vLayout->addWidget(rButton13x13, 2);
  vLayout->addWidget(rButton7x7, 3);
  vLayout->addLayout(gLayout);
  setLayout(vLayout);
}

void StartGame::configureGLayout() noexcept {
  gLayout->addWidget(buttonCancel, 0, 0);
  gLayout->addWidget(buttonStartGame, 0, 1);

}

void StartGame::configureButtons() noexcept {
  configureRButton19x19();
  configureRButton13x13();
  configureRButton7x7();
  configureButtonStartGame();
  configureButtonCancel();
}

void StartGame::configureRButton19x19() noexcept {
  rButton19x19->setChecked(true);
}

void StartGame::configureRButton13x13() noexcept {

}

void StartGame::configureRButton7x7() noexcept {

}

void StartGame::configureButtonStartGame() noexcept {
  connect(buttonStartGame, SIGNAL(clicked()), SLOT(slotStartGame()));
}

void StartGame::configureButtonCancel() noexcept {
  connect(buttonCancel, SIGNAL(clicked()), SLOT(close()));
}

void StartGame::slotStartGame() noexcept {
  close();
  game = new Game{this};
  game->move((width() - game->width())/2, (height() - game->height())/2);
  game->show();
}
