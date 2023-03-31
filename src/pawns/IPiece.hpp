#pragma once
#include <cstddef>

class Board;

// Color Enumeration
enum Color {
    Black = 0,
    White
};

enum PieceType {
    NOTHING = 0,
    QUEEN,
    FOOL,
    ROOK,
    KNIGHT,
    PAWN,
    KING,
};

// Base Piece

class IPiece {
    public:
        
        inline bool isTaken() { return this->taken; };      // Check if the piece was taken or not 
        inline void setTaken() { this->taken = true; };        // Set the piece as taken
        virtual int move( Board& ) = 0;                                         // To override in each piece class
        void checkMoves( Board& );

        int getColor() { return color; }
        virtual bool isPossibleMove( int ) = 0;
    protected:
        Color   color { White };        // Color of the piece
        bool    taken { false };        // True the piece was taken
        int  position;
};