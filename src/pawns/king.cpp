#include "pawns/king.hpp"
#include "board/board.h"
#include <iostream>

King::King ( Color set_color, size_t set_position) {
    color = set_color;
    position = set_position;
}

int King::move(Board& m_board){

}

void King::checkMoves(Board& m_board) {
    int allow_i = 0;
    for ( int i = 0; i < 8; i++ ) {
        int next_pos = position + allowedMoves[i];
        if (next_pos >= 0 && next_pos <= 63 ) {
            if ( m_board.cases[next_pos].type == NOTHING ) {
                possibleMoves[allow_i] = next_pos;
                allow_i++;
            } else {
                //eat
            }
        }
    }

    for(int i = 0; i < 8; i++){
        std::cout << possibleMoves[i] << ";";
    }
    std::cout << "\n";
}