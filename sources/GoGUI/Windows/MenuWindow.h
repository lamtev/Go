#ifndef GO_MENUWINDOW_H
#define GO_MENUWINDOW_H

#include <QPushButton>
#include <QMainWindow>

#include "GameWindow.h"
#include "SettingsWindow.h"
#include "HelpWindow.h"

class SettingsWindow;

class MenuWindow : public QMainWindow {
 Q_OBJECT

 public:
  explicit MenuWindow(QMainWindow *parent = nullptr) noexcept;

 private:
  QPalette *menuPalette;
  QPushButton *buttonStartGame;
  QPushButton *buttonHelp;
  QPushButton *buttonQuit;

  SettingsWindow *settings;
  HelpWindow *help;

  void configurePalette() noexcept;
  void configureButtons() noexcept;
  void configureButtonStartGame() noexcept;
  void configureButtonHelp() noexcept;
  void configureButtonQuit() noexcept;


 signals:

 private slots:
  void slotOpenSettings() noexcept;
  void slotOpenHelp() noexcept;

};

#endif //GO_MENUWINDOW_H
