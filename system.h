#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "circle.h"
#include "iostream"

#include "MyQueue.h"
#include "points.h"
#include "tokenizer.h"

using namespace std;


class System
{
public:
    System();
    System(string function, double originX, double originY, double numOfdots, double low, double high);
    void update(string function, double originX, double originY, double numOfdots, double low, double high);


    void Draw(sf::RenderWindow& widnow);
    double getSize(){return _size;}
    Queue<Points*>PlotExpression (string expression, double low, double high, double increments);


private:
    sf::CircleShape shape;
    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;

    // graphing data

    vector<Circle*> array;

    string _function;
    double _originX;
    double _originY;
    double _size;
    double _numOfdots;
    double _low;
    double _high;
    double _increments;


};

#endif // SYSTEM_H
