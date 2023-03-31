#include "board/board.h"
#include "pawns/knight.hpp"
#include "pawns/fool.hpp"
#include "pawns/rook.hpp"
#include "pawns/pawn.hpp"
#include "front.h"

int main(){
    front app;

    while(!app.is_finish()) {
        app.clear();
        app.doInput();
        app.render();
    }

    return 0;
}