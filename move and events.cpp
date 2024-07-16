#include<SFML/Graphics.hpp>

const int m = 5; 
using namespace sf;
void update(RectangleShape &snake, RenderWindow &window )
{
    if(Keyboard::isKeyPressed(Keyboard::A) && (snake.getPosition().x >= 0))
    {
        snake.move(-m,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::D)&& (snake.getPosition().x + snake.getSize().x  <= window.getSize().x))
    {
        snake.move(m,0);
    }
    if(Keyboard::isKeyPressed(Keyboard::W)&& (snake.getPosition().y >= 0))
    {
        snake.move(0,-m);
    }
    if(Keyboard::isKeyPressed(Keyboard::S)&& (snake.getPosition().y + snake.getSize().y  <= window.getSize().y))
    {
        snake.move(0,m);
    }
    if(Mouse::isButtonPressed(Mouse::Left))
    {
        snake.setFillColor(Color::Red);
    }
    if(Mouse::isButtonPressed(Mouse::Right))
    {
        snake.setFillColor(Color::Blue);
    }
}
void draw(RenderWindow &window , RectangleShape &snake)
{
    window.clear(Color::White);
    window.draw(snake);
    window.display();
}
int main()
{
    RenderWindow window(VideoMode(800, 600), "Snake Game");
    window.setFramerateLimit(60);

    RectangleShape snake;
    snake.setSize(Vector2f(20, 20));
    snake.setFillColor(Color::Green);
    snake.setPosition(400, 300);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
            {
               
            }
        }

        
       update(snake , window);
       draw(window, snake);
    }

    return 0;
}