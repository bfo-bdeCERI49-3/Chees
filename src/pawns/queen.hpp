#pragma once 

class Queen : public IPiece {
    public:
        int move();                                         // To override in each piece class
};