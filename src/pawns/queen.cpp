#include "queen/queen.hpp"
#include "board/board.h"

int Queen::move(Board &m_board)
{
    int new_pos;
    return new_pos;
}

void Queen::checkMoves(Board &m_board)
{
    if (this->color == White)
    {
        for (int i = 1; i < 8; i++)
        {
            if (this->position + 8 * i <= 63)
            {
                if (m_board.cases[this->position + 8 * i].type == NOTHING)
                {
                    this->possibleMoves[this->possibleMovesSize] = this->position + 8 * i;
                    this->possibleMovesSize++;
                }
                else
                    break;
            }
        }
        for (int i = 1; i < 8; i++)
        {
            if (m_board.cases[this->position + 9 * i].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position + 9 * i;
                this->possibleMovesSize++;
            }
            if (this->position % 7 != 0 || this->position + 9 * i <= 63)
                break;
        }
        for (int i = 1; i < 8; i++)
        {
            if (m_board.cases[this->position + 7 * i].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position + 7 * i;
                this->possibleMovesSize++;
            }
            if (this->position % 8 != 0 || this->position + 7 * i <= 63)
                break;
        }

        for (int i = 1; i < 8; i++)
            if (m_board.cases[this->position - 9 * i].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position - 9 * i;
                this->possibleMovesSize++;
            }
        if (this->position % 7 != 0 || this->position - 9 * i > 0)
            break;
        for (int i = 1; i < 8; i++)
        {
            if (m_board.cases[this->position - 7 * i].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position - 7 * i;
                this->possibleMovesSize++;
            }
            if (this->position % 8 != 0 || this->position - 7 * i > 0)
                break;
        }
    }
    if (this->color == Black)
    {
        for (int i = 1; i < 8; i++)
        {
            if (this->position + 8 * i <= 63)
            {
                if (m_board.cases[this->position + 8 * i].type == NOTHING)
                {
                    this->possibleMoves[this->possibleMovesSize] = this->position + 8 * i;
                    this->possibleMovesSize++;
                }
                else
                    break;
            }
        }
        for (int i = 1; i < 8; i++)
        {
            if (m_board.cases[this->position + 9 * i].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position + 9 * i;
                this->possibleMovesSize++;
            }
            if (this->position % 7 != 0 || this->position + 9 * i <= 63)
                break;
        }
        for (int i = 1; i < 8; i++)
        {
            if (m_board.cases[this->position + 7 * i].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position + 7 * i;
                this->possibleMovesSize++;
            }
            if (this->position % 8 != 0 || this->position + 7 * i <= 63)
                break;
        }

        for (int i = 1; i < 8; i++)
            if (m_board.cases[this->position - 9 * i].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position - 9 * i;
                this->possibleMovesSize++;
            }
        if (this->position % 7 != 0 || this->position - 9 * i > 0)
            break;
        for (int i = 1; i < 8; i++)
        {
            if (m_board.cases[this->position - 7 * i].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position - 7 * i;
                this->possibleMovesSize++;
            }
            if (this->position % 8 != 0 || this->position - 7 * i > 0)
                break;
        }
    }
}
