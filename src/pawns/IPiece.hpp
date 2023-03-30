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
    protected:
        Color   color { White };        // Color of the piece
        bool    taken { false };        // True the piece was taken

        // Should set-up at child constructor 
        int* allowed_moves { nullptr };
        int* possible_moves { nullptr };
        const size_t allowed_moves_size { 0 };
        size_t possible_move_size { 0 };

        int  position;
};