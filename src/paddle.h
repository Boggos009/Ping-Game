#pragma once

#include <raylib.h>

class Paddle
{
protected:
    void LimitMovement();
public:
    
    Paddle(float x, float y , float width , float height , float speed);
    void Draw();

    void Update();
    float x,y,width,height , speed;
};
