#pragma once 

class King : public IPiece {
    public:
        Kign();

        int move( Board& );                                        // To override in each piece class
        void checkMoves( Board& );
};