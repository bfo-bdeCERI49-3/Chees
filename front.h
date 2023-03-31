/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Notoverfl </var/spool/mail/Notoverfl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:24:35 by Notoverfl         #+#    #+#             */
/*   Updated: 2023/03/31 07:24:35 by Notoverfl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Notoverfl </var/spool/mail/Notoverfl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:24:30 by Notoverfl         #+#    #+#             */
/*   Updated: 2023/03/31 07:24:30 by Notoverfl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Notoverfl </var/spool/mail/Notoverfl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:33:58 by Notoverfl         #+#    #+#             */
/*   Updated: 2023/03/31 04:33:58 by Notoverfl        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "board/board.h"
#include "SDL2/SDL.h"
#include <string>

struct Entity {
    int x;
    int y;
    SDL_Texture* texture;
};

class front {
public:
    front();
    ~front();

    void doInput();
    void render();
    void clear();
    void draw_texture(SDL_Texture*, int, int, int, int);

    inline bool is_finish() { return state_end; }
private:
    Board m_board;
    bool state_end = false;

    SDL_Window* window;
    SDL_Renderer* renderer;
    Entity entities[13];

    int current_pos { -1 };
};
