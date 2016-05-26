#ifndef GO_SETTINGSWINDOW_H
#define GO_SETTINGSWINDOW_H

#include <QWidget>
#include <QTabWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QPushButton>

#include "GameWindow.h"
#include "MenuWindow.h"

class MenuWindow;
class GameWindow;

class SettingsWindow : public QWidget {
 Q_OBJECT

 public:
  explicit SettingsWindow(QWidget *parent = nullptr) noexcept;

 private:
  QPixmap *background;
  QPalette *settingsPalette;
  QLabel *text;
  QRadioButton *rButton19x19;
  QRadioButton *rButton13x13;
  QRadioButton *rButton7x7;
  QPushButton *buttonStartGame;
  QPushButton *buttonReturnToMenu;
  QPushButton *buttonQuit;

  int boardSize;

  GameWindow *game;
  MenuWindow *menu;

  void configureSettingsPalette() noexcept;
  void configureText() noexcept;
  void configureButtons() noexcept;
  void configureRButton19x19() noexcept;
  void configureRButton13x13() noexcept;
  void configureRButton7x7() noexcept;
  void configureButtonStartGame() noexcept;
  void configureButtonReturnToMenu() noexcept;
  void configureButtonQuit() noexcept;
  void determineBoardSize() noexcept;

 signals:

 private slots:
  void slotOpenGame() noexcept;
  void slotReturnToMenu() noexcept;

};

#endif //GO_SETTINGSWINDOW_H
