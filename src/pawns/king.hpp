#pragma once 

class King : public IPiece {
    public:
        int move();                                         // To override in each piece class
};