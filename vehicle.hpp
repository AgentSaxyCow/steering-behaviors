#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "vmath.hpp"

class Vehicle
{
    private:
        sf::Vector2f pos;
        sf::Vector2f velocity;
        int max_speed;
        float max_force;
        sf::CircleShape body;
    public:
        Vehicle()
        {
            this->pos = sf::Vector2f(0.0f, 0.0f);
            this->velocity = sf::Vector2f(1.0f, 1.0f);
            this->max_speed = 20;
            this->max_force = 0.03f;
            this->body = sf::CircleShape(10.0f);
        }
        void move(sf::Vector2f target)
        {
            sf::Vector2f desired_velocity = truncate(target - pos, max_speed);
            sf::Vector2f steering = desired_velocity - velocity;
            velocity += mult(steering, max_force);
            pos += velocity;
            body.setPosition(sf::Vector2f(pos.x - 5.f, pos.y - 5.f));
        }
        sf::CircleShape getBody() {return this->body;}
        sf::RectangleShape getVelocityLine() 
        {
            //sf::VertexArray line = sf::VertexArray(sf::LinesStrip, 2);
            //line[0].position = this->pos;
            //line[1].position = sf::Vector2f(this->pos.x + this->velocity.x, this->pos.y + this->velocity.y);
			sf::RectangleShape line(sf::Vector2f(10 * getMag(this->velocity), 2.f));
			line.setPosition(this->pos);
			line.setRotation(getHeading(this->velocity));
			line.setFillColor(sf::Color(166, 8, 5));
			return line;
        }
};

#endif
