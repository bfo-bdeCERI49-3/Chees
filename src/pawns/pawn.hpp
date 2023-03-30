#pragma once 

#include "pawns/IPiece.hpp"

class Pawn : public IPiece {
    public:
        Pawn ( Color );
        ~Pawn();

        int move( Board& );                                        // To override in each piece class
    private: 
        bool first_move { true };

        const int allowedMoves[2] = { 8, 16 };
        int possibleMoves[4];                                    // En Passant, First move;
};