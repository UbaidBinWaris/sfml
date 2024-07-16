#include"Game.h"

game::game()
{
    initVarible();
    initWindow();
}
game::~game()
{
    delete window;
}
const bool game::run()
{
    return window->isOpen();
}
void game::initWindow()
{
    this->window = new RenderWindow(videomode, "Game", sf::Style::Default);
}
void game::initVarible()
{
    this->window = nullptr;
    videomode.height = 600;
    videomode.width = 800;

    img.loadFromFile("snake.jpg");

    object.setSize(Vector2f(300.f,200.f));
    object.setPosition(100,100);
    //object.setFillColor(Color::Red);
    object.setOutlineThickness(-2);
    object.setOutlineColor(Color::White);
    object.setTexture(&img);
}
void game::pollevent()
{
    while(window->pollEvent(event))
    {
        switch(event.type)
        {
            case Event::Closed:
                window->close();
                break;
            case Event::KeyPressed:
                if(event.key.code == Keyboard::Escape)
                    window->close();
                break;
            default:
                break;
        }
    }
}
void game::update()
{
    pollevent();
}
void game::render()
{
    window->clear(Color::Black);

    window->draw(object);

    window->display();
}
