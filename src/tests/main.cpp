#include "board/board.h"
#include "pawns/knight.hpp"
#include "pawns/fool.hpp"
#include "pawns/rook.hpp"
#include "pawns/pawn.hpp"

int main(){ 
    Board board;    
    //Fool* test_fool  = new Fool(White, 1);

    static_cast<Rook*>(board.cases[56].m_pawn)->checkMoves(board);    
    static_cast<Knight*>(board.cases[57].m_pawn)->checkMoves(board);    
    static_cast<Fool*>(board.cases[58].m_pawn)->checkMoves(board);    
    static_cast<Pawn*>(board.cases[48].m_pawn)->checkMoves(board);    

    return 0;
}