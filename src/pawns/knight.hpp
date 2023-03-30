#pragma once 

#include "pawns/IPiece.hpp"

class Knight : public IPiece {
    public:
        int move( Board& );                                        // To override in each piece class
        void checkMoves( Board& );
    private:
        const int allowedMoves[4] = { -10, 6, 15, 17};           // 
        int possibleMoves[8];
};