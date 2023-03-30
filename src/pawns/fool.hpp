#pragma once 
#include "pawns/IPiece.hpp"

class Fool : public IPiece  {
    public:
        Fool(Color);
        ~Fool();

        int move(Board&);                                       // To override in each piece class
    private:
};