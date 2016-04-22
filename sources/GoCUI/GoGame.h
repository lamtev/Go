#ifndef GO_GOGAME_H
#define GO_GOGAME_H

#include <iostream>
#include <string>
#include <sstream>

#include "../GoEngine/GoEngineInterface.h"
#include "InitBoards.h"
#include "enums.h"

//TODO разобраться с constexpr
//TODO refactor GoGame

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
    void startGameCycle( std::string& command, int& first, int& second, bool& isExit, bool& isCommandIncorrect );

    /**
     * Парсить входную строку.
     * @param input строка.
     * @param first первая координата.
     * @param second вторая координата.
     * @param isIncorrectInput флаг корректности ввода.
     * @return тип распарсенной команды
     */
    int parseCommand( const std::string& command, int& first, int& second, bool& isCommandIncorrect ) const noexcept;

    /**
     * Парсить первую координату.
     * @param input строка.
     * @param first первая координата.
     * @param isIncorrectInput флаг корректности ввода.
     */
    void parseFirstCoordinate( const std::string& command, int& first, bool& isCommandIncorrect ) const noexcept;

    /**
     * Парсить вторую координату.
     * @param input строка.
     * @param second первая координата.
     * @param isIncorrectInput флаг корректности ввода.
     */
    void parseSecondCoordinate( const std::string& command, int& second, bool& isCommandIncorrect ) const noexcept;

    /**
     * Напечатать, что команда не верна.
     * Если это нужно, напечатать, что предыдущая введенная команда неверна.
     */
    void ifNeedPrintCommandIncorrect( bool& isCommandIncorrect ) const noexcept;

    /**
     * Напечатать, что команда была введена нверно.
     */
    void printUnknownCommand() const noexcept;

    /**
     * Выбрать распарсенную команду
     */
    void switchParsedCommand( const std::string& command, int& first, int& second, bool& isCommandIncorrect, bool& isExit );

    /**
     * Сделать ход.
     */
    void putStone( const int first, const int second );

    /**
     * Пропустить ход.
     */
    void pass() const noexcept;

    /**
     * Cдаться.
     */
    void surrender() const noexcept;

    /**
     * Кто сдался?
     */
    int whoSurrendered() const noexcept;

    /**
     * Выбрать сдавшегося.
     */
    void switchWhoSurrendered() const noexcept;

    /**
     * Напечатать, чей ход.
     */
    void printWhoseMove() const noexcept;

    /**
     * Напечатать, что черный сдался.
     */
    void printBlackSurrendered() const noexcept;

    /**
     * Напечатать, что белый сдался.
     */
    void printWhiteSurrendered() const noexcept;

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
