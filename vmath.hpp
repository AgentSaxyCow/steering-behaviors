#ifndef VMATH_HPP
#define VMATH_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

sf::Vector2f truncate(sf::Vector2f v, float d1)
{
    float d0 = sqrt(pow(v.x, 2) + pow(v.y, 2));
    float d = d1 / d0;
    return sf::Vector2(d*v.x, d*v.y);
}

sf::Vector2f mult(sf::Vector2f v, float x)
{
    return sf::Vector2f(x*v.x, x*v.y);
}

#endif