#pragma once 

#include "pawns/IPiece.h"

class Pawn : public IPiece {
    public:
        int move(Board&);                                        // To override in each piece class
        void checkMoves(Board&);

    private: 
        bool first_move { true };
        const int allowedMoves[2] = { 8, 16 };
        int possibleMoves[2];                                    // En Passant, First move;
};