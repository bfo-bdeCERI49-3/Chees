#pragma once
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
        IPiece(Color, PieceType);

        inline bool isTaken() { return this->taken; };      // Check if the piece was taken or not 
        inline void setTaken() { this->taken = true; };        // Set the piece as taken
        
        virtual int move(Board&) = 0;                                         // To override in each piece class
    protected:
        Color   color { White };     // Color of the piece
        bool    taken { false };    // True the piece was taken
        int  position;
};