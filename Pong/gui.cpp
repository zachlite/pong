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
    
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->renderer) {
        fprintf(stderr, "SDL Renderer creation failed: %s\n", SDL_GetError());
        return false;
    }
    
    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    
//    this->surface = SDL_GetWindowSurface(this->window);
//    Uint32 color_map = SDL_MapRGB(this->surface->format, 0x00, 0x00, 0x00);
//    SDL_FillRect(this->surface, NULL, color_map);
    
    std::cout << "gui initialized" << std::endl;
    return true;
}

void GUI::Destroy() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    IMG_Quit();
    SDL_Quit();
}


SDL_Texture * GUI::LoadTexture(std::string path) {
    SDL_Surface *img = IMG_Load(path.c_str());
    if(img == NULL) {
        fprintf(stderr, "Unable to load image %s! SDL_Image Error: %s\n", path.c_str(), IMG_GetError());
        return NULL;
    }
    
    return SDL_CreateTextureFromSurface(this->renderer, img);
}

SDL_Surface * GUI::LoadImage(std::string path) {
    SDL_Surface *img = IMG_Load(path.c_str());
    if(img == NULL) {
        fprintf(stderr, "Unable to load image %s! SDL_Image Error: %s\n", path.c_str(), IMG_GetError());
    }
    
    SDL_Surface *optimized_img = SDL_ConvertSurface(img, this->surface->format, NULL);
    if(optimized_img == NULL){
        fprintf(stderr, "Unable to optimize image %s! SDL_Image Error: %s\n", path.c_str(), SDL_GetError());
        SDL_FreeSurface(optimized_img);
        return img;
    } else {
        SDL_FreeSurface(img);
        return optimized_img;
    }
}

void GUI::PrepareRender() {
    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(this->renderer);
}

void GUI::Render(SDL_Surface *surface, SDL_Rect rect) {
//    SDL_FillRect(this->surface, NULL, SDL_MapRGB(this->surface->format, 0, 0, 0));
    SDL_BlitSurface(surface, NULL, this->surface, &rect);
    SDL_UpdateWindowSurface(this->window);
}

void GUI::RenderTexture(SDL_Texture *texture, SDL_Rect rect) {
    SDL_RenderCopy(this->renderer, texture, NULL, &rect);
}

void GUI::Update() {
    SDL_RenderPresent(this->renderer);
}
