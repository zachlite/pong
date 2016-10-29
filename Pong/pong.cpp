//
//  pong.cpp
//  Pong
//
//  Created by Zach Lite on 10/20/16.
//  Copyright © 2016 zach. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"
#include "pong.h"

Pong::Pong() {
    
}

Pong::~Pong() {
    
}

bool Pong::Initialize() {
    
    if(!this->gui.Initialize()){
        return false;
    }
    
    this->player_1.Initialize(PLAYER_1, gui.LoadTexture("Pong/img/test.png"));
    this->player_2.Initialize(PLAYER_2, gui.LoadTexture("Pong/img/test.png"));
    
    return true;
}


void Pong::Destroy() {
    gui.Destroy();
}

void Pong::Start() {

    SDL_Event event;
    std::string poll;
    
    while (!this->quit) {
        
        int frame_start_time = SDL_GetTicks();
    
        // handle events
        this->ProcessInput(event);
    
        gui.PrepareRender();
        
        gui.RenderTexture(this->player_1.GetPaddle().texture, this->player_1.GetPaddle().rect);
        gui.RenderTexture(this->player_2.GetPaddle().texture, this->player_2.GetPaddle().rect);
        
        gui.Update();
        
        int frame_time = SDL_GetTicks() - frame_start_time;
        
        if (frame_time < GUI::SECONDS_PER_FRAME) {
            SDL_Delay(GUI::SECONDS_PER_FRAME - frame_time);
        }
    }
}

void Pong::ProcessInput(SDL_Event e) {
    while (SDL_PollEvent(&e)) {
        
        if (e.type == SDL_QUIT) {
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
