#ifndef GO_GAME_H
#define GO_GAME_H

#include <QWidget>
#include <QMessageBox>
#include <QPalette>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRect>

#include "Board.h"

#include "../../GoEngine/GoEngineAPI.h"

class Game : public QWidget {
 Q_OBJECT

 public:
  explicit Game(QWidget *parent = nullptr) noexcept;

 private:
  QPalette *gamePalette;

  GoEngineAPI *engine;


 signals:

 private slots:

};


#endif //GO_GAME_H
