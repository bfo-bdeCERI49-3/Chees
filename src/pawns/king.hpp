#pragma once 

class King : public IPiece {
    public:
        int move(Board&);                                        // To override in each piece class
};