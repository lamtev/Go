#ifndef GO_GAMEWINDOW_H
#define GO_GAMEWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QPalette>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

#include "MenuWindow.h"

#include "../../GoEngine/GoEngineAPI.h"

class MenuWindow;

class GameWindow : public QWidget {
 Q_OBJECT

 public:
  explicit GameWindow(const int boardSize = 19, QWidget *parent = nullptr) noexcept;

 private:
  const int boardSize;

  QPixmap *background;
  QPalette *gamePalette;
  QPushButton *buttonReturnToMenu;
  QPushButton *buttonPass;
  QPushButton *buttonSurrender;

  GoEngineAPI *go;
  MenuWindow *menu;

  void configureGamePalette() noexcept;
  void configureButtons() noexcept;
  void configureButtonReturnToMenu() noexcept;
  void configureButtonPass() noexcept;
  void configureButtonSurrender() noexcept;
  void configureStatusBar() noexcept;
  void configureGo() noexcept;

 signals:

 private slots:
  void slotReturnToMenu() noexcept;
  void slotPass() noexcept;
  void slotSurrender() noexcept;
};


#endif //GO_GAMEWINDOW_H
