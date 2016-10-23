//
//  gui.cpp
//  Pong
//
//  Created by Zach Lite on 10/23/16.
//  Copyright © 2016 zach. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "gui.h"


GUI::GUI() {

}

GUI::~GUI() {
    
}

bool GUI::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL video initialization failed: %s\n", SDL_GetError());
        return false;
    }
    
    if (!IMG_Init(IMG_INIT_PNG)) {
        fprintf(stderr, "SDLImage PNG initialization failed: %s\n", IMG_GetError());
        return false;
    }
    
    this->window = SDL_CreateWindow("Pong", 0, 0, GUI::SCREEN_WIDTH, GUI::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!this->window) {
        fprintf(stderr, "SDL window creation failed: %s\n", SDL_GetError());
        return false;
    }
    
    this->surface = SDL_GetWindowSurface(this->window);
    Uint32 color_map = SDL_MapRGB(this->surface->format, 0xff, 0x00, 0xff);
    SDL_FillRect(this->surface, NULL, color_map);
    
    std::cout << "gui initialized" << std::endl;
    return true;
}

void GUI::Destroy() {
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

SDL_Surface * GUI::LoadImage(std::string path) {
    SDL_Surface *img = IMG_Load(path.c_str());
    if(img == NULL) {
        fprintf(stderr, "Unable to load image %s! SDL_Image Error: %s\n", path.c_str(), IMG_GetError());
    }
    return img;
}

void GUI::Render(SDL_Surface *surface, SDL_Rect rect) {
    std::cout << "rendering surface" << std::endl;
    SDL_BlitSurface(surface, NULL, this->surface, &rect);
    SDL_UpdateWindowSurface(this->window);
}



void GUI::PollEvents() {
    std::cout << "omg polling" << std::endl;
}
//
//void Pong::PollEvents(SDL_Event event) {
//    while (SDL_PollEvent(&event)) {
//        
//        switch (event.type) {
//            case SDL_QUIT:
//                this->quit = true;
//                break;
//                
//            case SDL_KEYUP:
//                this->HandleKeyUp(event);
//                break;
//                
//            default:
//                break;
//        }
//        
//    }
//}
//
//void Pong::HandleKeyUp(SDL_Event event) {
//    switch (event.key.keysym.sym) {
//        case SDLK_UP:
//            printf("up key pressed!\n");
//            break;
//            
//        case SDLK_DOWN:
//            printf("down key pressed!\n");
//            break;
//            
//        default:
//            break;
//    }
//    
//}
//

