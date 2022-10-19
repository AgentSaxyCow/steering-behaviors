#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "vehicle.hpp"

int main()
{
    // On start
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Steering Behavior");
    window.setFramerateLimit(60);
    sf::Mouse mouse;
    sf::Vector2f target = sf::Vector2f(640.0f, 360.0f);
    sf::CircleShape target_dot = sf::CircleShape(5.0f);
    target_dot.setPosition(target);

    Vehicle vehicle;
    
    while (window.isOpen())
    {
        sf:: Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

            if (mouse.isButtonPressed(mouse.Left))
            {
                sf::Vector2i mouse_pos = mouse.getPosition(window);
                target.x = (float)mouse_pos.x;
                target.y = (float)mouse_pos.y;
                target_dot.setPosition(target);
            }
        }

        vehicle.move(target);

        window.clear();

        window.draw(vehicle.getBody());
        window.draw(target_dot);
        window.draw(vehicle.getVelocityLine());
        window.display();
    }
    return 0;
}