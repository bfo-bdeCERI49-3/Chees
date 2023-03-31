#include "pawns/king.hpp"
#include "board/board.h"
#include <iostream>

King::King(Color set_color, size_t set_position)
{
    color = set_color;
    position = set_position;
}

int King::move(Board &m_board)
{
}

void King::checkMoves(Board &m_board)
{
    int allow_i = 0;
    for (int i = 0; i < 8; i++)
    {
        int next_pos = position + allowedMoves[i];

        // Right side of the checker
        if (this->position % 7 == 0 && (allowedMoves[i] == 1 || allowedMoves[i] == 9 || allowedMoves[i] == -9))
            continue;

        // Left side of the checker
        if (this->position % 8 == 0 && (allowedMoves[i] == -1 || allowedMoves[i] == 7 || allowedMoves[i] == -7))
            continue;

        if (this->color == White)
        {
            if (next_pos >= 0 && next_pos <= 63)
            {
                // Nothing in front
                if (m_board.cases[next_pos].type == NOTHING)
                {
                    possibleMoves[allow_i] = next_pos;
                    allow_i++;
                }

                // Black piece in front as white piece
                if (m_board.cases[next_pos].type != NOTHING && m_board.cases[next_pos].m_pawn->getColor() == Black)
                {
                    possibleMoves[allow_i] = next_pos;
                    allow_i++;
                }
            }
        }
        else
        {
           if (next_pos >= 0 && next_pos <= 63)
            {
                // Nothing in front
                if (m_board.cases[next_pos].type == NOTHING)
                {
                    possibleMoves[allow_i] = next_pos;
                    allow_i++;
                }

                // Black piece in front as white piece
                if (m_board.cases[next_pos].type != NOTHING && m_board.cases[next_pos].m_pawn->getColor() == White)
                {
                    possibleMoves[allow_i] = next_pos;
                    allow_i++;
                }
            } 
        }
    }

    for (int i = 0; i < 8; i++)
    {
        std::cout << possibleMoves[i] << ";";
    }
    std::cout << "\n";
}