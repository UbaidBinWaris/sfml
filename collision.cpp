#include<SFML/Graphics.hpp>
#include<unistd.h>
using namespace sf;
void update(CircleShape &shape , bool &right , RenderWindow &window)
{
    if(right)
    {
        shape.move(5,0);
        if(shape.getPosition().x > 600)
            right=false;
    }
    else
    {
        shape.move(-5,0);
        if(shape.getPosition().x < 0)
            right=true;
    }
}
int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);

    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);
    shape.setPosition(0,15);
    shape.setOutlineThickness(-5);
    shape.setOutlineColor(Color::Red);

    CircleShape fire(50);
    fire.setFillColor(Color::Blue);
    fire.setPosition(0,450);
    

    bool right=true;

    bool up = false;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(event.mouseButton.button == Mouse::Left && up == false)
                {
                    up = true;
                }
        }

        if(up)
        {
            fire.move(0,-10);
            
            if(fire.getPosition().y < 0 || fire.getGlobalBounds().intersects(shape.getGlobalBounds()) )
            {
                fire.setPosition(Mouse::getPosition(window).x , 450);
                up = false;

                sleep(5);
                
            }
        }
        else if(!up)
        {
            //if(Mouse::getPosition().x <= 0 && Mouse::getPosition().x <= 600)
                fire.setPosition(Mouse::getPosition(window).x , 450);
        }
        window.clear();
        update(shape , right, window);
        window.draw(fire);
        window.draw(shape);
        window.display();
    }

    return 0;
}