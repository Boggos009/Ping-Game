#include "ball.h"


Ball::Ball(float x, float y, float r, int speed_x, int speed_y)
{
    this->x=x;
    this->y = y;
    this->r = r;
    this->speed_x = speed_x ;
    this->speed_y =speed_y;
}

void Ball::Draw()
{
    DrawCircle(x,y,r,WHITE);
}

void Ball::Update(int &player_score, int&cpu_score)
{
    x+=speed_x;
    y+=speed_y;
    if(y+r >=GetScreenHeight())
    {
        speed_y*=-1;
    }
    if(y-r<=0)
    {
        speed_y*=-1;
    }
    if(x+r>=GetScreenWidth())
    {
        cpu_score++;
        ResetBall();
    }
    if(x-r<0)
    {
        player_score++;
        ResetBall();
    }
}

void Ball::ResetBall()
{
    x= GetScreenWidth()/2;
    y=GetScreenHeight()/2;
    int speed_choices[2] ={-1 , 1};
    speed_x*=speed_choices[GetRandomValue(0,1)];
    speed_y*=speed_choices[GetRandomValue(0,1)];
}
