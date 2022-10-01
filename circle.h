#ifndef CIRCLE_H
#define CIRCLE_H
#include <SFML/Graphics.hpp>
#include "random.h"

class Circle
{
public:
    Circle();
    Circle(double x, double y);
    void Draw(sf::RenderWindow& widnow);

private:
    sf::CircleShape shape;
    int _size;
    double _x;
    double _y;
};

#endif // CIRCLE_H
