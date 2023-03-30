#pragma once 
#include "Piece.h"

class Fool : public IPiece  {
    public:
        int move();                                         // To override in each piece class
};