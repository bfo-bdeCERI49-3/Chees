#pragma once

#include "../board/board.h"

// Color Enumeration
enum Color {
    Black = 0,
    White
};

// Base Piece
class IPiece {
    public:
        inline bool isTaken()   { return this->isPieceTaken; };         // Check if the piece was taken or not 
        inline void taken()     { this->isPieceTaken = true; };         // Set the piece as taken
        int move();                                                     // To override in each piece class

    private:
        Color   color;                   // Color of the piece
        bool    isPieceTaken { false };  // True the piece was taken
        int position;
};