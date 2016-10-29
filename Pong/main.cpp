//
//  main.cpp
//  Pong
//
//  Created by Zach Lite on 10/18/16.
//  Copyright © 2016 zach. All rights reserved.
//
#include <time.h>
#include <iostream>
#include <SDL2/SDL.h>
#include "pong.h"

int main(int argc, const char * argv[]) {

    Pong pong;
    if(!pong.Initialize()){
        return false;
    }
    
    pong.Start();
    pong.Destroy();
    
    return 0;
}
