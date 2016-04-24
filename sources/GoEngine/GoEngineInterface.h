#ifndef GOENGINEINTERFACE_H
#define GOENGINEINTERFACE_H

#include <string>

#include "Board.h"
#include "Rules/Motion.h"
#include "Rules/ScoreCalculator.h"
#include "enums.h"

//TODO

/**
 * Класс, предоставляющий интерфейс движка приложению
 */
class GoEngineInterface
{
public:

    /**
     * Деструктор
     * Разрушает объект
     */
    ~GoEngineInterface();

    /**
     * Начать игру.
     * Этот метод начинает игру с параметрами, заданными конфигурационным файлом
     * @param config конфигурационный файл
     */
    void startGame( const std::string& config );

    /**
     * Начать игру.
     * Этот метод начинает игру с параметрами, заданными его аргументами
     * @param diagonal диагональ игровой доски
     * @param rules правила подсчета очков
     * @param colorDistribution способ распределения цветов
     */
    void startGame( const int diagonal, const int rules, const int colorDistribution );

    /**
     * Положить камень в выбранный пункт.
     * Данный метод позволяет игроку положить его иговой камень в пункт доски
     * @param first первая координата выбранного пункта доски (A - S)
     * @param second вторая координата выбранного пункта доски (1 - 19)
     * @return доска
     */
    void putStone( const int first, const int second );

    /**
     * Пропустить ход.
     * Данный метод позваляит игроку пропустить ход
     */
    void pass() noexcept;

    /**
     * Сдаться.
     * Данный метод позволяет игроку сдаться
     */
    void surrender() noexcept;

    /**
     * Получить доску.
     * Данный метод возвращает доску
     * @return Board
     */
    Board& getBoard() const noexcept;

    /**
     * Чей ход?
     * Данный метод возвращает цвет того игрока, который должен сделать ход
     * @return цвет игрока, чей сейчас ход
     */
    int whoseMove() const noexcept;

    /**
     * Проверка на окончание игры.
     * Данный метод возвращает true, если игра закончена, и false - в противном
     * случае
     * @return булевое значение
     */
    bool isGameOver() const;

    /**
     * Кто победил?
     * Данный метод возвращает цвет победителя
     * @return цвет победителя
     */
    int whoWon() const;

    /**
     * Получить очки чёрных.
     * Данный метод возвращает количество очков чёрных
     * @return очки чёрных
     */
    int getBlackScore() const;

    /**
     * Получить очки белых.
     * Данный метод возвращает количество очков белых
     * @return очки белых
     */
    int getWhiteScore() const;

    /**
     * Кто сдался?
     */
    int whoSurrendered() const noexcept;

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
     * Получить вектор ходов.
     * @return ссылка на вектор ходов.
     */
    std::vector<Moves>& getMoves() const noexcept;

    /**
     * Получить последний совершённый ход.
     * @return ссылка на последний совершённый ход.
     */
    Moves& getLastMove() const noexcept;

private:

    Board* board; /**< Указатель на объект игровой доски */
    Motion* motion; /**< Указатель на объект процесса ходов */
    ScoreCalculator* scoreCalculator; /**< Указатель на объект калькулятора очков */
};

#endif // GOENGINEINTERFACE_H
