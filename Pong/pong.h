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

class Pong {
    
private:
    
    GUI gui;
    bool quit;
    
    void HandleEvent();
    
public:
    Pong();
    ~Pong();
    
    bool Initialize();
    void Destroy();
    void Start();
    
};




#endif /* pong_h */
