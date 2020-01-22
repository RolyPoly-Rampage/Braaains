#include <SFML/Graphics.hpp>
#include <windows.h>

int main()
{
    sf::Texture texture;
    if (!texture.loadFromFile("space man sprite sheet.jpg"))
    {
        // error...
    }

    sf::IntRect rectSourceSprite(0, 0, 196, 196);
    sf::Sprite sprite(texture, rectSourceSprite);
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);
    sf::Clock clock;
    int rownum = 1;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);
        if (clock.getElapsedTime().asMilliseconds() > 100.0f) {
            if (rectSourceSprite.left == (196 * 4)) {
                rectSourceSprite.left = 0;
                if (rectSourceSprite.top == (196 * 4)) {
                    rownum = 0;
                }
                rectSourceSprite.top = 196 * rownum;
                rownum++;
            }
            else {
                rectSourceSprite.left += 196;
            }
            sprite.setTextureRect(rectSourceSprite);
            clock.restart();
        }
        
        window.draw(sprite);

        // end the current frame
        window.display();

    }

    return 0;
}