#ifndef GO_GOGAME_H
#define GO_GOGAME_H

#include <iostream>
#include <string>
#include <sstream>

#include "../GoEngine/GoEngineInterface.h"
#include "InitBoards.h"

//TODO разобраться с constexpr

/**
 * Игра.
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

    GoEngineInterface*goEngineInterface; /**< Указатель на объект интерфейса движка*/

    /**
     * Настроить игру.
     */
    void configureGame();

    /**
     * Начать игровой процесс.
     */
    void play();

    /**
     * Запутить игровой цикл.
     */
    void startGameCycle( std::string& input, int& first, int& second, bool& isExit, bool& isIncorrectInput );

    /**
     * Парсить входную строку.
     * @param input строка.
     * @param first первая координата.
     * @param second вторая координата.
     * @param isIncorrectInput флаг корректности ввода.
     */
    void parseInput( const std::string& input, int& first, int& second, bool& isInputIncorrect ) const noexcept;

    /**
     * Парсить первую координату.
     * @param input строка.
     * @param first первая координата.
     * @param isIncorrectInput флаг корректности ввода.
     */
    void parseFirstCoordinate( const std::string& input, int& first, bool& isInputIncorrect ) const noexcept;

    /**
     * Парсить вторую координату.
     * @param input строка.
     * @param second первая координата.
     * @param isIncorrectInput флаг корректности ввода.
     */
    void parseSecondCoordinate( const std::string& input, int& second, bool& isInputIncorrect ) const noexcept;

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
     * Напечатать статистику съеденных камней.
     */
    void printEatenStonesStat() const noexcept;

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
     * Ввести ход.
     */
    void inputMove();

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
