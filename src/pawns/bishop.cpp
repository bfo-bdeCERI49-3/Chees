#include "pawns/bishop.hpp"
#include "board/board.h"
#include <iostream>

Bishop::Bishop( Color set_color, size_t set_position ) {
    color = set_color;
    position = set_position;
}

bool Bishop::isPossibleMoves( Board& m_board, int new_position ) {
    checkMoves(m_board);
    for ( int i = 0; i < 16; i++){
        if ( possibleMoves[i] == new_position ) { 
            return true;
        }
    }
    return false;
}

void Bishop::checkMoves( Board& m_board ) {
    int allow_i = 0;
    for ( int i = 0; i < 4; i++ ) {
        int next_pos = position;
        while ( next_pos + allowedMoves[i] >= 0 && next_pos  + allowedMoves[i] < 64) {

            Case current_case = m_board.cases[next_pos  + allowedMoves[i]];
            if(current_case.type != NOTHING) {
                if ( current_case.m_pawn != nullptr ) {
                    if ( color !=  current_case.m_pawn->getColor() ) {
                        possibleMoves[allow_i] = next_pos + allowedMoves[i];
                        allow_i++;
                    }
                }
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

int Bishop::move( Board& m_board, int old_pos, int new_pos){
    m_board.cases[new_pos].m_pawn = m_board.cases[old_pos].m_pawn;
    m_board.cases[new_pos].type = m_board.cases[old_pos].type;


    m_board.cases[old_pos].m_pawn = nullptr;
    m_board.cases[old_pos].type = NOTHING;

    position = new_pos;
}
