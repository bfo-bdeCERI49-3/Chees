#pragma once
#include "IPiece.hpp"
#include "../board/board.h"


class King : public IPiece {
    public:
        King ( Color, size_t );
        ~King();

        int move( Board&, int , int );                                      // To override in each piece class
        void checkMoves( Board& );

        bool isPossibleMoves( Board&, int );
    private:
        const int allowedMoves[8] = {-1, -9, -8, -7, 1, 9, 8, 7};
        int possibleMoves[8];
        bool mate { false };
};