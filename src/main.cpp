#include <raylib.h>
#include <iostream>
#include "game.h"
#include "interface.h"
using namespace std;


int main() 
{
    InitWindow(800, 600, "Paddle Game");
    SetTargetFPS(60);
    
    Interface inf1;
    Game game = Game(1280 , 800);
    
    if(inf1.Begin())
    {
        while (WindowShouldClose()==false)
        {
            SetWindowSize(1280,800);
            BeginDrawing();
            ClearBackground(Dark_Green);
            game.Draw();
            game.Update();

            EndDrawing();
        }
    }
    
    CloseWindow();
}