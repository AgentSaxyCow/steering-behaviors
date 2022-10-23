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
float getHeading(sf::Vector2f v)
{
	if (v.x > 0 && v.y >= 0) {
		return atan(abs(v.y)/abs(v.x)) * (180.f/M_PI);
	}
	else if (v.x == 0 && v.y > 0) {
		return 90.f;
	}
	else if (v.x < 0 && v.y > 0) {
		return (atan(abs(v.x)/abs(v.y)) * (180.f/M_PI)) + 90.f; 
	}
	else if (v.x < 0 && v.y <= 0) {
		return (atan(abs(v.y)/abs(v.x)) * (180.f/M_PI)) + 180.f; 
	}
	else if (v.x == 0 && v.y < 0) {
		return 270.f;
	}
	else if (v.x > 0 && v.y < 0) {
		return (atan(abs(v.x)/abs(v.y)) * (180.f/M_PI)) + 270.f; 
	}
	else {
		return 0.f;
	}
}

#endif
