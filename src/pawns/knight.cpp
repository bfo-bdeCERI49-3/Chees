#include "pawns/knight.hpp"
#include "board/board.h"
#include <iostream>

Knight::Knight(Color set_color, size_t set_position)
{
    color = set_color;
    position = set_position;
}

void Knight::checkMoves(Board &m_board)
{
    int allow_i = 0;
    for (int i = 0; i < 8; i++)
    {
        int next_pos = position + allowedMoves[i];
        if (next_pos >= 0 && next_pos <= 63)
        {
            if ((next_pos + 1) % 8 == 0 || next_pos % 8 == 0)
            {
                continue;
            }

            if (this->color == White)
            {
                // Si la case est vide
                if (m_board.cases[next_pos].type == NOTHING)
                {
                    possibleMoves[allow_i] = next_pos;
                    allow_i++;
                }
                else
                {
                    if (m_board.cases[next_pos].type != NOTHING && m_board.cases[next_pos].m_pawn->getColor() == Black)
                    {
                        possibleMoves[allow_i] = next_pos;
                        allow_i++;
                        break;
                    }
                }
            }
            else
            {
                // Si la case est vide
                if (m_board.cases[next_pos].type == NOTHING)
                {
                    possibleMoves[allow_i] = next_pos;
                    allow_i++;
                }
                else
                {
                    if (m_board.cases[next_pos].type != NOTHING && m_board.cases[next_pos].m_pawn->getColor() == White)
                    {
                        break;
                    }
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

int Knight::move(Board &m_board)
{
    checkMoves(m_board);
}