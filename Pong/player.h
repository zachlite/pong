//
//  player.h
//  Pong
//
//  Created by Zach Lite on 10/26/16.
//  Copyright © 2016 zach. All rights reserved.
//

#ifndef player_h
#define player_h

#include <iostream>
#include "SDL2/SDL.h"

typedef enum {
    PLAYER_1,
    PLAYER_2
} PlayerNumber;

typedef enum {
    UP,
    DOWN
} Direction;

struct Paddle {
    SDL_Texture *texture;
    SDL_Rect rect;
};

const int PADDLE_SPEED = 5;
const int PADDLE_WIDTH = 20;
const int PADDLE_HEIGHT = 100;

class Player {

private:
    int score;
    Paddle paddle;
    PlayerNumber player_number;
    
    void Move(Direction dir);

public:
    Player();
    ~Player();

    void Initialize(PlayerNumber player_number, SDL_Texture *paddle_texture);
    Paddle GetPaddle();
    void HandleEvents(SDL_Event e);
    void HandleContinuousEvents(const Uint8 *key_states);
};


#endif /* player_h */
