#pragma once
#include "IPiece.hpp"
#include "../board/board.h"


class King : public IPiece {
    public:
        int move();             // To override in each piece class
        void checkMoves(board &board);


    private:
        const int allowedMoves[8] = { 1, 8, -8, 7, -7, 9, -9 };     // Allowed moves as King
        int possibleMoves[8];                                           // 
};