#include "circle.h"

Circle::Circle()
{

}

Circle::Circle(double x, double y){
    _x = x;
    _y = y;
    _size = 2;
    shape = sf::CircleShape(_size);
    shape.setPosition(sf::Vector2f(_x,_y));
    shape.setFillColor(sf::Color::White);
}

void Circle::Draw(sf::RenderWindow& window){
    window.draw(shape);
}
