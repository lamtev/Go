#include "Motion.h"

Motion::Motion() noexcept
{
    moveIndex = 0;
    moves.resize(movesSize);
}

void Motion::putStone(Board* board, int first, int second)
{
    ifNeedResizeMoves();
    ifMoveIllegalThrowException(board, first, second);
    board->operator()(first, second) = whoseMove();
    moves[moveIndex].putFirst(first);
    moves[moveIndex].putSecond(second);
    ++moveIndex;
}

void Motion::pass() noexcept
{
    ifNeedResizeMoves();
    moves[moveIndex].putFirst(PASS_COORD);
    moves[moveIndex].putSecond(PASS_COORD);
    ++moveIndex;
}

void Motion::surrender() noexcept
{
    surrendered = whoseMove();
}

bool Motion::isGameOver() const noexcept
{
    //TODO добавить условий конца игры
    return areTwoPasses() || whoSurrendered();
}

int Motion::whoSurrendered() const noexcept
{
    return surrendered;
}


int Motion::getMoveIndex() const noexcept
{
    return moveIndex;
}

vector<Moves>& Motion::getMoves() const noexcept
{
    return const_cast<vector<Moves>&>(moves);
}

int Motion::whoseMove() const noexcept
{
    if( isBlacksMove() )
    {
        return BLACK;
    }
    else
    {
        return WHITE;
    }
}

int Motion::getStonesEatenByBlack() const noexcept
{
    return stonesEatenByBlack;
}

int Motion::getStonesEatenByWhite() const noexcept
{
    return stonesEatenByWhite;
}

bool Motion::areTwoPasses() const noexcept
{
    if( moveIndex >= 2 )
    {
        Moves passedMove;
        passedMove.putFirst(PASS_COORD);
        passedMove.putSecond(PASS_COORD);
        return moves[moveIndex - 1] == passedMove && moves[moveIndex - 1] == moves[moveIndex - 2];
    }
    else
    {
        return false;
    }
}

void Motion::ifNeedResizeMoves() noexcept
{
    if( movesSize - 1 == moveIndex )
    {
        movesSize += 100;
        moves.resize(movesSize);
    }
}

bool Motion::isBlacksMove() const noexcept
{
    return !(moveIndex % 2);
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
        Moves passedMove(PASS_COORD, PASS_COORD);
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

Moves& Motion::getLastMove() const noexcept
{
    return moves[moveIndex - 1];
}
