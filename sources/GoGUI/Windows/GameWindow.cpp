#include "GameWindow.h"

GameWindow::GameWindow(const int boardSize, QWidget *parent) noexcept : QWidget{parent, Qt::WindowCloseButtonHint |
                                                                            Qt::WindowMinimizeButtonHint},
                                                            boardSize{boardSize},
                                                            background{new QPixmap{":/menu_background.jpg"}},
                                                            gamePalette{new QPalette},
                                                            buttonReturnToMenu{new QPushButton{this}},
                                                            buttonPass{new QPushButton{this}},
                                                            buttonSurrender{new QPushButton{this}},
                                                            go{nullptr},
                                                            menu{nullptr} {
  configureGamePalette();
  configureButtons();
  configureGo();
}

void GameWindow::configureGamePalette() noexcept {
  setFixedSize(background->width(), background->height());
  gamePalette->setBrush(backgroundRole(), QBrush{*background});
  setPalette(*gamePalette);
}

void GameWindow::configureButtons() noexcept {
  configureButtonReturnToMenu();
  configureButtonPass();
  configureButtonSurrender();
}

void GameWindow::configureButtonReturnToMenu() noexcept {
  buttonReturnToMenu->setText(QObject::tr("Return to menu"));
  buttonReturnToMenu->move(5, (height() - buttonReturnToMenu->height())/2 - buttonReturnToMenu->height() );
  connect(buttonReturnToMenu, SIGNAL(clicked()), SLOT(slotReturnToMenu()));
}

void GameWindow::configureButtonPass() noexcept {
  buttonPass->setText(QObject::tr("Pass"));
  buttonPass->move(5, (height() - buttonPass->height())/2);
  connect(buttonPass, SIGNAL(clicked()), SLOT(slotPass()));
}

void GameWindow::configureButtonSurrender() noexcept {
  buttonSurrender->setText(QObject::tr("Surrender"));
  buttonSurrender->move(5, (height() - buttonSurrender->height())/2 + buttonSurrender->height());
  connect(buttonSurrender, SIGNAL(clicked()), SLOT(slotSurrender()));
}

void GameWindow::configureStatusBar() noexcept {

}

void GameWindow::configureGo() noexcept {
  go = new GoEngineAPI;
  go->startGame(boardSize, JAPANESE, NIGIRI);
}

void GameWindow::slotReturnToMenu() noexcept {
  menu = new MenuWindow{nullptr};
  menu->move(x(), y());
  close();
  menu->show();
}

void GameWindow::slotPass() noexcept {
  go->pass();
  qDebug() << "Move is passed: " << !go->getLastMove().isNotPass();
  qDebug() << "GameWindow is over: " << go->isGameOver();
}

void GameWindow::slotSurrender() noexcept {
  go->surrender();
  qDebug() << "Surrendered: " << static_cast<int>(go->whoSurrendered());
  qDebug() << "Winner: " << static_cast<int>(go->whoWon());
}

