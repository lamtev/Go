#include "Motion.h"

Motion::Motion()
{
    motionIndex = 0;
    moves.reserve(361);
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

bool Motion::areTwoPasses() const noexcept
{
    Moves passedMove;
    passedMove.putFirst(0);
    passedMove.putSecond(0);
    return moves[motionIndex] == passedMove && moves[motionIndex] == moves[motionIndex-2];
}

void Motion::ifMoveRepeat( Board* board, int first, int second ) const
{
    if( motionIndex >= 2 )
    {
        Moves passedMove;
        passedMove.putFirst(0);
        passedMove.putSecond(0);
        if( moves[motionIndex] != passedMove && moves[motionIndex] == moves[motionIndex-2] )
        {
            throw MoveRepeatException();
        }
    }
}

void Motion::ifMoveBeyondBoard( Board* board, int first, int second ) const
{
    int diagonal = board->getDiagonal();
    if( first < 0 || first >= diagonal || second < 0 || second >= diagonal )
    {
        throw MoveBeyondBoardException();
    }
}

void Motion::ifMoveToDie(Board *board, int first, int second) const
{
    //TODO void Motion::ifMoveToDie
    if( false )
    {
        throw MoveToDieException();
    }
}

void Motion::ifMoveIllegal( Board* board, int first, int second ) const
{
    ifMoveRepeat(board, first, second);
    ifMoveBeyondBoard(board, first, second);
    ifMoveToDie(board, first, second);
}

void Motion::putStone(Board* board, int first, int second)
{
    ifMoveIllegal( board, first, second );
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
































