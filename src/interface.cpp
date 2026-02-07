#include "Interface.h"

Interface::Interface()
    : startButton("start_button.png", {300,150}, 0.65)
    , exitButton("exit_button.png", {300,300}, 0.65)
    , backGround(LoadTexture("background.png"))
{
}

Interface::~Interface()
{
    UnloadTexture(backGround);
}

bool Interface::Begin()
{
    while(WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(backGround , 0,0,WHITE);
        Vector2 mousePosition =GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        startButton.Draw();
        exitButton.Draw();
        if(startButton.IsPressed(mousePosition , mousePressed))
        {
            return true;
        }

        if(exitButton.IsPressed(mousePosition , mousePressed))
        {
            return false;
        }
        EndDrawing();
    }
    return false;
    
}
