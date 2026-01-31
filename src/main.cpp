#include <raylib.h>
#include <iostream>
using namespace std;
int player_score = 0 , cpu_score =0;

Color Green = Color{38,185,154,255};
Color Dark_Green = Color{20,160,133,255};
Color Light_Green = Color{129,204,184,255};
Color Yellow = Color{243,213,91,255};

class Ball
{
public:
    float x,y,r;
    int speed_x , speed_y;
    void Draw()
    {
        DrawCircle(x,y,r,WHITE);
    }
    void Update()
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

    void ResetBall()
    {
        x= GetScreenWidth()/2;
        y=GetScreenHeight()/2;
        int speed_choices[2] ={-1 , 1};
        speed_x*=speed_choices[GetRandomValue(0,1)];
        speed_y*=speed_choices[GetRandomValue(0,1)];

        
    }
};

class Paddle
{
protected:
    void LimitMovement()
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
public:
    float x,y,width,height , speed;
    

    void Draw()
    {
        DrawRectangleRounded({x,y,width , height} , 0.8 , 0 , WHITE);
    }

    void Update()
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
};

class Cpu:public Paddle
{
public:
    void Update(int bally)
    {
        if(y+height/2 <=bally )
        {
            y+=speed;
        }
        if(y+height/2> bally)
        {
            y-=speed;
        }
        LimitMovement();
    }
};

Ball ball;
Paddle player;
Cpu cpu;
int main() 
{
    
    SetTargetFPS(60);
    int screen_width = 1280, screen_height=800;

    ball.x=screen_width/2;
    ball.y = screen_height/2;
    ball.r = 25;
    ball.speed_x = 7 ; ball.speed_y = 7;
    player.x = screen_width-35; player.y=screen_height/2-60; player.width=25 ; player.height = 120; player.speed=6;
    cpu.x = 10; cpu.y=screen_height/2-60; cpu.width=25 ; cpu.height = 120; cpu.speed=6;


    InitWindow(screen_width , screen_height , "Paddle Game!");

    while(WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(Dark_Green);
        DrawRectangle(screen_width/2 , 0 , screen_width/2 , screen_height , Green);
        DrawCircle(screen_width/2 , screen_height/2 , 150 , Light_Green);

        ball.Update();
        player.Update();
        cpu.Update(ball.y);
        
        
        if(CheckCollisionCircleRec({ball.x , ball.y} , ball.r , {player.x , player.y , player.width , player.height}))
        {
            ball.speed_x*=-1;
        }
        if(CheckCollisionCircleRec({ball.x , ball.y} , ball.r , {cpu.x , cpu.y , cpu.width , cpu.height}))
        {
            ball.speed_x*=-1;
        }

        ball.Draw();
        player.Draw();
        cpu.Draw();
        
        
        DrawLine(screen_width/2 , 0 , screen_width/2 , screen_height , WHITE);
        DrawText(TextFormat("%i" , cpu_score) , screen_width/4-20 , 20 , 80 , WHITE);
        DrawText(TextFormat("%i" , player_score) , 3*screen_width/4-20 , 20 , 80 , WHITE);

        EndDrawing();
    }

    CloseWindow();
}