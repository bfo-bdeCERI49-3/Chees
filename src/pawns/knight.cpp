#include "pawms/knight.hpp"

Knight::Knight ( Color set_color ) {
    color = set_color;
    allowed_moves = new  int[allowed_moves_size];
    possible_moves = new int[possible_move_size];
}

int Knight::move(Board& m_board) {
    checkMoves(m_board);
}