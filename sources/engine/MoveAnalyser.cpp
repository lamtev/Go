#include "MoveAnalyser.h"

namespace Go {

MoveAnalyser::MoveAnalyser(const Board &board, const Moves &moves) noexcept:
    board{std::make_shared<Board>(board)},
    moves{std::make_shared<Moves>(moves)} { }

}