#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <iostream>

int main()
{
    // Create a window with a title and size
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Notepad");

    // Load a font
    sf::Font font;
    if (!font.loadFromFile("times_new_romance2/Times New Romance.ttf")) {
        std::cerr << "Could not load font" << std::endl;
        return -1;
    }

    // Create a text object to display text
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    std::string inputText;
    std::ofstream file("output.txt");

    // Main loop that continues until the window is closed
    while (window.isOpen())
    {
        // Create an event object to handle window events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close the window when the close button is pressed
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle text input
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == '\b') {
                    // Handle backspace
                    if (!inputText.empty())
                        inputText.pop_back();
                } else if (event.text.unicode == '\r' || event.text.unicode == '\n') {
                    // Handle enter key (save text to file)
                    file << inputText << std::endl;
                    inputText.clear();
                } else if (event.text.unicode < 128) {
                    // Append character to inputText
                    inputText += static_cast<char>(event.text.unicode);
                }
            }
        }

        // Clear the window with a black color
        window.clear(sf::Color::Black);

        // Update the text object with the current input text
        text.setString(inputText);

        // Draw the text object
        window.draw(text);

        // Display the contents of the window
        window.display();
    }

    file.close();
    return 0;
}
