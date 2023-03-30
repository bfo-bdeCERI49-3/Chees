#pragma once 

class Rook : public IPiece {
    public:
        int move(Board&);                                   // To override in each piece class

    private:
        const int allowedMoves[7] = { 1, 2, 3, 4, 5, 6, 7 };
        int possibleMoves[14];                              // En Passant, First move;
};