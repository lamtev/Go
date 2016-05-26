#ifndef GO_MENU_H
#define GO_MENU_H

#include <QPushButton>
#include <QMainWindow>

#include "Game.h"
#include "Settings.h"
#include "Help.h"

class Menu : public QMainWindow {
 Q_OBJECT

 public:
  explicit Menu(QMainWindow *parent = nullptr) noexcept;

 private:
  QPalette *menuPalette;
  QPushButton *buttonStartGame;
  QPushButton *buttonHelp;
  QPushButton *buttonQuit;

  Settings *settings;
  Help *help;

  void configurePalette() noexcept;
  void configureButtons() noexcept;
  void configureButtonStartGame() noexcept;
  void configureButtonHelp() noexcept;
  void configureButtonQuit() noexcept;


 signals:

 private slots:
  //void slotOpenGame() noexcept;
  void slotOpenSettings() noexcept;
  void slotOpenHelp() noexcept;

};

#endif //GO_MENU_H
