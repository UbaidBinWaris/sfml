#include<SFML/Graphics.hpp>
using namespace sf;


int main()
{
    RenderWindow window(VideoMode(800,600),"Shotter Game",Style::Default);

    CircleShape player(50);
    player.setPosition(window.getSize().x /2 -player.getRadius() , window.getSize().y - player.getRadius()*2 - 20);
    player.setFillColor(Color::White);

    RectangleShape enemy(Vector2f(50,50));
    enemy.setPosition(700,200);
    enemy.setFillColor(Color::Red);
    


    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(player);
        window.draw(enemy);

        window.display();
    }
}