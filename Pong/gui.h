//
//  gui.h
//  Pong
//
//  Created by Zach Lite on 10/23/16.
//  Copyright © 2016 zach. All rights reserved.
//

#ifndef gui_h
#define gui_h

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

class GUI {
    
private:
    SDL_Window *window;
    SDL_Surface *surface;
    SDL_Renderer *renderer;
    TTF_Font *font;
    
public:
    static const int SCREEN_HEIGHT = 480;
    static const int SCREEN_WIDTH = 640;
    static const int FRAMES_PER_SECOND = 60;
    constexpr static const float SECONDS_PER_FRAME = (1 * 1000) / GUI::FRAMES_PER_SECOND;
    
    GUI();
    ~GUI();
    bool Initialize();
    void Destroy();
    SDL_Texture * LoadTexture(std::string path);
    SDL_Texture * CreateText(std::string s);
    
    void PrepareRender();
    void RenderTexture(SDL_Texture *texture, SDL_Rect rect);
    void Update();

};


#endif /* gui_h */
