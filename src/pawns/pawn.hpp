#pragma once 

#include "pawns/IPiece.hpp"

class Pawn : public IPiece {
    public:
        Pawn ( Color );
        ~Pawn();

        int move( Board& );                                        // To override in each piece class
        void checkMoves( Board& );
    private: 
        bool first_move { true };

        const int allowedMoves[4] = { 7, 8, 9, 16 };
        int possibleMoves[4];                                    // En Passant, First move;
        int possibleMovesSize = 0;
};