//
// Created by Notoverflow on 3/30/23.
//

#include "board.h"
#include "pawns/rook.hpp"
#include "pawns/knight.hpp"
#include "pawns/fool.hpp"
#include "pawns/queen.hpp"
#include "pawns/king.hpp"
#include "pawns/pawn.hpp"


Board::Board() {
    for (int i = 0; i < 64; i++) {
        cases[i] = new Case();
        if (i == 0 || i == 7) {

            cases[i]->m_pawn = new Rook(White);
        } else if (i == 56 || i == 63) {
            cases[i]->m_pawn = new Rook(Black);
        } else if (i == 1 || i == 6) {
            cases[i]->m_pawn = new Knight(White);
        } else if (i == 57 || i == 62) {
            cases[i]->m_pawn = new Knight(Black);
        }else if (i == 2 || i == 5) {
            cases[i]->m_pawn = new Fool(White);
        } else if (i == 58 || i == 61) {
            cases[i]->m_pawn = new Fool(Black);
        }else if (i == 3) {
            cases[i]->m_pawn = new Queen(White);
        } else if (i == 59) {
            cases[i]->m_pawn = new Queen(Black);
        }else if (i == 4) {
            cases[i]->m_pawn = new King(White);
        } else if (i == 60) {
            cases[i]->m_pawn = new King(Black);
        }else if (i >= 8 && i <= 15) {
            cases[i]->m_pawn = new Pawn(White);
        } else if (i >= 48 && i <= 55) {
            cases[i]->m_pawn = new Pawn(Black);
        }else {
            cases[i]->m_pawn = nullptr;
        }


    }


}
