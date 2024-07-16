#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    //RenderWindow win(VideoMode::getDesktopMode()  "SFML Window" , Style::Close | Style::Titlebar );//| Style::Resize);
    RenderWindow win(VideoMode(600,600), "SFML Fullscreen Window", Style::Titlebar | Style::Close);

    RectangleShape shape(Vector2f(200.f, 100.f));
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(Color::Red);
    shape.setOutlineThickness(2.f);

    Vertex line[] = {Vector2f(100.f, 100.f), Vector2f(300.f, 300.f) };
    while(win.isOpen())
    {
        Event event;
        while(win.pollEvent(event))
        {
            if(event.type == Event::Closed)
                win.close();
        }

        win.draw (shape);
        win.draw (line, 2, Lines);
        //win.clear(Color::Black);
        win.display();
    }
}