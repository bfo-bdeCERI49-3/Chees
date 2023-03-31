#pragma once 
#include "pawns/IPiece.hpp"
#include "../board/board.h"

class Queen : public IPiece {
    public:
    Queen ( Color, size_t );
    Queen();

    ~Queen();

        int move( Board&, int , int );
        void checkMoves(Board&);                                         // To override in each piece class

        bool isPossibleMoves( Board&, int );

private:
        const int allowedMovesBishop[4] = {-9, -7, 9, 7};
        const int allowedMovesRook[14] = {1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 32, 40, 48, 56};
        int possibleMoves[30];
        bool first_move { true };
};