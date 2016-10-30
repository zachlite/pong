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
    
    if(TTF_Init() == -1) {
        fprintf(stderr,"SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }
    
    this->font = TTF_OpenFont("Pong/fonts/Roboto-Regular.ttf", 28);
    
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
    
    std::cout << "gui initialized" << std::endl;
    return true;
}

void GUI::Destroy() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    TTF_CloseFont(this->font);
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

SDL_Texture * GUI::CreateText(std::string s) {
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, s.c_str(), {0,0,0});
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(this->renderer, textSurface);
    return textTexture;
}

void GUI::PrepareRender() {
    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(this->renderer);
}

void GUI::RenderTexture(SDL_Texture *texture, SDL_Rect rect) {
    SDL_RenderCopy(this->renderer, texture, NULL, &rect);
}

void GUI::Update() {
    SDL_RenderPresent(this->renderer);
}
