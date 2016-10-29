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

const int BALL_WIDTH = 20;
const int BALL_HEIGHT = 20;

struct Ball {
    SDL_Texture *texture;
    SDL_Rect rect;
    float vx;
    float vy;
};

class Pong {
    
private:
    GUI gui;
    bool quit = false;
    Player player_1;
    Player player_2;
    Ball ball;
    
    void ProcessInput(SDL_Event e);
    void MoveBall();
    void CheckForGoal();
    void ResetBall();
    
public:
    Pong();
    ~Pong();
    
    bool Initialize();
    void Destroy();
    void Start();
    
};

#endif /* pong_h */
