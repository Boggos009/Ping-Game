#include <raylib.h>
#include "buttons.h"

class Interface
{
private:
    Button startButton;
    Button exitButton;
    Texture2D backGround;
public:
    Interface();
    ~Interface();
    bool Begin();
};