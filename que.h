#include<SFML/Graphics.hpp>

using namespace sf;

class queue 
{
public:
    int size;
    int front;
    int rear;
    RectangleShape* arr;
    int length;

    queue() 
    {
        size = 20;
        front = -1;
        rear = -1;
        arr = new RectangleShape[size];
        length = 0;
    }

    ~queue() 
    {
        delete[] arr;
    }

    void enqueue() 
    {
        if (length == size) 
        {
            extend_queue();
        }
        if (length == 0) 
        {
            front = 0;
            rear = 0;
        } else {
            front = (front + 1) % size;
        }
        length++;
    }
    void cheak(RenderWindow& window)
    {
        if(arr[front].getPosition().y + arry[front].getSize().y <= window.getSize().y)
        {
            dequeue();
        }
    }

    void dequeue() {
        if (length == 0) 
            return;

        rear++;
        length--;
    }

    void extend_queue() 
    {
        int newSize = size * 2;
        RectangleShape* newArr = new RectangleShape[newSize];

        for (int i = 0; i < length; ++i) 
        {
            newArr[i] = arr[(rear + i) % size];
        }

        delete[] arr;
        arr = newArr;
        size = newSize;
    }
};