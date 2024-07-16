#include"Game.h"
//using namespace sf;
int main()
{
    game g;

    while(g.run())
    {
        g.update();
        g.render();
    }

}