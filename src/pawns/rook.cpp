#include "pawns/rook.hpp"
#include "board/board.h"
#include <iostream>


Rook::Rook(Color set_color, size_t set_position)
{
    color = set_color;
    position = set_position;
}

bool Rook::isPossibleMoves( Board& m_board, int new_position ) {
    checkMoves(m_board);
    for ( int i = 0; i < 16; i++){
        if ( possibleMoves[i] == new_position ) { 
            return true;
        }
    }
    return false;
}


void Rook::checkMoves(Board &m_board)
{
    int allow_i = 0;

    bool vertical = true;
    bool horizontal = true;

    for (int i = 0; i < 14; i++)
    {
        int next_pos = position + allowedMoves[i];

        if (vertical && next_pos >= 0 && next_pos <= 63)
        {
            if (m_board.cases[next_pos].type == NOTHING)
            {
                possibleMoves[allow_i] = next_pos;
                allow_i++;
            }
            else
            {
                if(  m_board.cases[next_pos].type != KING || m_board.cases[next_pos].m_pawn->getColor() != color ) {
                    possibleMoves[allow_i] = next_pos;
                    allow_i++;
                }
                vertical = false;
            }
        }

        next_pos = position - allowedMoves[i];
        if (horizontal && next_pos >= 0 && next_pos <= 63)
        {
            if (m_board.cases[next_pos].type == NOTHING)
            {
                possibleMoves[allow_i] = next_pos;
                allow_i++;
            }
            else
            {
                if(  m_board.cases[next_pos].type != KING || m_board.cases[next_pos].m_pawn->getColor() != color ) {
                    possibleMoves[allow_i] = next_pos;
                    allow_i++;
                }
                horizontal = false;
            }
        }
    }

    for (int i = 0; i < 16; i++)
    {
        std::cout << possibleMoves[i] << ";";
    }
    std::cout << "\n";
}

int Rook::move( Board& m_board, int old_pos, int new_pos){
    m_board.cases[new_pos].m_pawn = m_board.cases[old_pos].m_pawn;
    m_board.cases[new_pos].type = m_board.cases[old_pos].type;


    m_board.cases[old_pos].m_pawn = nullptr;
    m_board.cases[old_pos].type = NOTHING;

    position = new_pos;
}