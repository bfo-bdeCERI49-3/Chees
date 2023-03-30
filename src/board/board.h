//
// Created by Notoverflow on 3/30/23.
//

#pragma once

enum PieceType {
    NOTHING = 0,
    QUEEN,
    FOOL,
    ROOK,
    KNIGHT,
    PAWN,
    KING,
};

struct Case {
    IPiece* m_pawn { nullptr };
    PieceType type { NOTHING };
};

class Board {
    public:

    private: 
        Case* cases; 
};