#pragma once 
#include "pawns/IPiece.hpp"

class Rook : public IPiece {
    public:
        Rook( Color, size_t );
        ~Rook();

        int move( Board&, int , int );                                   // To override in each piece class
        void checkMoves(Board&);

        bool isPossibleMoves( Board&, int );

    private:
        const int allowedMoves[14] = {1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 32, 40, 48, 56};
        int possibleMoves[16];
};