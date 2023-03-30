#include "pawns/fool.hpp"
#include "board/board.h"
#include <iostream>

Fool::Fool( Color set_color, size_t set_position ) {
    color = set_color;
    position = set_position;
}

void Fool::checkMoves( Board& m_board ) {
    int allow_i = 0;
    for ( int i = 0; i < 4; i++ ) {
        int next_pos = position;
        while ( next_pos + allowedMoves[i] >= 0 && next_pos  + allowedMoves[i] < 64) {
            if ( (next_pos + 1) % 8 == 0 || next_pos%8 == 0) {
                break;
            }
            possibleMoves[allow_i] = next_pos + allowedMoves[i];
            next_pos += allowedMoves[i];
            allow_i++;
        }
    }

    for(int i = 0; i < 16; i++){
        std::cout << possibleMoves[i] << ";";
    }
    std::cout << "\n";

}

int Fool::move(Board &m_board) {
    int new_pos = position;
    return new_pos;
}