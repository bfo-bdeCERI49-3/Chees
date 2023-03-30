#pragma once 
#include "pawns/IPiece.hpp"

class Queen : public IPiece {
    public:
        int move(Board&);                                         // To override in each piece class
    private:

};