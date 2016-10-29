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

class GUI {
    
private:
    SDL_Window *window;
    SDL_Surface *surface;
    SDL_Renderer *renderer;
    
public:
    static const int SCREEN_HEIGHT = 480;
    static const int SCREEN_WIDTH = 640;
    static const int FRAMES_PER_SECOND = 60;
    constexpr static const float SECONDS_PER_FRAME = (1 * 1000) / GUI::FRAMES_PER_SECOND;
    
    GUI();
    ~GUI();
    bool Initialize();
    void Destroy();
    SDL_Surface * LoadImage(std::string path);
    SDL_Texture * LoadTexture(std::string path);
    
    void PrepareRender();
    void Render(SDL_Surface *surface, SDL_Rect rect);
    void RenderTexture(SDL_Texture *texture, SDL_Rect rect);
    void Update();

};


#endif /* gui_h */
