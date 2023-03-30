#pragma once 
#include "pawns/IPiece.hpp"

class Rook : public IPiece {
    public:
        Rook( Color );
        ~Rook();

        int move(Board&);                                   // To override in each piece class
    private:
        int possibleMoves[14];                              // En Passant, First move;
};