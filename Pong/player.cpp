//
//  player.cpp
//  Pong
//
//  Created by Zach Lite on 10/26/16.
//  Copyright © 2016 zach. All rights reserved.
//

#include <stdio.h>
#include "player.h"
#include "gui.h"

Player::Player() {

}

Player::~Player() {
    
}

void Player::Initialize(PlayerNumber player_number, SDL_Texture *paddle_texture) {
    this->score = 0;
    this->paddle.texture = paddle_texture;
    this->player_number = player_number;
    
    if (player_number == PLAYER_1) {
        this->paddle.rect = {10, 10, 20, 100};
    } else {
        this->paddle.rect = {GUI::SCREEN_WIDTH - 10 - PADDLE_WIDTH, GUI::SCREEN_HEIGHT - 10 - PADDLE_HEIGHT, 20, 100};
    }
}

void Player::Move(Direction dir) {
    if (dir == UP) {
        if (this->paddle.rect.y > 5) {
            this->paddle.rect.y -= PADDLE_SPEED;
        }
    
    } else if (dir == DOWN) {
        if (this->paddle.rect.y < (GUI::SCREEN_HEIGHT - this->paddle.rect.h)) {
            this->paddle.rect.y += PADDLE_SPEED;
        }
    }
}

Paddle Player::GetPaddle() {
    return this->paddle;
}

void Player::HandleEvents(SDL_Event e) {
    
}

void Player::HandleContinuousEvents(const Uint8 *key_states) {
    if (this->player_number == PLAYER_1) {
        
        if (key_states[SDL_SCANCODE_W]) {
            this->Move(UP);
        } else if (key_states[SDL_SCANCODE_S]) {
            this->Move(DOWN);
        }
        
    } else {
        
        if(key_states[SDL_SCANCODE_DOWN]){
            this->Move(DOWN);
        } else if (key_states[SDL_SCANCODE_UP]){
            this->Move(UP);
        }
    }
}
