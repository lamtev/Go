#include "Motion.h"

Motion::Motion() noexcept
{
    moveIndex = 0;
    movesSize = 100;
    surrendered = EMPTY;
    winner = EMPTY;
    stonesEatenByBlack = 0;
    stonesEatenByWhite = 0;
    moves.resize(movesSize);
}

void Motion::putStone(Board* board, int first, int second)
{
    ifNeedResizeMoves();
    ifMoveIllegalThrowException(board, first, second);
    board->operator()(first, second) = whoseMove();
    moves[moveIndex] = Move{ first, second };
    ++moveIndex;
}

void Motion::pass() noexcept
{
    ifNeedResizeMoves();
    moves[moveIndex] = passedMove;
    ++moveIndex;
}

void Motion::surrender() noexcept
{
    surrendered = whoseMove();
}

bool Motion::isGameOver() const noexcept
{
    return areTwoPasses() || whoSurrendered();
}

int Motion::whoSurrendered() const noexcept
{
    return surrendered;
}

int Motion::whoWon() const noexcept
{
    switch( surrendered )
    {
    case BLACK :
        return WHITE;
    case WHITE :
        return BLACK;
    default :
        return EMPTY;
    }
}

int Motion::getMoveIndex() const noexcept
{
    return moveIndex;
}

std::vector<Move>& Motion::getMoves() const noexcept
{
    return const_cast<std::vector<Move>&>(moves);
}

int Motion::whoseMove() const noexcept
{
    return isBlacksMove() ? BLACK : WHITE;
}

int Motion::getStonesEatenByBlack() const noexcept
{
    return stonesEatenByBlack;
}

int Motion::getStonesEatenByWhite() const noexcept
{
    return stonesEatenByWhite;
}

Move& Motion::getLastMove() const noexcept
{
    return const_cast<Move&>(moves[moveIndex - 1]);
}

bool Motion::areTwoPasses() const noexcept
{
    return moveIndex >= 2 ? moves[moveIndex - 1] == passedMove && moves[moveIndex - 1] == moves[moveIndex - 2] : false;
}

bool Motion::isBlacksMove() const noexcept
{
    return !(moveIndex % 2);
}

void Motion::ifNeedResizeMoves() noexcept
{
    if( movesSize - 1 == moveIndex )
    {
        movesSize += 100;
        moves.resize(movesSize);
    }
}

void Motion::ifMoveOutsideTheBoardThrowException( Board* board, int first, int second ) const
{
    if( first < 0 || first >= board->getDiagonal() || second < 0 || second >= board->getDiagonal() )
    {
        throw MoveOutsideTheBoardException();
    }
}

void Motion::ifMoveToNotEmptyPointThrowException( Board* board, int first, int second ) const
{
    if( board->operator()(first, second).isNotEmpty() )
    {
        throw MoveToNotEmptyPointException();
    }
}

void Motion::ifMoveRepeatThrowException( int first, int second ) const
{
    //BUG ifMoveRepeatThrowException
    if( moveIndex >= 2 )
    {
        if( moves[moveIndex] != passedMove && moves[moveIndex] == moves[moveIndex - 2] )
        {
            throw MoveRepeatException();
        }
    }
}

void Motion::ifMoveToDieThrowException( Board* board, int first, int second ) const
{
    //TODO void Motion::ifMoveToDie

    if( false )
    {
        throw MoveToDieException();
    }
}

void Motion::ifMoveIllegalThrowException( Board* board, int first, int second ) const
{
    ifMoveOutsideTheBoardThrowException(board, first, second);
    ifMoveToNotEmptyPointThrowException(board, first, second);
    //ifMoveRepeatThrowException(first, second);
    ifMoveToDieThrowException(board, first, second);
}
