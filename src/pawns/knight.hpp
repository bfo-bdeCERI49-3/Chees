#pragma once 

#include "pawns/IPiece.hpp"

class Knight : public IPiece {
    public:
        Knight ( Color, size_t );
        ~Knight();

        int move( Board& );                                        // To override in each piece class
        void checkMoves( Board& m_board );

        bool isPossibleMoves( Board&, int );

    private:
        const int allowedMoves[8] = { -10, 6, 15, 17, 10, 6, -15, -17};
        int possibleMoves[8];
};