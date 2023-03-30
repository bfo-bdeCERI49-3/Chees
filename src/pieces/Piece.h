#pragma once

// Color Enumeration
enum Color {
    Black = 0,
    White
};

// Base Piece
class IPiece {
    public:
        inline bool isTaken() { return this->taken; };      // Check if the piece was taken or not 
        inline void taken() { this->taken = true; };        // Set the piece as taken
        int move();                                         // To override in each piece class

    private:
        Color   color { NULL };     // Color of the piece
        bool    taken { false };    // True the piece was taken
}