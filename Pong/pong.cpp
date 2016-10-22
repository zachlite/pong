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
    
    this->quit = false;
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL video initialization failed: %s", SDL_GetError());
        return false;
    }
    
    this->window = SDL_CreateWindow("Pong", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!this->window) {
        fprintf(stderr, "SDL window creation failed: %s", SDL_GetError());
        return false;
    }
    
    this->surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xff, 0x00, 0xee));
    SDL_UpdateWindowSurface(window);
    
    return true;
}

void Pong::Start() {
    
    int frames = 0;
    SDL_Event event;
    
    while (!this->quit) {
        
        int frame_start_time = SDL_GetTicks();
    
        // handle events
        this->PollEvents(event);
        
    
        // do things
    
        
        // render
        this->Render();
        
        
        float average_fps = frames / (SDL_GetTicks() / 1000.0f);
        printf("%f\n", average_fps);
        frames++;
        
        int frame_time = SDL_GetTicks() - frame_start_time;
        if (frame_time < SECONDS_PER_FRAME) {
            SDL_Delay(SECONDS_PER_FRAME - frame_time);
        }
    }
}

void Pong::PollEvents(SDL_Event event) {
    while (SDL_PollEvent(&event)) {
        
        switch (event.type) {
            case SDL_QUIT:
                this->quit = true;
                break;
                
            case SDL_KEYUP:
                this->HandleKeyUp(event);
                break;
                
            default:
                break;
        }
        
    }
}

void Pong::HandleKeyUp(SDL_Event event) {
    switch (event.key.keysym.sym) {
        case SDLK_UP:
            printf("up key pressed!\n");
            break;
            
        case SDLK_DOWN:
            printf("down key pressed!\n");
            break;
            
        default:
            break;
    }

}

void Pong::Render() {
    // draw everything on screen
}

void Pong::Destroy() {
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}