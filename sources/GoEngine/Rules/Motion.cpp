#include "Motion.h"

Motion::Motion()
{
    motionIndex = 0;
    moves.resize(100);
}

void Motion::putStone(Board* board, int first, int second)
{
    ifMoveIllegalThrowException( board, first, second );
    board->operator()(first, second) = whoseMove();
    moves[motionIndex].putFirst(first);
    moves[motionIndex].putSecond(second);
    ++motionIndex;
}

void Motion::pass() noexcept
{
    moves[motionIndex].putFirst(0);
    moves[motionIndex].putSecond(0);
    ++motionIndex;
}

bool Motion::areTwoPasses() const noexcept
{
    Moves passedMove;
    passedMove.putFirst(0);
    passedMove.putSecond(0);
    return moves[motionIndex] == passedMove && moves[motionIndex] == moves[motionIndex-2];
}

int Motion::getMotionIndex() const noexcept
{
    return motionIndex;
}

vector<Moves>& Motion::getMoves() const noexcept
{
    return const_cast<vector<Moves>&>(moves);
}

bool Motion::isBlacksMove() const noexcept
{
    return !(motionIndex % 2);
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

void Motion::ifMoveToNotEmptyPointThrowException( Board* board, int first, int second ) const
{
    if( board->operator()(first, second).isNotEmpty() )
    {
        throw MoveToNotEmptyPointException();
    }
}

void Motion::ifMoveRepeatThrowException( Board* board, int first, int second ) const
{
    //TODO fix bug
    if( motionIndex >= 2 )
    {
        Moves passedMove(0, 0);
        if( moves[motionIndex] != passedMove && moves[motionIndex] == moves[motionIndex-2] )
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
    ifMoveToNotEmptyPointThrowException(board, first, second);
    ifMoveRepeatThrowException(board, first, second);
    ifMoveToDieThrowException(board, first, second);
}