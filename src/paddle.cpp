#include "paddle.h"

Paddle::Paddle(float x, float y , float width , float height , float speed)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed = speed;
    
}


void Paddle::LimitMovement()
{
    if(y<=0)
    {
        y=0;
    }
    if(y+height>=GetScreenHeight())
    {
        y=GetScreenHeight()-height;
    }
}

void Paddle::Draw()
{
    DrawRectangleRounded({x,y,width , height} , 0.8 , 0 , WHITE);
}

void Paddle::Update()
{
    if(IsKeyDown(KEY_UP))
    {
        y-=speed;
    }
    if(IsKeyDown(KEY_DOWN))
    {
        y+=speed;
    }
    LimitMovement();
}