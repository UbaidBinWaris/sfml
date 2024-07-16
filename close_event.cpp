#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main()
{
    RenderWindow win(VideoMode(800, 600), "SFML Graphics");

    while (win.isOpen())
    {
        Event event;
        while (win.pollEvent(event))
        {
            if (event.type == Event::Closed)
                win.close();

            if (event.type == Event::KeyPressed)
            {
                cout << "Key pressed: " << event.key.code << endl;
                return 0;
            }
        }

       if(Mouse::isButtonPressed(Mouse::Left))
       {
            cout << "Mouse key pressed" << endl;
            return 0;
       }

        win.display();
    }
}