#pragma once
#include "IPiece.h"

class King : IPiece {
    public:
        int move();             // To override in each piece class
        void checkMoves(board &board);


    private:
        const int allowedMoves[8] = { 1, -1, 8, -8, 7, -7, 9, -9 };     // Allowed moves as King
        int possibleMoves[8];                                           // 
};