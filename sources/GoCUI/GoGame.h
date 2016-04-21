#ifndef GO_GOGAME_H
#define GO_GOGAME_H

#include <iostream>
#include <string>
#include <sstream>

#include "../GoEngine/GoEngineInterface.h"

/**
 * Класс, отвечающий за
 */
class GoGame
{
public:

    /**
     * Конструктор
     */
    GoGame();

    /**
     * Деструктор
     */
    ~GoGame();

    /**
     * Начать игру
     * Этот метод объединяет методы данного класса, отвечающие за организацию игрового процесса.
     */
    void begin();

private:

    /**
     * Указатель на объект интерфейса, предоставляемого движком приложению
     */
    GoEngineInterface*goEngineInterface;

    /**
     * Напечатать, чей ход.
     */
    void printWhoseMove() const;

    /**
     * Напечатать, сколько камней съели чёрные.
     */
    void printStonesEatenByBlack() const noexcept;

    /**
     * Напечатать, сколько камней съели белые.
     */
    void printStonesEatenByWhite() const noexcept;

    /**
     * Отрисовать текущее состояние доски.
     */
    void printBoard();

    /**
     * Ввести диагональ.
     * @param diagonal диагональ.
     */
    void inputDiagonal( int& diagonal );

    /**
     * Ввести координаты.
     */
    void inputCoordinates();

    /**
     * Вывести сообщение ввода диагонали.
     */
    void printDiagonalInputMessage();

    /**
     * Диагональ - n?
     * @param n значение диагонали.
     * @param input входная строка.
     * @return true, если да, и false, если нет.
     */
    bool isDiagonalN( const int n, const std::string& input ) const noexcept;

    /**
     * Диагональ корректна?
     * @param input входная строка.
     * @return true, если корректна, и false, если нет.
     */
    bool isDiagonalCorrect( const std::string& input ) const noexcept;

    /**
     * Получить диагональ.
     * @param input входная строка.
     * @return диагональ.
     */
    int getDiagonal( const std::string& input ) const noexcept;

    /**
     * Ключ exit?
     * @param input входная строка.
     * @return true, если введен ключ exit, и false - иначе.
     */
    bool isExit( const std::string& input ) const noexcept;

    //TODO
    /**
     * Завершить программу.
     */
    void exit() const noexcept;

};

#endif //GO_GOGAME_H
