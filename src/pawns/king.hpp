#pragma once
#include "pawns/IPiece.hpp"


class King : public IPiece {
    public:
        King ( Color, size_t );
        ~King();

        int move(Board&);                                       // To override in each piece class
        void checkMoves( Board& );
    private:
        const int allowedMoves[8] = {-1, -9, -8, -7, 1, 9, 8, 7};
        int possibleMoves[8];
        bool mate { false };
};