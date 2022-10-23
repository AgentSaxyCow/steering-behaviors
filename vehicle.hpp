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
		float rotation;
    public:
        Vehicle()
        {
            this->pos = sf::Vector2f(0.0f, 0.0f);
            this->velocity = sf::Vector2f(1.0f, 1.0f);
            this->max_speed = 10;
            this->max_force = 0.05f;
            this->body = sf::CircleShape(15.0f, 3);
			this->rotation = 0.f;
        }
        void move(sf::Vector2f target)
        {
            sf::Vector2f desired_velocity = truncate(target - pos, max_speed);
            sf::Vector2f steering = desired_velocity - velocity;
            velocity += mult(steering, max_force);
            pos += velocity;
            body.setPosition(sf::Vector2f(pos.x, pos.y));
			rotation = getHeading(velocity);
			body.setRotation(fmod(rotation + 90.f, 360.f));
        }
        sf::CircleShape getBody() {return this->body;}
};

#endif
