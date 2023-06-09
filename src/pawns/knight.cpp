#include "pawns/knight.hpp"
#include "board/board.h"
#include <iostream>

Knight::Knight(Color set_color, size_t set_position)
{
    color = set_color;
    position = set_position;
}

int Knight::move( Board& m_board, int old_pos, int new_pos){
    m_board.cases[new_pos].m_pawn = m_board.cases[old_pos].m_pawn;
    m_board.cases[new_pos].type = m_board.cases[old_pos].type;


    m_board.cases[old_pos].m_pawn = nullptr;
    m_board.cases[old_pos].type = NOTHING;

    position = new_pos;
}

bool Knight::isPossibleMoves( Board& m_board,  int new_position ) {
    checkMoves(m_board);
    for ( int i = 0; i < 8; i++){
        if ( possibleMoves[i] == new_position ) {
            return true;
        }
    }
    return false;
}

void Knight::checkMoves(Board &m_board)
{
    int allow_i = 0;
    for (int i = 0; i < 8; i++) {
        int next_pos = position + allowedMoves[i];
        if (next_pos >= 0 && next_pos <= 63)
        {
            if ( m_board.cases[next_pos].type == NOTHING ||  m_board.cases[next_pos].m_pawn->getColor() != color) {
                possibleMoves[allow_i] = next_pos;
                allow_i++;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        std::cout << possibleMoves[i] << ";";
    }
    std::cout << "\n";
}
