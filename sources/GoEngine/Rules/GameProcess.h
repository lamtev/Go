#ifndef GO_GAMEPROCESS_H
#define GO_GAMEPROCESS_H

#include "../Model/Board.h"
#include "Move.h"
#include "Exceptions/MoveOutsideTheBoardException.h"
#include "Exceptions/MoveRepeatException.h"
#include "Exceptions/MoveToDieException.h"
#include "Exceptions/MoveToNotEmtyPointException.h"

//TODO усовершенствовать съедение

/**
 * Игровой процесс.
 * Cледит за тем, чтобы ходы выполнялись в соответствии с правилами.
 * Определяет очерёдность ходов. Определяет победителя и проигравшего.
 */
class GameProcess {

 public:

  /**
   * Конструктор.
   */
  explicit GameProcess(const int diagonal) noexcept;


  /**
   * Деструктор.
   */
  ~GameProcess() noexcept;

  /**
   * Положить камень.
   * @param first первая координата
   * @param second вторая координата
   */
  void putStone(int first, int second);

  /**
   * Пропустить ход.
   */
  void pass() noexcept;

  /**
   * Сдаться.
   */
  void surrender() noexcept;

  /**
   * Игра закончена?
   * @return true, если игра закончилась, и false - в противном случае
   */
  bool isGameOver() const noexcept;

  /**
   * Кто сдался?
   * @return цвет сдавшегося.
   */
  Status whoSurrendered() const noexcept;

  /**
   * Кто победил?
   * @return цвет победителя.
   */
  Status whoWon() const noexcept;

  /**
   * Получить номер текущего хода.
   * @return номер текущего хода
   */
  int getMoveIndex() const noexcept;

  /**
   * Получить вектор всех ходов.
   * @return вектор всех ходов
   */
  std::vector<Move> &getMoves() const noexcept;

  /**
   * Получить последний совершённый ход.
   * @return ссылка на последний совершённый ход.
   */
  Move &getLastMove() const noexcept;

  /**
   * Получить предпоследний совершённых ход.
   * @return ссылка на последний совершённый ход
   */
  Move &getPenultMove() const noexcept;

  /**
   * Получить число камней, съеденных чёрным.
   * @return число камней, съеденных чёрным
   */
  int getStonesEatenByBlack() const noexcept;

  /**
   * Получить число камней, съеденных белым.
   * @return число камней, съеденных белым
   */
  int getStonesEatenByWhite() const noexcept;

  /**
   * Получить доску.
   * @return доску
   */
  Board &getBoard() const noexcept;

  /**
   * Чей ход.
   * @return чей ход.
   */
  Status whoseMove() const noexcept;

 private:

  int diagonal;
  /**< Диагональ доски */
  Board *board;
  /**< Доска */
  int walketh;
  /**< Ходящий игрок */
  std::vector<Move> moves;
  /**< Вектор, хранящий все ходы */
  Status surrendered;
  /**< Сдавшийся */
  Status winner;
  /**< Победитель */
  int stonesEatenByBlack; /**< Число камней, съеденных чёрным */
  int stonesEatenByWhite; /**< Число камней, съеденных белым */
  const Move passedMove{PASS_COORD, PASS_COORD}; /**< Пропущенный ход */
  std::vector<Point *> pointsWithEatenStones; /**< Вектор указателей на пункты со съеденными камнями */

  /**
   * Определить съеденные камни.
   */
  void determineEatenStones() noexcept;

  /**
   * Убрать с доски съеденные камни.
   */
  void deleteEatenStones() noexcept;

  /**
   * Камень может быть съеден?
   * @param first первая координата
   * @param second вторая координата
   * @return true, если камень может быть съеден, и false, если нет
   */
  bool couldStoneBeEaten(int first, int second) const noexcept;

  /**
   * Ход под смерть?
   * @param first первая координата
   * @param second вторая координата
   * @return true, если ход под смерть, и false, если нет
   */
  bool isMoveToDie(int first, int second) const noexcept;

  /**
   * Обновить ходящего
   */
  void updateWalketh() noexcept;

  /**
   * Проверка двух последних ходов на пропуск.
   * @return true, если оба игрока пропустили поочередно ход, false - в противном случае
   */
  bool areTwoPasses() const noexcept;

  /**
   * Если ход за пределы доски, бросить исключение.
   * Данная функция-член выбрасывает исключение, если игрок совершает ход за пределы доски.
   * @param first первая координата
   * @param second вторая координата
   */
  void ifMoveOutsideTheBoardThrowException(int first, int second) const;

  /**
   * Если ход в занятый пункт, бросить исключение.
   * Данная функция-член выбрасывает исключение, если игрок совершает ход в уже занятый пункт.
   * @param first первая координата
   * @param second вторая координата
   */
  void ifMoveToNotEmptyPointThrowException(int first, int second) const;

  /**
   * Если повтор хода, бросить исключение.
   * Данный метод выбрасывает исключение, если игрок повторил свой предыдущий ход
   * @param first первая координата
   * @param second вторая координата
   */
  void ifMoveRepeatThrowException(int first, int second) const;

  /**
   * Если ход под смерть, бросить исключение.
   * Данный метод выбрасывает исключение, если ход совершается под смерть
   * @param first первая координата
   * @param second вторая координата
   */
  void ifMoveToDieThrowException(int first, int second) const;

  /**
   * Если ход неверен, бросить исключение.
   * @param first первая координата
   * @param second вторая координата
   */
  void ifMoveIllegalThrowException(int first, int second) const;

};


#endif //GO_GAMEPROCESS_H
