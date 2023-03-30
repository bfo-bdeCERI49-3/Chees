#pragma once 

#include "pawns/IPiece.h"

class Pawn : public IPiece {
    public:
        int move();                                         // To override in each piece class
    private: 
        bool first_move { true };
};