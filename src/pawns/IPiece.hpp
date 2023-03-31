#pragma once
#include <cstddef>

class Board;

// Color Enumeration
enum Color {
    Black = 0,
    White,
    None,
};

enum PieceType {
    NOTHING = 0,
    PAWN,
    KNIGHT,
    FOOL,
    ROOK,
    QUEEN,
    KING,
};
// Base Piece

class IPiece {
    public:
        
        inline bool isTaken() { return this->taken; };      // Check if the piece was taken or not 
        inline void setTaken() { this->taken = true; };        // Set the piece as taken
        virtual int move( Board&, int , int ) = 0;                                         // To override in each piece class
        void checkMoves( Board& );

        int getColor() { return color; }
        virtual bool isPossibleMoves( Board&, int ) = 0;


    protected:
        Color   color { None };        // Color of the piece
        bool    taken { false };        // True the piece was taken
        int  position;
};