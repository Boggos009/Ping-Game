#pragma once
#include "paddle.h"
#include "CpuPaddle.h"
#include "ball.h"
#include <iostream>
using namespace std;


extern Color Green;
extern Color Dark_Green;
extern Color Light_Green;
extern Color Yellow;


class Game
{
private:
    int screen_width , screen_height;
    Ball ball; 
    Paddle player;
    Cpu cpuPlayer;
    int player_score , cpu_score;
public:
    Game(int screen_width ,int screen_height);
    void Update();
    void Draw();
};