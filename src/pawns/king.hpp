#pragma once
#include "pawns/IPiece.hpp"


class King : public IPiece {
    public:
        King ( Color );
        ~King();
        
        int move(Board&);                                        // To override in each piece class
};