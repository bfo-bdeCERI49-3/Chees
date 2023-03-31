//
// Created by Notoverflow on 3/30/23.
//




#pragma once
#include "pawns/IPiece.hpp"

struct Case {
    IPiece* m_pawn { nullptr };
    PieceType type { NOTHING };
};

class Board {
    public:
        Board();
        ~Board();
        
        Case* cases;
        private:
            bool checkMates();
            
};