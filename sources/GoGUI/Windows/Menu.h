#ifndef GO_MENU_H
#define GO_MENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "Game.h"
#include "Settings.h"
#include "Help.h"

class Menu : public QWidget {
  Q_OBJECT

 public:
  explicit Menu(QWidget *parent = nullptr) noexcept;

 private:
  QPalette *menuPalette;
  QVBoxLayout *vLayout;
  QPushButton *buttonStartGame;
  QPushButton *buttonSettings;
  QPushButton *buttonHelp;
  QPushButton *buttonQuit;

  Game *game;
  Settings *settings;
  Help *help;

  void configurePalette() noexcept;
  void configureVLayout() noexcept;
  void configureButtons() noexcept;
  void configureButtonStartGame() noexcept;
  void configureButtonSettings() noexcept;
  void configureButtonHelp() noexcept;
  void configureButtonQuit() noexcept;


 signals:

 private slots:
  void slotOpenGame() noexcept;
  void slotOpenSettings() noexcept;
  void slotOpenHelp() noexcept;

};

#endif //GO_MENU_H
