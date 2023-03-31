//
// Created by Notoverflow on 3/30/23.
//

#include "board.h"
#include "pawns/rook.hpp"
#include "pawns/knight.hpp"
#include "pawns/bishop.hpp"
#include "pawns/queen.hpp"
#include "pawns/king.hpp"
#include "pawns/pawn.hpp"

Board::~Board(){
    for (size_t i = 0; i < 64; i++) {
        if ( cases[i].m_pawn != nullptr ) {
            delete cases[i].m_pawn;
        }
    }
    delete[] cases;
}

Board::Board() {

    cases = new Case[64];

    for (size_t i = 0; i < 64; i++) {
        if (i == 0 || i == 7) {
            cases[i].m_pawn = new Rook(White, i);
            cases[i].type = ROOK; 
        } else if (i == 56 || i == 63) {
            cases[i].m_pawn = new Rook(Black, i);
            cases[i].type = ROOK; 
        } else if (i == 1 || i == 6) {
            cases[i].m_pawn = new Knight(White, i);
            cases[i].type = KNIGHT; 
        } else if (i == 57 || i == 62) {
            cases[i].m_pawn = new Knight(Black, i);
            cases[i].type = KNIGHT; 
        }else if (i == 2 || i == 5) {
            cases[i].m_pawn = new Bishop(White, i);
            cases[i].type = FOOL; 
        } else if (i == 58 || i == 61) {
            cases[i].m_pawn = new Bishop(Black, i);
            cases[i].type = FOOL; 
        }else if (i == 3) {
            cases[i].m_pawn = new Queen(White, i);
            cases[i].type = QUEEN; 
        } else if (i == 59) {
            cases[i].m_pawn = new Queen(Black, i);
            cases[i].type = QUEEN; 
        }else if (i == 4) {
            cases[i].m_pawn = new King(White, i);
            cases[i].type = KING; 
        } else if (i == 60) {
            cases[i].m_pawn = new King(Black, i);
            cases[i].type = KING;
        }else if (i >= 8 && i <= 15) {
            cases[i].m_pawn = new Pawn(White, i);
            cases[i].type = PAWN;
        } else if (i >= 48 && i <= 55) {
            cases[i].m_pawn = new Pawn(Black, i);
            cases[i].type = PAWN;
        }else {
            cases[i].m_pawn = nullptr;
        }
    }
}
