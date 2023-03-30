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
        // Color, PieceType, size_t size of our array moves;
        IPiece(Color, PieceType, size_t);

        inline bool isTaken() { return this->taken; };      // Check if the piece was taken or not 

        inline void setTaken() { this->taken = true; };        // Set the piece as taken

        virtual int move( Board& ) = 0;                                         // To override in each piece class

        void checkMoves( Board& );
    protected:
        Color   color { White };        // Color of the piece
        bool    taken { false };        // True the piece was taken

        int* allowed_moves { nullptr }; // Should set-up at constructor 
        size_t allowed_moves_size { 0 };

        int* possibleMoves { nullptr };

        int  position;
};