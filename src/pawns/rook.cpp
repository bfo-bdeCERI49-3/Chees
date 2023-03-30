#include "pawns/rook.hpp"

Rook::Rook( Color set_color ) : allowed_moves_size(8), possible_move_size(16) {
    color = set_color;
    const templates[7] = { 1, 2, 3, 4, 5, 6, 7 };
}

int Rook::move( Board& m_board ){

}