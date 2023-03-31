#include "pawns/rook.hpp"
#include "board/board.h"
#include <iostream>

Rook::Rook(Color set_color, size_t set_position)
{
    color = set_color;
    position = set_position;
}

void Rook::checkMoves(Board &m_board)
{
    int allow_i = 0;

    bool vertical = true;
    bool horizontal = true;

    for (int i = 0; i < 14; i++)
    {
        int next_pos = position + allowedMoves[i];

        // A enlever en cas de bug, peut causer des soucis dans la logique
        if(next_pos % 8 == 0 || next_pos % 7 == 0)
            continue;

        if (vertical && next_pos >= 0 && next_pos <= 63)
        {
            if (m_board.cases[next_pos].type == NOTHING)
            {
                possibleMoves[allow_i] = next_pos;
                allow_i++;
            }
            else
            {
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
                horizontal = false;
            }
            if (this->color == White)
            {

                if (m_board.cases[next_pos].type != NOTHING && m_board.cases[next_pos].m_pawn->getColor() == Black)
                {
                    possibleMoves[allow_i] = next_pos;
                    allow_i++;
                    break;
                }
            }
            else
            {
                if (m_board.cases[next_pos].type != NOTHING && m_board.cases[next_pos].m_pawn->getColor() == White)
                    break;
            }
        }
    }

    for (int i = 0; i < 16; i++)
    {
        std::cout << possibleMoves[i] << ";";
    }
    std::cout << "\n";
}

int Rook::move(Board &m_board)
{
}