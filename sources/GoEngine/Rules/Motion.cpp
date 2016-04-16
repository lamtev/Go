#include "Motion.h"

Motion::Motion()
{
    motionIndex = 0;
    moves.resize(100);
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

int Motion::getMotionIndex() const noexcept
{
    return motionIndex;
}

vector<Moves>& Motion::getMoves() const noexcept
{
    return const_cast<vector<Moves>&>(moves);
}


void Motion::ifMoveRepeat( Board* board, int first, int second ) const
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

void Motion::ifMoveBeyondBoard( Board* board, int first, int second ) const
{
    int diagonal = board->getDiagonal();
    if( first < 0 || first >= diagonal || second < 0 || second >= diagonal )
    {
        throw MoveBeyondBoardException();
    }
}

void Motion::ifMoveToDie( Board* board, int first, int second ) const
{
    //TODO void Motion::ifMoveToDie
    if( false )
    {
        throw MoveToDieException();
    }
}

void Motion::ifMoveToNotEmptyPoint( Board* board, int first, int second ) const
{
    //TODO void Motion::ifMoveToNotEmptyPoint
    Moves currentMove(first, second);
//    Moves passedMove(0, 0);

    if( false/*find(board->getMoves().begin(), board->getMoves().end(), currentMove) != board->getMoves().end()*/ )
    {
        throw MoveToNotEmptyPointException();
    }
}

void Motion::ifMoveIllegal( Board* board, int first, int second ) const
{
    ifMoveRepeat(board, first, second);
    ifMoveBeyondBoard(board, first, second);
    ifMoveToDie(board, first, second);
    ifMoveToNotEmptyPoint(board, first, second);
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










































