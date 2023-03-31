#include "pawns/pawn.hpp"
#include "board/board.h"
#include <iostream>

Pawn::Pawn( Color set_color, size_t set_position){
    color = set_color;
    position = set_position;
}

int Pawn::move( Board& m_board, int old_pos, int new_pos){
    m_board.cases[new_pos].m_pawn = m_board.cases[old_pos].m_pawn;
    m_board.cases[new_pos].type = m_board.cases[old_pos].type;


    m_board.cases[old_pos].m_pawn = nullptr;
    m_board.cases[old_pos].type = NOTHING;
}

bool Pawn::isPossibleMoves( Board& m_board, int new_position ) {
    checkMoves(m_board);
    for ( int i = 0; i < 4; i++){
        if ( possibleMoves[i] == new_position ) { 
            return true;
        }
    }
    return false;
}


void Pawn::checkMoves(Board &m_board)
{
    if (this->color == White)
    {
        if (this->first_move)
        {
            if (m_board.cases[this->position + 16].type == NOTHING && m_board.cases[this->position + 8].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position + 16;
                this->possibleMovesSize++;
            }
        }
        if (this->position + 8 <= 64) {
            if (m_board.cases[this->position + 8].type == NOTHING)
            {

                this->possibleMoves[this->possibleMovesSize] = this->position + 8;
                this->possibleMovesSize++;
            }
        }   
        if (this->position % 7 != 0)
        {
            if (m_board.cases[this->position + 9].type != NOTHING && m_board.cases[this->position + 9].m_pawn->getColor() == Black)
            {

                this->possibleMoves[this->possibleMovesSize] = this->position + 9;
                this->possibleMovesSize++;
            }
        }

        if (this->position % 8 != 0)
        {
            if (m_board.cases[this->position + 7].type != NOTHING && m_board.cases[this->position + 7].m_pawn->getColor() == Black)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position + 7;
                this->possibleMovesSize++;
            }
        }
    }
    else if(this->color == Black)
    {
        if (this->first_move)
        {
            if (m_board.cases[this->position - 16].type == NOTHING && m_board.cases[this->position - 8].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position - 16;
                this->possibleMovesSize++;
            }
        }
        if (this->position - 8 >= 0) {
            if (m_board.cases[this->position - 8].type == NOTHING)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position - 8;
                this->possibleMovesSize++;
            }
        } 
        if (m_board.cases[this->position - 8].type == NOTHING)
        {
            this->possibleMoves[this->possibleMovesSize] = this->position - 8;
            this->possibleMovesSize++;
        }
        if (m_board.cases[this->position - 9].type != NOTHING && m_board.cases[this->position - 9].m_pawn->getColor() == White)
        {
            this->possibleMoves[this->possibleMovesSize] = this->position - 9;
            this->possibleMovesSize++;
        }
        if (m_board.cases[this->position - 7].type != NOTHING && m_board.cases[this->position - 7].m_pawn->getColor() == White)
        {
            this->possibleMoves[this->possibleMovesSize] = this->position - 7;
            this->possibleMovesSize++;
        }
        if (this->position % 7 != 0)
        {
            if (m_board.cases[this->position - 9].type != NOTHING && m_board.cases[this->position - 9].m_pawn->getColor() == White)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position - 9;
                this->possibleMovesSize++;
            }
        }

        if (this->position % 8 != 0)
        {
            if (m_board.cases[this->position - 7].type != NOTHING && m_board.cases[this->position - 7].m_pawn->getColor() == White)
            {
                this->possibleMoves[this->possibleMovesSize] = this->position - 7;
                this->possibleMovesSize++;
            }
        }
    }

    for(int i = 0; i < 4; i++){
        std::cout << possibleMoves[i] << ";";
    }
    std::cout << "\n";
}
