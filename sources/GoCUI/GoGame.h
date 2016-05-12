#ifndef GO_GOGAME_H
#define GO_GOGAME_H

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>

#include "../GoEngine/GoEngineAPI.h"
#include "Help.h"
#include "InitBoards.h"

//TODO point to function use
//TODO new parser

enum class TypeOfCommand
{
    ERROR = 4,
    EXIT,
    MOVE,
    PASS,
    SURRENDER,
    HELP,
    START_GAME
};

typedef bool (*pfunc)( const std::string& );

const std::map<std::string, int> MENU_COMMANDS{
        { "1",          1 },
        { "2",          2 },
        { "3",          3 },
        { "START GAME", static_cast<int>(TypeOfCommand::START_GAME) },
        { "HELP",       static_cast<int>(TypeOfCommand::HELP) },
        { "EXIT",       static_cast<int>(TypeOfCommand::EXIT) },
};

/**
 * Игра.
 */
class GoGame
{
public:

    /**
     * Конструктор.
     * @param argc число параметров
     * @param argv список параметров
     */
    GoGame( const int argc = 1, char** argv = nullptr ) noexcept;

    /**
     * Копирующий конструктор.
     *
     */
    GoGame( const GoGame& go ) noexcept;

    /**
     * Деструктор.
     */
    ~GoGame();

    /**
     * Начать игру.
     * Этот метод объединяет методы данного класса, отвечающие за организацию игрового процесса.
     */
    void begin();

private:

    GoEngineAPI* goEngineInterface; /**< Указатель на объект интерфейса движка */
    Help* help; /**< Указатель на объект хэлпа */
    int argc; /**< Число параметров командной строки */
    char** argv; /**< Список параметров командной строки */
    bool needMessage; /**< Нужно сообщение об ошибке? */
    bool needHelp; /**< Нужен хэлп? */
    bool hasExceptionHandled; /**< Было исключение обработано? */
    bool exit; /**< Выход? */
    std::string MESSAGE; /**< Сообщение */
    std::vector<char> board; /**< Доска для вывода на экран */

    /**
     * Открыть меню.
     */
    void menu();

    /**
     * Отрисовать меню.
     */
    void printMenu() const noexcept;

    /**
     * Хэлп.
     */
    void printHelp() const noexcept;

    /**
     * Распарсить комманду.
     * @param command команда
     */
    int parseCommand( const std::string& command ) const noexcept;

    /**
     * Начать игру.
     */
    void startGame();

    /**
     * Настроить игру.
     * @return true, если настройки прошли успешно, и false - в противном случае.
     */
    bool configureGame();

    /**
     * Инициализировать доску для вывода.
     * @param diagonal диагональ.
     */
    void initBoard( int diagonal ) noexcept;

    /**
     * Начать игровой процесс.
     */
    void play();

    /**
     * Запутить игровой цикл.
     * @param command строка.
     * @param first первая координата.
     * @param second вторая координата.
     */
    void startGameCycle( std::string& command, int& first, int& second );

    /**
     * Парсить входную строку.
     * @param command строка.
     * @param first первая координата.
     * @param second вторая координата.
     * @return тип распарсенной команды
     */
    int parseCommand1( const std::string& command, int& first, int& second ) noexcept;

    /**
     * Парсить первую координату.
     * @param command строка.
     * @param first первая координата.
     */
    void parseFirstCoordinate( const std::string& command, int& first ) noexcept;

    /**
     * Парсить вторую координату.
     * @param command строка.
     * @param second первая координата.
     */
    void parseSecondCoordinate( const std::string& command, int& second ) noexcept;

    /**
     * Напечатать cообщение, если нужно.
     * Если это нужно, напечатать соответствующее сообщение.
     */
    void ifNeedPrintMessage() noexcept;

    /**
     * Вывести help, если нужно.
     */
    void ifNeedPrintHelp() noexcept;

    /**
     * Напечатать сообщение.
     */
    void printMessage() const noexcept;

    /**
     * Выбрать распарсенную команду
     */
    void switchParsedCommand( const std::string& command, int& first, int& second );

    /**
     * Сделать ход.
     */
    void putStone( const int first, const int second );

    /**
     * Включить сообщение.
     * @param message сообщение
     */
    void turnOnMessage( const char* message ) noexcept;

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
     * @return цвет победителя.
     */
    int whoSurrendered() const noexcept;

    /**
     * Кто победил?
     * @return цвет победителя.
     */
    int whoWon() const noexcept;

    /**
     * Напечатать, чей ход.
     */
    void printWhoseMove() const noexcept;

    /**
     * Вывести на экран, кто сдался.
     * Данный метод выводит на экран сообщение о том, какой игрок сдался, если это имело место быть.
     */
    void printWhoSurrendered() const noexcept;

    /**
     * Вывести на экран, кто победил.
     * Данный метод выводит на экран сообщение о том, кто победил, если победитель определился.
     */
    void printWhoWon() const noexcept;

    /**
     * Напечатать, что черный сдался.
     */
    void printBlackSurrendered() const noexcept;

    /**
     * Напечатать, что белый сдался.
     */
    void printWhiteSurrendered() const noexcept;

    /**
     * Напечатать, что чёрный выиграл.
     */
    void printBlackWon() const noexcept;

    /**
     * Напечатать, что белый выиграл.
     */
    void printWhiteWon() const noexcept;

    /**
     * Напечатать статистику съеденных камней.
     */
    void printEatenStonesStat() const noexcept;

    /**
     * Отрисовать текущее состояние доски.
     */
    void printBoard();

    /**
     * Напечатать "Посчитайте очки".
     */
    void printCalculateScores() const noexcept;

    /**
     * Ввести диагональ.
     * @param diagonal диагональ.
     * @return true, если диагональ распарсилась, иначе - false.
     */
    bool parseDiagonal( int& diagonal ) noexcept;

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
    bool isDiagonalN( const std::string& input, const int n ) const noexcept;

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
     * Входная строка совпадает с командой?
     * @param input входная строка.
     * @param command команда
     * @return true, если входная строка совпадает с командой, и false - иначе.
     */
    bool isCommand( const std::string& input, const char* const command ) const noexcept;

    /**
     * Ключ exit?
     * @param input входная строка.
     * @return true, если введен ключ exit, и false - иначе.
     */
    bool isExit( const std::string& input ) const noexcept;

    /**
     * Ключ pass?
     * @param input входная строка.
     * @return true, если введен ключ exit, и false - иначе.
     */
    bool isPass( const std::string& input ) const noexcept;

    /**
     * Ключ surrender?
     * @param input входная строка.
     * @return true, если введен ключ exit, и false - иначе.
     */
    bool isSurrender( const std::string& input ) const noexcept;

    /**
     * Ключ help?
     * @param input входная строка.
     * @return true, если введен ключ help, и false - иначе.
     */
    bool isHelp( const std::string& input ) const noexcept;

    /**
     * Обновить доску
     */
    void updateBoard() noexcept;

    /**
     * Убрать выделение предпоследнего хода.
     */
    void unmarkPenultMove() noexcept;

    /**
     * Выделить последний ход.
     */
    void markLastMove() noexcept;
};

#endif //GO_GOGAME_H
