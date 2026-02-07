#pragma once
#include <raylib.h>
#include <raymath.h>

using namespace std;

class Ball
{
private:
    void ResetBall();
public:
    float x,y,r;
    int speed_x , speed_y;
    Ball(float x , float y , float r , int speed_x , int speed_y);
    void Draw();
    void Update(int &player_score ,int &cpu_score);
    
};
