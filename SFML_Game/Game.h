#include<SFML/Graphics.hpp>

using namespace sf;

class game
{
private:
    RenderWindow* window;
    Event event;
    VideoMode videomode;
    Texture img;
    RectangleShape object;
    void initVarible();
    void initWindow();

public:
    game();
    virtual ~game();
    const bool run();
    void pollevent();
    void update();
    void render();
};