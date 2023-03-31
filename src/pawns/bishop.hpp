#pragma once 
#include "pawns/IPiece.hpp"

class Bishop : public IPiece  {
    public:
        Bishop( Color, size_t );
        ~Bishop();

        int move(Board&);                                       // To override in each piece class
        void checkMoves( Board& );
    private:
        const int allowedMoves[4] = {-9, -7, 9, 7};
        int possibleMoves[16];
};