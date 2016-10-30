//
//  pong.cpp
//  Pong
//
//  Created by Zach Lite on 10/20/16.
//  Copyright © 2016 zach. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <time.h>       
#include "SDL2/SDL.h"
#include "pong.h"

Pong::Pong() {
    
}

Pong::~Pong() {
    
}

bool Pong::Initialize() {
    srand((unsigned int)time(NULL));

    if(!this->gui.Initialize()){
        return false;
    }
    
    this->net = gui.LoadTexture("Pong/img/net.png");

    this->player_1.Initialize(PLAYER_1, gui.LoadTexture("Pong/img/paddle.png"));
    this->player_2.Initialize(PLAYER_2, gui.LoadTexture("Pong/img/paddle.png"));
    this->player_1_score = gui.CreateText("0");
    this->player_2_score = gui.CreateText("0");
    
    this->ball.texture = gui.LoadTexture("Pong/img/ball.png");
    this->ResetBall();
    
    return true;
}


void Pong::Destroy() {
    gui.Destroy();
}

void Pong::Start() {
    SDL_Event event;
    while (!this->quit) {
        
        int frame_start_time = SDL_GetTicks();
    
        // handle events
        this->ProcessInput(event);
    
        // handle game logic
        this->MoveBall();
        this->CheckForGoal();
    
        // render textures
        gui.PrepareRender();
        
        gui.RenderTexture(this->player_1.GetPaddle().texture, this->player_1.GetPaddle().rect);
        gui.RenderTexture(this->player_2.GetPaddle().texture, this->player_2.GetPaddle().rect);
        gui.RenderTexture(this->ball.texture, this->ball.rect);
        gui.RenderTexture(this->net, {GUI::SCREEN_WIDTH/2 - 1, 0, 2, GUI::SCREEN_HEIGHT});
        gui.RenderTexture(this->player_1_score, {100, 30, 50, 80});
        gui.RenderTexture(this->player_2_score, {GUI::SCREEN_WIDTH - 100 - 50, 30, 50, 80});
        
        gui.Update();
        
        int frame_time = SDL_GetTicks() - frame_start_time;
        if (frame_time < GUI::SECONDS_PER_FRAME) {
            SDL_Delay(GUI::SECONDS_PER_FRAME - frame_time);
        }
    }
}

void Pong::MoveBall() {
    // if a ball hits a wall, reverse y
    if (this->ball.rect.y <= 0 ||
        this->ball.rect.y >= GUI::SCREEN_HEIGHT - this->ball.rect.h) {
        this->ball.vy *= -1;
    }
    
    // if ball hits paddle, reverse x
    const SDL_Rect paddle_1_rect = this->player_1.GetPaddle().rect;
    const SDL_Rect paddle_2_rect = this->player_2.GetPaddle().rect;
    
    if (SDL_HasIntersection(&paddle_1_rect, &this->ball.rect) ||
        SDL_HasIntersection(&paddle_2_rect, &this->ball.rect)) {
        this->ball.vx *= -1;
        
        // adjust the vy based on where the ball hits the paddle
        if (this->ball.rect.x < GUI::SCREEN_WIDTH / 2) {
            if (this->ball.rect.y + (this->ball.rect.h / 2.0) < paddle_1_rect.y + (paddle_1_rect.h / 2.0)) {
                if (this->ball.vy > 0) {
                    this->ball.vy *= -1;
                }
            } else {
                if (this->ball.vy < 0) {
                    this->ball.vy *= -1;
                }
            }
        } else {
            if (this->ball.rect.y + (this->ball.rect.h / 2.0) < paddle_2_rect.y + (paddle_2_rect.h / 2.0)) {
                if (this->ball.vy > 0) {
                    this->ball.vy *= -1;
                }
            } else {
                if (this->ball.vy < 0) {
                    this->ball.vy *= -1;
                }
            }
        }
    
        
        // add a little noise
        float y_noise = (rand() % 1000) / 600.0f;

        if (this->ball.vy < 0) {
            this->ball.vy += (y_noise * -1);
        } else {
            this->ball.vy += y_noise;
        }
    }
    
    
    this->ball.rect.x += this->ball.vx;
    this->ball.rect.y += this->ball.vy;
}


void Pong::CheckForGoal() {
    if (this->ball.rect.x <= 0) {
        printf("player 2 scored!\n");
        this->player_2.Score();
        int score = this->player_2.GetScore();
        this->player_2_score = gui.CreateText(std::to_string(score));
        this->ResetBall();
        
    } else if (this->ball.rect.x >= GUI::SCREEN_WIDTH - this->ball.rect.w) {
        printf("player 1 scored!\n");
        this->player_1.Score();
        int score = this->player_1.GetScore();
        this->player_1_score = gui.CreateText(std::to_string(score));
        this->ResetBall();
    }
}

void Pong::ResetBall() {
    this->ball.rect = {static_cast<int>(GUI::SCREEN_WIDTH / 2.0f - (BALL_WIDTH / 2.0f)),
                       static_cast<int>(GUI::SCREEN_HEIGHT / 2.0f - (BALL_HEIGHT / 2.0f)), BALL_WIDTH, BALL_HEIGHT};
    
    float vy = rand() % 2;
    float vx = rand() % 2;
    
    if (vy == 0) {
        this->ball.vy = -1;
    } else {
        this->ball.vy = 1;
    }
    
    if (vx == 0) {
        this->ball.vx = -5;
    } else {
        this->ball.vx = 5;
    }
    
}


void Pong::ProcessInput(SDL_Event e) {
    while (SDL_PollEvent(&e)) {
        
        if (e.type == SDL_QUIT ||
           (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
            printf("see ya\n");
            this->quit = true;
        }
    
        this->player_1.HandleEvents(e);
        this->player_2.HandleEvents(e);
    }
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    this->player_1.HandleContinuousEvents(state);
    this->player_2.HandleContinuousEvents(state);
}
