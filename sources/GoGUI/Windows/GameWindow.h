#ifndef GO_GAMEWINDOW_H
#define GO_GAMEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QPalette>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

#include "MenuWindow.h"

class MenuWindow;
class BoardWidget;

class GameWindow : public QMainWindow {
 Q_OBJECT

 public:
  explicit GameWindow(const int boardSize = 19, QWidget *parent = nullptr) noexcept;
  ~GameWindow() noexcept;

 private:
  const int BOARD_DIAG;
  const QString pushButtonsStyle {
      "QPushButton "
          "{"
          " background: #00ffff; "
          " color: #0000cd; "
          " font-size: 25px; "
          " border: none; "
          "}"
          "QPushButton:pressed:focus "
          "{"
          " color: #000000;"
          "}"
          "QPushButton:hover"
          "{"
          " color: #ff1493; "
          "}"
  };

  QPixmap *background;
  QPalette *gamePalette;
  QPushButton *buttonReturnToMenu;
  QPushButton *buttonPass;
  QPushButton *buttonSurrender;

  BoardWidget *board;
  MenuWindow *menu;

  QString whoseMove{QObject::tr("Black's move")};

 protected:
  void mousePressEvent(QMouseEvent *mouseEvent) override;
  void update() noexcept;

  void configureGamePalette() noexcept;
  void configureButtons() noexcept;
  void configureButtonReturnToMenu() noexcept;
  void configureButtonPass() noexcept;
  void configureButtonSurrender() noexcept;
  void configureStatusBar() noexcept;

 signals:

 private slots:
  void slotReturnToMenu() noexcept;
  void slotPass() noexcept;
  void slotSurrender() noexcept;
};


#endif //GO_GAMEWINDOW_H
