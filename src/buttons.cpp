#include "buttons.h"

Button::Button(const char *imagePath, Vector2 imagePosition , float scale)
{
    Image image = LoadImage(imagePath);

    int originalWidth = image.width;
    int originalHeight = image.height;

    int newWidth = static_cast <int> (originalWidth*scale);
    int newHeight = static_cast <int> (originalHeight*scale);
    ImageResize(&image , newWidth , newHeight);

    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = imagePosition;

}

Button::~Button()
{
    UnloadTexture(texture);
}

void Button::Draw()
{
    DrawTexture(texture , position.x , position.y , WHITE);
}

bool Button::IsPressed(Vector2 mousePos, bool mousePressed)
{
    Rectangle rec = {position.x , position.y , (float)texture.width ,(float) texture.height};

    if(CheckCollisionPointRec(mousePos , rec)&&mousePressed)
    {
        return true;
    }
    return false;
}
