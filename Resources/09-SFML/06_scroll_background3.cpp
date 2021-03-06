#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(768, 768), "SFML works!");
    //sf::CircleShape shape(100.f);
    sf::Sprite  spriteBall;
    sf::Sprite  spriteBg1;
    sf::Sprite  spriteBg2;
    sf::Texture golfBall;
    sf::Texture background;

    //shape.setFillColor(sf::Color::Green);

    if (golfBall.loadFromFile("./images/golf_ball.png")) {
        spriteBall.setTexture(golfBall);
        spriteBall.setScale(.1, .1);
    } else {
        std::cout << "Error loading texture..." << std::endl;
    }

    if (background.loadFromFile("./images/scroll_bg.png")) {
        spriteBg1.setTexture(background);
        spriteBg1.setPosition(0, 0);
        spriteBg2.setTexture(background);
        spriteBg2.setPosition(0, 0);
    } else {
        std::cout << "Error loading texture..." << std::endl;
    }

    sf::Vector2u size;

    size = background.getSize();

    std::cout << size.x << std::endl;

    float x1 = 0.0;
    float y1 = 0.0;
    float x2 = 2040.0;
    float y2 = 0.0;
    int   bg_flag = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        spriteBg1.setPosition(x1, y1);
        spriteBg2.setPosition(x2, y2);

        x1 -= .075;
        x2 -= .075;

        //std::cout << x1 << std::endl;

        if (x1 <= -2040) {
            x1 = 768;
        }

        if (x2 <= -2040) {
            x2 = 768;
        }

        window.clear();
        //window.draw(shape);
        window.draw(spriteBg1);
        window.draw(spriteBg2);
        window.draw(spriteBall);
        window.display();
    }

    return 0;
}