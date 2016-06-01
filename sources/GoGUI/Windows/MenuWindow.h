#ifndef GO_MENUWINDOW_H
#define GO_MENUWINDOW_H

#include <QPushButton>
#include <QMainWindow>
#include <QColor>

#include "GameWindow.h"
#include "SettingsWindow.h"
#include "HelpWindow.h"

class SettingsWindow;

class MenuWindow : public QMainWindow {
 Q_OBJECT

 public:
  explicit MenuWindow(QMainWindow *parent = nullptr) noexcept;

 private:
  const QString pushButtonsStyle {
      "QPushButton "
          "{"
          " background: #000000; "
          " color: #ffffff; "
          " font-size: 25px; "
          "}"
          "QPushButton:pressed "
          "{"
          " color: #808080;"
          "}"
          "QPushButton:flat "
          "{"
          " border: none;"
          " background: #000000; "
          "}"};
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
