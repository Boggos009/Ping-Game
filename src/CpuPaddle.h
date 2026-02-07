#pragma once
#include "paddle.h"

class Cpu : public Paddle
{
public:
    Cpu(float x, float y, float width, float height, float speed) : Paddle(x, y, width, height, speed)
    {
    }
    void Update(int bally)
    {
        if (y + height / 2 <= bally)
        {
            y += speed;
        }
        if (y + height / 2 > bally)
        {
            y -= speed;
        }
        LimitMovement();
    }
};
