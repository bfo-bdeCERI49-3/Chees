#pragma once 
#include "pawns/IPiece.hpp"

class Fool : public IPiece  {
    public:
        Fool(Color color, PieceType type, size_t size, int *allowedMoves, int *possibleMoves);

    int move(Board&);                                       // To override in each piece class
    private: 
        const int allowedMoves[4] = { 7, 9, -7, -9};            // Possible diagonals move
        int  possibleMoves[16];
};