#pragma once 
#include "pawns/IPiece.h"

class Fool : public IPiece  {
    public:
        int move(Board&)                                        // To override in each piece class
    private: 
        const int allowedMoves[4] = { 7, 9, -7, -9};            // Possible diagonals move
        int  possibleMoves[16];
};