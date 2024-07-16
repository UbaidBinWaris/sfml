#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML Shapes");

    Texture img;
    img.loadFromFile("images.png");

    Sprite sprite(img);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //window.clear();
        window.draw(sprite);
        window.display();
    }
}