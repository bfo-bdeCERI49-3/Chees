#pragma once 
#include "pawns/IPiece.hpp"

class Fool : public IPiece  {
    public:
        Fool ();

        int move( Board& );                                        // To override in each piece class
        void checkMoves( Board& );
    private: 
        const int allowedMoves[4] = { 7, 9, -7, -9};            // Possible diagonals move
        int  possibleMoves[16];
};