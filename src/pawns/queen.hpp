#pragma once 
#include "pawns/IPiece.hpp"

class Queen : public IPiece {
    public:
        Queen ( Color );
        ~Queen();

        int move(Board&);                                         // To override in each piece class
    private:

};