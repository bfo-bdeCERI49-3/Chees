#pragma once 
#include "pawns/IPiece.hpp"
#include "../board/board.h"

class Queen : public IPiece {
    public:
        Queen ( Color, size_t );
        ~Queen();

        int move(Board&);
        void checkMoves(Board&);                                         // To override in each piece class
    private:
        const int allowedMoves[30] = { -1, 1, -7, 7, 8, -8, -9, 9, };
        int possibleMoves[30];
        bool first_move { true };
};