//
//  pong.h
//  Pong
//
//  Created by Zach Lite on 10/20/16.
//  Copyright © 2016 zach. All rights reserved.
//

#ifndef pong_h
#define pong_h

#include "SDL2/SDL.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int FRAMES_PER_SECOND = 30;
const float SECONDS_PER_FRAME = (1 * 1000) / FRAMES_PER_SECOND;

class Pong {
    
private:
    SDL_Window *window;
    SDL_Surface *surface;
    bool quit;
    
    void Render();
    void PollEvents(SDL_Event event);
    void HandleKeyUp(SDL_Event event);
    
public:
    Pong();
    ~Pong();
    
    bool Initialize();
    void Destroy();
    void Start();
    
};




#endif /* pong_h */
