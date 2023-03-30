#include "pawns/IPiece.hpp"
#include "board/board.h"

void IPiece::checkMoves( Board& m_board ) {
    int allow_i = 0;
    
    for ( int i = 0; i < allowed_moves_size; i++) {
        int next_move = position + allowed_moves[i];
        if ( next_move >= 0 && next_move <= 63 ) {
            if ( m_board.cases[next_move].m_pawn == nullptr ) {
                possible_moves[allow_i] = next_move;
                allow_i++;
            }
        }
    }

}