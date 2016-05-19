#ifndef GO_MENU_H
#define GO_MENU_H

#include <QtWidgets>
#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <QVBoxLayout>
#include <QGridLayout>
//#include <QRect>


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

  void connectSignals() const noexcept;

 signals:

 private slots:
  void startGame(){};
  void openSettings(){};
  void openHelp(){};

};


#endif //GO_MENU_H
