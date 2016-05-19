#ifndef GO_MENU_H
#define GO_MENU_H

#include <QtWidgets>
#include <QMainWindow>
#include <QPushButton>
#include <QMenu>


class Menu : public QMainWindow {
  Q_OBJECT

 public:
  explicit Menu(QWidget *parent = nullptr) noexcept;

 private:
  QPushButton *btnStartGame = new QPushButton{tr("Start game")};
  QPushButton *btnSettings = new QPushButton{tr("Settings")};
  QPushButton *btnHelp = new QPushButton{tr("Help")};
  QPushButton *btnQuit = new QPushButton{tr("Quit")};

 signals:

 private slots:
};


#endif //GO_MENU_H
