#include "queen.hpp"

int Queen::move(Board &m_board)
{
    int new_pos;
    return new_pos;
}

void Queen::checkMoves(Board &m_board)
{
    int movesSize = 0;
    if (this->color == White)
    {
        // Right side of the checker
        if (this->position % 8 == 0)
        {
            // Generate horizontal moves
            for (int i = 1; i < 8; i++)
            {

                Case nextPosition = m_board.cases[this->position + i];

                // Nothing in front
                if (nextPosition.type == NOTHING)
                {
                    this->possibleMoves[movesSize] == i;
                    movesSize++;
                }

                // Black pawn in front
                if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                {
                    this->possibleMoves[movesSize] == i;
                    movesSize++;
                    break;
                    // White pawn in front
                }
                else if (nextPosition.m_pawn->getColor() == White)
                {
                    break;
                }

                // arrived at the right side: exit loop
                if (this->position + i % 7 == 0)
                    break;
            }

            // generate veritcal moves
            for (int i = 1; i < 8; i++)
            {
                // Check for overflow
                if (this->position + 8 * i < 63)
                {
                    Case nextPosition = m_board.cases[this->position + 8 * i];
                    // Black piece on the way as a white piece
                    if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                    {
                        this->possibleMoves[movesSize] = this->position + 8 * i;
                        movesSize++;
                        break;
                        // White piece on the way as white
                    }
                    else if (nextPosition.m_pawn->getColor() == White)
                    {
                        break;
                    };

                    // Nothing on the way
                    if (nextPosition.type == NOTHING)
                    {
                        this->possibleMoves[movesSize] = this->position + 8 * i;
                        movesSize++;
                    }
                }
            }
            for (int i = 0; i < 8; i++)
            {
                // Check for overflow
                if (this->position - 8 * i > 0)
                {
                    Case nextPosition = m_board.cases[this->position - 8 * i];

                    // Nothing on the way
                    if (nextPosition.type == NOTHING)
                    {
                        this->possibleMoves[movesSize] = this->position - 8 * i;
                        movesSize++;
                    }

                    // Black piece on the way as a white piece
                    if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                    {
                        this->possibleMoves[movesSize] = this->position - 8 * i;
                        movesSize++;
                        // White as white -> break loop and stop looking for moves
                    }
                    else if (nextPosition.m_pawn->getColor() == White && this->position + 8 * i != this->position)
                    {
                        break;
                    }
                }
            }

            // Diagonal
            for (int i = 1; i < 8; i++)
            {
                // Check for overflow
                if (this->position + 9 * i <= 63)
                {
                    Case nextPosition = m_board.cases[this->position + 9 * i];
                    // Black piece on the way as a white piece
                    if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                    {
                        this->possibleMoves[movesSize] = this->position + 9 * i;
                        movesSize++;
                        break;
                        // White piece on the way as white
                    }
                    else if (nextPosition.m_pawn->getColor() == White)
                    {
                        break;
                    };

                    // Nothing on the way
                    if (nextPosition.type == NOTHING)
                    {
                        this->possibleMoves[movesSize] = this->position + 9 * i;
                        movesSize++;
                    }
                }
            }
            for (int i = 0; i < 8; i++)
            {
                // Check for overflow
                if (this->position - 9 * i >= 0)
                {
                    Case nextPosition = m_board.cases[this->position - 9 * i];

                    // Nothing on the way
                    if (nextPosition.type == NOTHING)
                    {
                        this->possibleMoves[movesSize] = this->position - 9 * i;
                        movesSize++;
                    }

                    // Black piece on the way as a white piece
                    if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                    {
                        this->possibleMoves[movesSize] = this->position - 9 * i;
                        movesSize++;
                        // White as white -> break loop and stop looking for moves
                    }
                    else if (nextPosition.m_pawn->getColor() == White && this->position != this->position - 9 * i)
                    {
                        break;
                    }
                }
            }
        }

        if (this->position % 7 == 0)
        {
            // Horizontal moves
            for (int i = 1; i < 8; i++)
            {
                Case nextPosition = m_board.cases[this->position - i];

                if (nextPosition.type == NOTHING)
                {
                    this->possibleMoves[movesSize] = this->position - i;
                    movesSize++;
                }

                // Black piece
                if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                {
                    this->possibleMoves[movesSize] = this->position - i;
                    movesSize++;
                    break;
                }

                // White piece
                if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == White)
                {
                    break;
                }

                if (this->position - i % 8 == 0)
                    break;
            }
            // generate veritcal moves
            for (int i = 1; i < 8; i++)
            {
                // Check for overflow
                if (this->position + 8 * i < 63)
                {
                    Case nextPosition = m_board.cases[this->position + 8 * i];
                    // Black piece on the way as a white piece
                    if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                    {
                        this->possibleMoves[movesSize] = this->position + 8 * i;
                        movesSize++;
                        break;
                        // White piece on the way as white
                    }
                    else if (nextPosition.m_pawn->getColor() == White)
                    {
                        break;
                    };

                    // Nothing on the way
                    if (nextPosition.type == NOTHING)
                    {
                        this->possibleMoves[movesSize] = this->position + 8 * i;
                        movesSize++;
                    }
                }
            }
            for (int i = 0; i < 8; i++)
            {
                // Check for overflow
                if (this->position - 8 * i > 0)
                {
                    Case nextPosition = m_board.cases[this->position - 8 * i];

                    // Nothing on the way
                    if (nextPosition.type == NOTHING)
                    {
                        this->possibleMoves[movesSize] = this->position - 8 * i;
                        movesSize++;
                    }

                    // Black piece on the way as a white piece
                    if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                    {
                        this->possibleMoves[movesSize] = this->position - 8 * i;
                        movesSize++;
                        // White as white -> break loop and stop looking for moves
                    }
                    else if (nextPosition.m_pawn->getColor() == White && this->position + 8 * i != this->position)
                    {
                        break;
                    }
                }
            }

            // Horizontal
            for (int i = 1; i < 8; i++)
            {
                // Check for overflow
                if (this->position + 9 * i <= 63)
                {
                    Case nextPosition = m_board.cases[this->position + 9 * i];
                    // Black piece on the way as a white piece
                    if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                    {
                        this->possibleMoves[movesSize] = this->position + 9 * i;
                        movesSize++;
                        break;
                        // White piece on the way as white
                    }
                    else if (nextPosition.m_pawn->getColor() == White)
                    {
                        break;
                    };

                    // Nothing on the way
                    if (nextPosition.type == NOTHING)
                    {
                        this->possibleMoves[movesSize] = this->position + 9 * i;
                        movesSize++;
                    }
                }
            }
            for (int i = 0; i < 8; i++)
            {
                // Check for overflow
                if (this->position - 9 * i >= 0)
                {
                    Case nextPosition = m_board.cases[this->position - 9 * i];

                    // Nothing on the way
                    if (nextPosition.type == NOTHING)
                    {
                        this->possibleMoves[movesSize] = this->position - 9 * i;
                        movesSize++;
                    }

                    // Black piece on the way as a white piece
                    if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                    {
                        this->possibleMoves[movesSize] = this->position - 9 * i;
                        movesSize++;
                        // White as white -> break loop and stop looking for moves
                    }
                    else if (nextPosition.m_pawn->getColor() == White && this->position != this->position - 9 * i)
                    {
                        break;
                    }
                }
            }
            // Diagonal
            for (int i = 1; i < 8; i++)
            {
                // Check for overflow
                if (this->position + 7 * i <= 63)
                {
                    Case nextPosition = m_board.cases[this->position + 7 * i];
                    // Black piece on the way as a white piece
                    if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                    {
                        this->possibleMoves[movesSize] = this->position + 7 * i;
                        movesSize++;
                        break;
                        // White piece on the way as white
                    }
                    else if (nextPosition.m_pawn->getColor() == White)
                    {
                        break;
                    };

                    // Nothing on the way
                    if (nextPosition.type == NOTHING)
                    {
                        this->possibleMoves[movesSize] = this->position + 7 * i;
                        movesSize++;
                    }
                }
            }
            for (int i = 0; i < 8; i++)
            {
                // Check for overflow
                if (this->position - 7 * i >= 0)
                {
                    Case nextPosition = m_board.cases[this->position - 7 * i];

                    // Nothing on the way
                    if (nextPosition.type == NOTHING)
                    {
                        this->possibleMoves[movesSize] = this->position - 7 * i;
                        movesSize++;
                    }

                    // Black piece on the way as a white piece
                    if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                    {
                        this->possibleMoves[movesSize] = this->position - 7 * i;
                        movesSize++;
                        // White as white -> break loop and stop looking for moves
                    }
                    else if (nextPosition.m_pawn->getColor() == White && this->position != this->position - 7 * i)
                    {
                        break;
                    }
                }
            }
        }

        // Diagonal
        for (int i = 1; i < 8; i++)
        {
            // Check for overflow
            if (this->position + 7 * i <= 63)
            {
                Case nextPosition = m_board.cases[this->position + 7 * i];
                // Black piece on the way as a white piece
                if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                {
                    this->possibleMoves[movesSize] = this->position + 7 * i;
                    movesSize++;
                    break;
                    // White piece on the way as white
                }
                else if (nextPosition.m_pawn->getColor() == White)
                {
                    break;
                };

                // Nothing on the way
                if (nextPosition.type == NOTHING)
                {
                    this->possibleMoves[movesSize] = this->position + 7 * i;
                    movesSize++;
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            // Check for overflow
            if (this->position - 7 * i >= 0)
            {
                Case nextPosition = m_board.cases[this->position - 7 * i];

                // Nothing on the way
                if (nextPosition.type == NOTHING)
                {
                    this->possibleMoves[movesSize] = this->position - 7 * i;
                    movesSize++;
                }

                // Black piece on the way as a white piece
                if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                {
                    this->possibleMoves[movesSize] = this->position - 7 * i;
                    movesSize++;
                    // White as white -> break loop and stop looking for moves
                }
                else if (nextPosition.m_pawn->getColor() == White && this->position != this->position - 7 * i)
                {
                    break;
                }
            }
        }
        // Horizontal
        for (int i = 1; i < 8; i++)
        {
            // Check for overflow
            if (this->position + 9 * i <= 63)
            {
                Case nextPosition = m_board.cases[this->position + 9 * i];
                // Black piece on the way as a white piece
                if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                {
                    this->possibleMoves[movesSize] = this->position + 9 * i;
                    movesSize++;
                    break;
                    // White piece on the way as white
                }
                else if (nextPosition.m_pawn->getColor() == White)
                {
                    break;
                };

                // Nothing on the way
                if (nextPosition.type == NOTHING)
                {
                    this->possibleMoves[movesSize] = this->position + 9 * i;
                    movesSize++;
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            // Check for overflow
            if (this->position - 9 * i >= 0)
            {
                Case nextPosition = m_board.cases[this->position - 9 * i];

                // Nothing on the way
                if (nextPosition.type == NOTHING)
                {
                    this->possibleMoves[movesSize] = this->position - 9 * i;
                    movesSize++;
                }

                // Black piece on the way as a white piece
                if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
                {
                    this->possibleMoves[movesSize] = this->position - 9 * i;
                    movesSize++;
                    // White as white -> break loop and stop looking for moves
                }
                else if (nextPosition.m_pawn->getColor() == White && this->position != this->position - 9 * i)
                {
                    break;
                }
            }
        }
        // Horizontal moves
        for (int i = 1; i < 8; i++)
        {
            Case nextPosition = m_board.cases[this->position - i];

            if (nextPosition.type == NOTHING)
            {
                this->possibleMoves[movesSize] = this->position - i;
                movesSize++;
            }

            // Black piece
            if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
            {
                this->possibleMoves[movesSize] = this->position - i;
                movesSize++;
                break;
            }

            // White piece
            if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == White)
            {
                break;
            }

            if (this->position - i % 8 == 0)
                break;
        }
        for (int i = 1; i < 8; i++)
        {

            Case nextPosition = m_board.cases[this->position + i];

            // Nothing in front
            if (nextPosition.type == NOTHING)
            {
                this->possibleMoves[movesSize] == i;
                movesSize++;
            }

            // Black pawn in front
            if (nextPosition.type != NOTHING && nextPosition.m_pawn->getColor() == Black)
            {
                this->possibleMoves[movesSize] == i;
                movesSize++;
                break;
                // White pawn in front
            }
            else if (nextPosition.m_pawn->getColor() == White)
            {
                break;
            }

            // arrived at the right side: exit loop
            if (this->position + i % 7 == 0)
                break;
        }
    }
}