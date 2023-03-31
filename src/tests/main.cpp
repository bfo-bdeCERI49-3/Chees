#include "board/board.h"
#include "pawns/knight.hpp"
#include "pawns/rook.hpp"
#include "pawns/pawn.hpp"
#include "front.h"

int main(){
    front app;

    while(!app.is_finish()) {

        app.doInput();
        app.render();
        app.clear();
        SDL_Delay(16);
    }

    return 0;
}