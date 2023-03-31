//
// Created by Notoverflow on 3/30/23.
//

#include <iostream>
#include "front.h"
#include "pawns/IPiece.hpp"
#include "SDL2/SDL_image.h"

void front::doInput() {
    SDL_Event event;
    int mouseX = -1, mouseY = -1;

    while (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT:
                state_end = true;
                break;
            case SDL_MOUSEBUTTONDOWN: {
                SDL_GetMouseState(&mouseX, &mouseY);
                if ( mouseX >= 10 && mouseX <= 1040 && mouseY >= 10 && mouseY <=  1040 ) {

                    int m_j = (mouseY / 130 );
                    int m_i = (mouseX / 130) ;

                    int i = m_j * 8 + m_i;
                    std::cout << m_j << " " << m_i << " " << i << std::endl;
                    if ( current_pos == -1 && m_board.cases[i].type != NOTHING) {
                        current_pos = i;
                    } else if ( current_pos != -1 ) {
                        if ( current_pos != i) {
                            if m_board.cases[current_pos].m_pawn->isPossibleMoves(i) {
                                m_board.cases[current_pos].m_pawn->move(m_board, current_pos, i);
                            }
                        }
                        current_pos = -1;
                    }
                }
                }
                break;
            default:
                break;
        }
    }
}

void front::render() {

    // start pos y = 700; x = 100
    // end pos y = 140; x = 1060
    // case x = 120, y = 80
    int y = 0;
    int x = 0;

    int wb =  0;

    SDL_SetRenderDrawColor(renderer, 33, 77, 77, 255);
    draw_texture(entities[0].texture, 1040, 720, 0, 0);

    for (int i = 0; i < 64; i++) {
        if  ( i != 0 && i % 8 == 0) {
            y += 130;
            x = 0;
        }

        if (  m_board.cases[i].type != NOTHING && m_board.cases[i].m_pawn->getColor() == Black){
            wb = 6;
        }

        if( m_board.cases[i].type == PieceType::ROOK ) {
            draw_texture(entities[5 + wb].texture, 150, 160, x, y);
        } else if ( m_board.cases[i].type == PieceType::QUEEN ) {
            draw_texture(entities[2 + wb].texture, 150, 160, x, y);
        } else if ( m_board.cases[i].type == PieceType::KING ) {
            draw_texture(entities[1 + wb].texture, 150, 160, x, y);
        } else if ( m_board.cases[i].type == PieceType::FOOL ) {
            draw_texture(entities[3 + wb ].texture, 150, 160, x, y);
        } else if ( m_board.cases[i].type == PieceType::PAWN) {
            draw_texture(entities[6 + wb].texture, 150, 160, x, y);
        } else if ( m_board.cases[i].type == PieceType::KNIGHT) {
            draw_texture(entities[4 + wb].texture, 150, 160, x, y);
        }

        x += 130;
        wb = 0;
    }


    SDL_RenderPresent(renderer);
}

void front::draw_texture(SDL_Texture* texture, int size_x, int size_y, int pos_x, int pos_y) {
    SDL_Rect dest;

    dest.w = size_x;
    dest.h = size_y;
    dest.x = pos_x;
    dest.y = pos_y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void front::clear() {
    SDL_RenderClear(renderer);
}

front::~front() {}


front::front() {
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow("Chees", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1040, 1040, 0);

    if (!window){
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }


    memset(&entities, 0, 14 * sizeof(Entity));
    entities[0].texture = IMG_LoadTexture(renderer, "assets/chessboard.png");
    entities[1].texture = IMG_LoadTexture(renderer, "assets/tile000.png");
    entities[2].texture = IMG_LoadTexture(renderer, "assets/tile001.png");
    entities[3].texture = IMG_LoadTexture(renderer, "assets/tile002.png");
    entities[4].texture = IMG_LoadTexture(renderer, "assets/tile003.png");
    entities[5].texture = IMG_LoadTexture(renderer, "assets/tile004.png");
    entities[6].texture = IMG_LoadTexture(renderer, "assets/tile005.png");
    entities[7].texture = IMG_LoadTexture(renderer, "assets/tile006.png");
    entities[8].texture = IMG_LoadTexture(renderer, "assets/tile007.png");
    entities[9].texture = IMG_LoadTexture(renderer, "assets/tile008.png");
    entities[10].texture = IMG_LoadTexture(renderer, "assets/tile009.png");
    entities[11].texture = IMG_LoadTexture(renderer, "assets/tile010.png");
    entities[12].texture = IMG_LoadTexture(renderer, "assets/tile011.png");

}
