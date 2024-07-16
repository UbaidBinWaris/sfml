#include <SFML/Graphics.hpp>
#include <unistd.h>
#include<iostream>
using namespace std;
using namespace sf;
float m = 100.0f;
int rotation = 0;
float deltaTime;
float moveSpeed = 300.f;
int eq=100;
void move_side(CircleShape& shape, RenderWindow& win)
{
    
    if(shape.getPosition().y  >= win.getSize().y - eq)
    {
        shape.move(m, 0);
        return;
    }
    else
        shape.move(0, m);   
}
void newwindow()
{
    RenderWindow window(VideoMode(300,200), "close window");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}
void move_up_down(CircleShape& shape, RenderWindow& win)
{
    while((shape.getPosition().y >= eq-101) || (shape.getPosition().x >= eq-101))
    {
        sleep(1);
        if(shape.getPosition().y >= eq)
        {
            shape.move(0, -m);
        }
        else if(shape.getPosition().x >= eq+100)
        {
            shape.move(-m, 0);
        }
        else
        {
            break;
        }
       
        
        //win.clear();
        win.draw(shape);
        win.display();
        cout<<shape.getPosition().x<<" "<<shape.getPosition().y<<endl<<endl;
    }
    if(eq == win.getSize().y)
    {
        win.close();
        newwindow();
    }
    shape.setPosition(eq,eq);
    //shape.setPosition(0,0);
    rotation++;
}

int main()
{
    RenderWindow window(VideoMode(700,700), "SFML window");
    CircleShape shape(50);
    shape.setFillColor(Color::Green);
    Clock clock;
    
    shape.setPosition(0, 0);
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        //m = moveSpeed * deltaTime;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        eq = (rotation*100) + 100;
        if((shape.getPosition().x  >= window.getSize().x - eq) && (shape.getPosition().y >= window.getSize().y - eq ))
        {
            move_up_down(shape, window);
        }
        sleep(1);



        cout<<shape.getPosition().x<<" "<<shape.getPosition().y<<endl<<endl;
    
        //shape.move(m, m);
        window.draw(shape);
        
        window.display();
        
        //window.clear();
        move_side(shape, window);

        //if(shape.getPosition().x  == window.getSize().x && shape.getPosition().y == window.getSize().y)
        //{
        //    window.close();
        //    newwindow();
        //}
    }

    

    return 0;
}

