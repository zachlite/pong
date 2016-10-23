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

//Pong
//
//private:
//Window window
//
//
//public:
//Initialize()
//Start()
//Destroy()
//
//
//________________________
//
//
//Window
//
//private:
//
//
//public:
//Initialize()
//Destroy()
//Render()
//PollEvents()
//
//
//
//





Pong::Pong() {
    
}

Pong::~Pong() {
    
}

bool Pong::Initialize() {
    if(!gui.Initialize()){
        return false;
    }
    
    // put an image on the screen
    SDL_Surface *img = gui.LoadImage("Pong/img/test.png");
    SDL_Rect img_rect;
    img_rect.x = 23;
    img_rect.y = 31;
    img_rect.w = 100;
    img_rect.h = 20;
    gui.Render(img, img_rect);
    
    
    return true;
}

void Pong::Destroy() {
    gui.Destroy();
}

void Pong::Start() {

//    SDL_Event event;
    std::string poll;
    
    while (!this->quit) {
        
        int frame_start_time = SDL_GetTicks();
    
//         handle events
//        this->PollEvents(event);
        
    
        // do things
    
        
        // render
//        this->Render();
        SDL_Delay(10);
        
        
    
        int frame_time = SDL_GetTicks() - frame_start_time;
        
        if (frame_time < GUI::SECONDS_PER_FRAME) {
            SDL_Delay(GUI::SECONDS_PER_FRAME - frame_time);
        }
        
    }
}



