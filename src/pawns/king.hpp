#pragma once 

class King : Piece {
    public:
        inline bool isTaken() { return this->taken; };      // Check if the piece was taken or not 
        inline void taken() { this->taken = true; };        // Set the piece as taken
        
        int move();                                         // To override in each piece class
}