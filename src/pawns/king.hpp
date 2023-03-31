#pragma once
#include "IPiece.hpp"
#include "../board/board.h"


class King : public IPiece {
    public:
        King ( Color, size_t );
        ~King();

        int move(Board&);                                        // To override in each piece class
};