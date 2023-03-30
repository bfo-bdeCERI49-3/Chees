#include "board/board.h"
#include "pawns/knight.hpp"
#include "pawns/fool.hpp"
#include "pawns/rook.hpp"

int main(){ 
    Board board;    
    //Fool* test_fool  = new Fool(White, 1);

    static_cast<Rook*>(board.cases[0].m_pawn)->checkMoves(board);    
    static_cast<Knight*>(board.cases[1].m_pawn)->checkMoves(board);    
    static_cast<Fool*>(board.cases[2].m_pawn)->checkMoves(board);    

    return 0;
}