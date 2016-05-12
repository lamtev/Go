#include "GameProcess.h"

GameProcess::GameProcess( const int diagonal ) noexcept : diagonal{ diagonal },
                                                          board{ new Board{ diagonal } },
                                                          movesSize{ 100 },
                                                          moveIndex{ 0 },
                                                          surrendered{ Status::EMPTY },
                                                          winner{ Status::EMPTY },
                                                          stonesEatenByBlack{ 0 },
                                                          stonesEatenByWhite{ 0 }
{
    moves.resize(movesSize);
}

GameProcess::~GameProcess()
{
    delete board;
}

Status GameProcess::whoseMove() const noexcept
{
    if( isGameOver() )
    {
        return Status::EMPTY;
    }
    return isBlacksMove() ? Status::BLACK : Status::WHITE;
}

void GameProcess::putStone( int first, int second )
{
    resizeMoves();
    ifMoveIllegalThrowException(first, second);
    //TODO обдумать постановку камня на доску!!!
    //todo не нравится мне вот эта строчка... выходи пункт равен тому, чей ход...
    //может что нибудь типа такой конструкции:
    //Point &samplePoint = board(first, second);
    //samplePoint.setStone(Stone(whoseMove())); ...
    //тоже не очень хорошо, громоздко, но чуть чуть понятнее
    //тут подумать надо
    board->operator()(first, second) = whoseMove();
    //todo слишком длинно, колбаса
    //todo а можно просто board(first, second)?
    //лучше разбить на 2-3 строчки.
    //тут бы еще мог бы метод setStone кстати быть:
    //Point samplePoint = board(first, second);
    //Stone sampleStone(samplePoint.getStatus(), first, second, 0);
    //board(first, second).setStone(sampleStone);
    //дело вкуса, конечно, но строчка реально длинная и непонятная.
    board->operator()(first, second).createStone(static_cast<Color>(board->operator()(first, second).getStatus()), first, second, 0);
    moves[moveIndex] = Move{ first, second };
    ++moveIndex;
}

void GameProcess::pass() noexcept
{
    resizeMoves();
    moves[moveIndex] = passedMove;
    ++moveIndex;
}

void GameProcess::surrender() noexcept
{
    surrendered = whoseMove();
    winner = whoseMove() == Status::BLACK ? Status::WHITE : Status::BLACK;
}

bool GameProcess::isGameOver() const noexcept
{
    return areTwoPasses() || static_cast<bool>(whoSurrendered());
}

Status GameProcess::whoSurrendered() const noexcept
{
    return surrendered;
}

Status GameProcess::whoWon() const noexcept
{
    return winner;
}

int GameProcess::getMoveIndex() const noexcept
{
    return moveIndex;
}

std::vector<Move>& GameProcess::getMoves() const noexcept
{
    return const_cast<std::vector<Move>&>(moves);
}

Move& GameProcess::getLastMove() const noexcept
{
    return const_cast<Move&>(moves[moveIndex - 1]);
}

Move& GameProcess::getPenultMove() const noexcept
{
    return const_cast<Move&>(moves[moveIndex - 2]);
}

int GameProcess::getStonesEatenByBlack() const noexcept
{
    return stonesEatenByBlack;
}

int GameProcess::getStonesEatenByWhite() const noexcept
{
    return stonesEatenByWhite;
}

Board& GameProcess::getBoard() const noexcept
{
    return *board;
}

bool GameProcess::areTwoPasses() const noexcept
{
    return moveIndex >= 2 ?
           getLastMove() == passedMove &&
           getLastMove() == getPenultMove() :
           false;
}

bool GameProcess::isBlacksMove() const noexcept
{
    return !(moveIndex % 2);
}

void GameProcess::resizeMoves() noexcept
{
    if( movesSize - 1 == moveIndex )
    {
        movesSize += 100;
        moves.resize(movesSize);
    }
}

void GameProcess::removeEatenStones() noexcept
{
    //TODO removeEatenStones
}

void GameProcess::ifMoveOutsideTheBoardThrowException( int first, int second ) const
{
    if( first  < 1 || first  > board->getDiagonal() ||
        second < 1 || second > board->getDiagonal() )
    {
        throw MoveOutsideTheBoardException();
    }
}

void GameProcess::ifMoveToNotEmptyPointThrowException( int first, int second ) const
{
    if( board->operator()(first, second).isNotEmpty() )
    {
        throw MoveToNotEmptyPointException();
    }
}

void GameProcess::ifMoveRepeatThrowException( int first, int second ) const
{
    if( moveIndex >= 2 )
    {
        Move currentMove{ first, second };
        if( currentMove != passedMove && currentMove == getPenultMove() )
        {
            throw MoveRepeatException();
        }
    }
}

void GameProcess::ifMoveToDieThrowException( int first, int second ) const
{
    //TODO void GameProcess::ifMoveToDie

    if( false )
    {
        throw MoveToDieException();
    }
}

void GameProcess::ifMoveIllegalThrowException( int first, int second ) const
{
    ifMoveOutsideTheBoardThrowException(first, second);
    ifMoveToNotEmptyPointThrowException(first, second);
    //ifMoveRepeatThrowException(first, second);
    ifMoveToDieThrowException(first, second);
}
