#include <Windows/Widgets/BoardWidget.h>
#include "GameWindow.h"

GameWindow::GameWindow(const int boardSize, QWidget *parent) noexcept :
                                                            QWidget{parent, Qt::WindowCloseButtonHint |
                                                                            Qt::WindowMinimizeButtonHint},
                                                            BOARD_DIAG{boardSize},
                                                            background{new QPixmap{":/menu_background.jpg"}},
                                                            gamePalette{new QPalette},
                                                            buttonReturnToMenu{new QPushButton{this}},
                                                            buttonPass{new QPushButton{this}},
                                                            buttonSurrender{new QPushButton{this}},
                                                            board{new BoardWidget{boardSize, this}},
                                                            menu{nullptr} {
  configureGamePalette();
  configureButtons();
  board->move(300, 20);
}

GameWindow::~GameWindow() noexcept {
  delete board;
}

void GameWindow::update() noexcept {
  switch (board->getGo()->whoseMove())
  {
    case Status::BLACK :
      whoseMove = QObject::tr("Black's move");
      break;
    case Status::WHITE :
      whoseMove = QObject::tr("White's move");
      break;
    default :
      whoseMove = QObject::tr("Game is over");
      break;
  }
  QWidget::update();
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

void GameWindow::slotReturnToMenu() noexcept {
  menu = new MenuWindow{nullptr};
  menu->move(x(), y());
  close();
  menu->show();
}

void GameWindow::slotPass() noexcept {
  board->getGo()->pass();
  QMessageBox twoPassesMessageBox;
  if (board->getGo()->isGameOver()) {
    QString gameIsOver{QObject::tr("Game is over")};
    QString calculateYourScores{QObject::tr("Now calculate your scores.")};
    twoPassesMessageBox.setText(gameIsOver + "\n" + calculateYourScores);
    twoPassesMessageBox.show();
    twoPassesMessageBox.exec();
  }
}

void GameWindow::slotSurrender() noexcept {
  board->getGo()->surrender();
  QMessageBox surrenderMessageBox;
  QString surrendered;
  QString winner;
  switch (board->getGo()->whoSurrendered()) {
    case Status::BLACK :
      surrendered = QObject::tr("Black player");
      winner = QObject::tr("White player");
      break;
    default :
      surrendered = QObject::tr("White player");
      winner = QObject::tr("Black player");
      break;
  }
  QString gameIsOver{QObject::tr("Game is over")};
  QString hasSurrendered{QObject::tr(" has surrendered.")};
  QString hasWon{QObject::tr(" has won!!!")};
  surrenderMessageBox.setText(gameIsOver + "\n" + surrendered + hasSurrendered + "\n" + winner + hasWon);
  surrenderMessageBox.show();
  surrenderMessageBox.exec();
  close();
}




