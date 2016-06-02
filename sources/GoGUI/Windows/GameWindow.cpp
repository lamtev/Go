#include <Windows/Widgets/BoardWidget.h>
#include "GameWindow.h"

GameWindow::GameWindow(const int boardSize, QWidget *parent) noexcept :
                                                            QMainWindow{parent, Qt::WindowCloseButtonHint |
                                                                            Qt::WindowMinimizeButtonHint},
                                                            BOARD_DIAG{boardSize},
                                                            background{new QPixmap{":/menu_background.jpg"}},
                                                            gamePalette{new QPalette},
                                                            stonesEatenByBlack{new QLabel{this}},
                                                            stonesEatenByWhite{new QLabel{this}},
                                                            buttonReturnToMenu{new QPushButton{this}},
                                                            buttonPass{new QPushButton{this}},
                                                            buttonSurrender{new QPushButton{this}},
                                                            board{new BoardWidget{boardSize, this}},
                                                            menu{nullptr} {
  configureGamePalette();
  configureButtons();
  board->move(300, 20);
  configureStatusBar();
  configureStonesEatenBy();
}

GameWindow::~GameWindow() noexcept {
  delete board;
}

void GameWindow::mousePressEvent(QMouseEvent *mouseEvent) {
  update();
  QWidget::mousePressEvent(mouseEvent);
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
      whoseMove = QObject::tr("Game is over.");
      break;
  }
  statusBar()->showMessage(whoseMove);
  configureStonesEatenBy();
  QWidget::update();
}

void GameWindow::configureGamePalette() noexcept {
  setFixedSize(background->width(), background->height());
  gamePalette->setColor(QPalette::Background, QColor{QRgb{0x00ffff}});
  setPalette(*gamePalette);
}

void GameWindow::configureStonesEatenBy() noexcept {
  std::string black;
  std::ostringstream oss;
  oss.str("");
  oss <<  board->getGo()->getStonesEatenByBlack();
  black = oss.str();
  QString STONES_EATEN_BY_BLACK{QObject::tr("Stones eaten by black:")};
  stonesEatenByBlack->setText(STONES_EATEN_BY_BLACK + " " + QString::fromStdString(black));
  stonesEatenByBlack->setStyleSheet(textStyle);
  stonesEatenByBlack->setFixedSize(350, 35);
  stonesEatenByBlack->move(rect().right() - 325,
                           (height() - stonesEatenByBlack->height())/2 - stonesEatenByBlack->height()/2);
  oss.str("");
  std::string white;
  oss <<  board->getGo()->getStonesEatenByWhite();
  white = oss.str();
  QString STONES_EATEN_BY_WHITE{QObject::tr("Stones eaten by white:")};
  stonesEatenByWhite->setText(STONES_EATEN_BY_WHITE + " " + QString::fromStdString(white));
  stonesEatenByWhite->setStyleSheet(textStyle);
  stonesEatenByWhite->setFixedSize(350, 35);
  stonesEatenByWhite->move(rect().right() - 325,
                           (height() - stonesEatenByWhite->height())/2 + stonesEatenByWhite->height()/2);
}

void GameWindow::configureButtons() noexcept {
  configureButtonReturnToMenu();
  configureButtonPass();
  configureButtonSurrender();
}

void GameWindow::configureButtonReturnToMenu() noexcept {
  buttonReturnToMenu->setText(QObject::tr("Return to menu"));
  buttonReturnToMenu->setStyleSheet(pushButtonsStyle);
  buttonReturnToMenu->setFixedSize(300, 50);
  buttonReturnToMenu->move(5, (height() - buttonReturnToMenu->height())/2 - buttonReturnToMenu->height() );
  connect(buttonReturnToMenu, SIGNAL(clicked()), SLOT(slotReturnToMenu()));
}

void GameWindow::configureButtonPass() noexcept {
  buttonPass->setText(QObject::tr("Pass"));
  buttonPass->setStyleSheet(pushButtonsStyle);
  buttonPass->setFixedSize(300, 50);
  buttonPass->move(5, (height() - buttonPass->height())/2);
  connect(buttonPass, SIGNAL(clicked()), SLOT(slotPass()));
}

void GameWindow::configureButtonSurrender() noexcept {
  buttonSurrender->setText(QObject::tr("Surrender"));
  buttonSurrender->setStyleSheet(pushButtonsStyle);
  buttonSurrender->setFixedSize(300, 50);
  buttonSurrender->move(5, (height() - buttonSurrender->height())/2 + buttonSurrender->height());
  connect(buttonSurrender, SIGNAL(clicked()), SLOT(slotSurrender()));
}

void GameWindow::configureStatusBar() noexcept {
  statusBar()->setFixedSize(300, 30);
  statusBar()->setStyleSheet("color: #0000cd;"
                             "font-size: 25px;");
  statusBar()->showMessage(whoseMove);
}

void GameWindow::slotReturnToMenu() noexcept {
  menu = new MenuWindow{nullptr};
  menu->move(x(), y());
  close();
  menu->show();
}

void GameWindow::slotPass() noexcept {
  board->getGo()->pass();
  update();
  QMessageBox twoPassesMessageBox;
  if (board->getGo()->isGameOver()) {
    QString gameIsOver{QObject::tr("Game is over.")};
    QString calculateYourScores{QObject::tr("Now calculate your scores.")};
    twoPassesMessageBox.setText(gameIsOver + "\n" + calculateYourScores);
    twoPassesMessageBox.show();
    twoPassesMessageBox.exec();
    board->setEnabled(false);
    buttonPass->setEnabled(false);
    buttonSurrender->setEnabled(false);
  }
}

void GameWindow::slotSurrender() noexcept {
  board->getGo()->surrender();
  update();
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
  QString gameIsOver{QObject::tr("Game is over.")};
  QString hasSurrendered{QObject::tr(" has surrendered.")};
  QString hasWon{QObject::tr(" has won!!!")};
  surrenderMessageBox.setText(gameIsOver + "\n" + surrendered + hasSurrendered + "\n" + winner + hasWon);
  surrenderMessageBox.show();
  surrenderMessageBox.exec();
  board->setEnabled(false);
  buttonPass->setEnabled(false);
  buttonSurrender->setEnabled(false);
}
