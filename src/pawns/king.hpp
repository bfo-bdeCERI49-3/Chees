#pragma once
#include "pawns/IPiece.hpp"


class King : public IPiece {
    public:
        int move(Board&);                                        // To override in each piece class
};