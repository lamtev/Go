#ifndef GO_MENU_H
#define GO_MENU_H

#include <QtWidgets>
#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <QVBoxLayout>
#include <QGridLayout>

#include "Game.h"
#include "Settings.h"
#include "Help.h"

class Menu : public QWidget {
  Q_OBJECT

 public:
  explicit Menu(QWidget *parent = Q_NULLPTR) noexcept;

 private:
  QPalette *palette;
  QVBoxLayout *vLayout;
  QPushButton *btnStartGame;
  QPushButton *btnSettings;
  QPushButton *btnHelp;
  QPushButton *btnQuit;

  Game *game;
  Settings *settings;
  Help *help;

  void configurePalette() noexcept;
  void configureVLayout() noexcept;
  void configureButtons() noexcept;

  void connectSignals() const noexcept;

 signals:

 private slots:
  void slotOpenGame() noexcept;
  void slotOpenSettings() noexcept;
  void slotOpenHelp() noexcept;

};

#endif //GO_MENU_H
