#pragma once 

class Knight : public IPiece {
    public:
        int move(Board&);                                         // To override in each piece class
    private:
        const int allowedMoves[8] = { -10, 6, 15, 17, 10, -6, -15, -17};
        int possibleMoves[8];
};