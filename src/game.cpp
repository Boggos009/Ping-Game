#include "game.h"

Color Green = Color{38,185,154,255};
Color Dark_Green = Color{20,160,133,255};
Color Light_Green = Color{129,204,184,255};
Color Yellow = Color{243,213,91,255};

Game::Game(int screen_width , int screen_height) :
ball(screen_width/2 , screen_height/2 , 25 , 7 , 7) ,
player(screen_width-35 , screen_height/2-60 , 25 , 120 , 6),
cpuPlayer(10 , screen_height/2-60 , 25 , 120 , 6)
{
    this->screen_width = screen_width;
    this->screen_height = screen_height;
    
    player_score = 0 ;cpu_score =0;
}

void Game::Update()
{
    ball.Update(player_score , cpu_score);
    player.Update();
    cpuPlayer.Update(ball.y);

    
    
    if(CheckCollisionCircleRec({ball.x , ball.y} , ball.r , {player.x , player.y , player.width , player.height}))
    {
        ball.speed_x*=-1;
    }
    if(CheckCollisionCircleRec({ball.x , ball.y} , ball.r , {cpuPlayer.x , cpuPlayer.y , cpuPlayer.width , cpuPlayer.height}))
    {
        ball.speed_x*=-1;
    }

}

void Game::Draw()
{

    DrawRectangle(screen_width/2 , 0 , screen_width/2 , screen_height , Green);
    DrawCircle(screen_width/2 , screen_height/2 , 150 , Light_Green);

    DrawLine(screen_width/2 , 0 , screen_width/2 , screen_height , WHITE);
    DrawText(TextFormat("%i" , cpu_score) , screen_width/4-20 , 20 , 80 , WHITE);
    DrawText(TextFormat("%i" , player_score) , 3*screen_width/4-20 , 20 , 80 , WHITE);
    ball.Draw();
    player.Draw();
    cpuPlayer.Draw();
}
