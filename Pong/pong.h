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
#include "gui.h"
#include "player.h"

class Pong {
    
private:
    GUI gui;
    bool quit;
    Player player_1;
    Player player_2;
    
    void ProcessInput(SDL_Event e);
    
public:
    Pong();
    ~Pong();
    
    bool Initialize();
    void Destroy();
    void Start();
    
};

#endif /* pong_h */
