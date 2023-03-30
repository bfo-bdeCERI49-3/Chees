#pragma once 

#include "pawns/IPiece.hpp"

class Knight : public IPiece {
    public:
        Knight ( Color );
        ~Knight();

        int move( Board& );                                        // To override in each piece class
    private:

};