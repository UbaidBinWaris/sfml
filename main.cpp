#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

float moveSpeed = 300.f;
float m;
int eq = 100;
int rotation = 0;

void move_side(CircleShape& shape, RenderWindow& win, float m)
{
    if (shape.getPosition().y >= win.getSize().y - eq)
    {
        shape.move(m, 0);
    }
    else
    {
        shape.move(0, m);
    }
}

void move_up_down(CircleShape& shape, RenderWindow& win, float m)
{
    while ((shape.getPosition().y >= eq) || (shape.getPosition().x >= eq))
    {
        if (shape.getPosition().y <= eq)
        {
            shape.move(-m, 0);
        }
        else
        {
            shape.move(0, -m);
        }

        win.clear();
        win.draw(shape);
        win.display();
        cout << shape.getPosition().x << " " << shape.getPosition().y << endl << endl;
    }
    rotation++;
    eq -= 10; // Reduce the border size
    if (eq < 0) eq = 0; // Ensure eq doesn't go negative
    shape.setPosition(eq, eq); // Reset position for the next rotation
}

int main()
{
    RenderWindow window(VideoMode(600, 600), "SFML window");
    CircleShape shape(50);
    shape.setFillColor(Color::Green);
    Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        m = moveSpeed * deltaTime;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if ((shape.getPosition().x >= window.getSize().x - eq) && (shape.getPosition().y >= window.getSize().y - eq))
        {
            move_up_down(shape, window, m);
        }
        else
        {
            move_side(shape, window, m);
        }

        cout << shape.getPosition().x << " " << shape.getPosition().y << endl << endl;

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
