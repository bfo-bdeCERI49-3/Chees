#include "pawns/fool.hpp"
#include "board/board.h"

Fool::Fool( Color set_color ) : allowed_moves_size(8), possible_move_size(8)  {
    color = set_color;

    allowed_moves = new  int[allowed_moves_size];
    possible_moves = new int[possible_move_size];

    allowed_moves

}

int Fool::move(Board &m_board) {
    int new_pos = position;
    return new_pos;
}