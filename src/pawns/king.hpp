#pragma once
#include "IPiece.hpp"
#include "../board/board.h"


class King : public IPiece {
    public:
        King ( Color, size_t );
        ~King();

        int move(Board&);                                       // To override in each piece class
        void checkMoves( Board& );

        inline int* getPossibleMoves() { return possibleMoves; }
    private:
        const int allowedMoves[8] = {-1, -9, -8, -7, 1, 9, 8, 7};
        int possibleMoves[8];
        bool mate { false };
};