#include "system.h"
#include "random.h"
#include <iostream>
#include <constants.h>
#include <string>


System::System()
//constructor of system
{

}


//constructor of system, it set the window, the graph info
System::System(string function, double originX, double originY, double numOfdots, double low, double high){

    _originX = originX;
    _originY = originY;
    _numOfdots = numOfdots;
    _low = low;
    _high = high;

    x_axis = sf::RectangleShape(sf::Vector2f(1280,1));
    x_axis.setPosition(0,_originY);
    x_axis.setFillColor(sf::Color::Yellow);//set the y-axis

    y_axis = sf::RectangleShape(sf::Vector2f(1,1200));
    y_axis.setPosition(_originX,0);
    y_axis.setFillColor(sf::Color::Yellow);//set the x-axis

    string _function = function;

    double domain;

    if(_high < 0){
        domain = (abs(_low)-abs(_high));
    }
    else if(_low > 0){
        domain = (abs(_high)-abs(_low));
    }
    else{
        domain = (abs(_low)+abs(_high));
    }

    _increments = domain / _numOfdots;

    _size = 1280 / domain;


    //draw the graph
    Queue<Points*> points = PlotExpression(function,_low,_high,_increments);
//    cout << "function is " << function << endl;

    double x=0;
    double y=0;
    for(int i=0; i<_numOfdots; i++){
        //graph the equation with dots
        Points* carrier = points.pop();
        x = carrier->getX();
        y = carrier->getY();
        array.push_back(new Circle(x,y));
    }
}



void System::update(string funciton, double originX, double originY, double numOfdots, double low, double high){

    double count = _numOfdots;
    while(count !=0){
        array.pop_back();
        count--;
    }


    _originX = originX;
    _originY = originY;
    _numOfdots = numOfdots;
    _low = low;
    _high = high;



    x_axis = sf::RectangleShape(sf::Vector2f(1280,1));
    x_axis.setPosition(0,_originY);
    x_axis.setFillColor(sf::Color::Yellow);

    y_axis = sf::RectangleShape(sf::Vector2f(1,1200));
    y_axis.setPosition(_originX,0);
    y_axis.setFillColor(sf::Color::Yellow);

    string _function = funciton;

    double domain;
//cout << __LINE__ << endl;

    if(_high < 0){
        domain = (abs(_low)-abs(_high));
    }
    else if(_low > 0){
        domain = (abs(_high)-abs(_low));
    }
    else{
        domain = (abs(_low)+abs(_high));
    }

    _increments = domain / _numOfdots;

    _size = 1280 / domain;

    Queue<Points*> points = PlotExpression(_function,_low,_high,_increments);
//    cout << "function is " << _function << endl;
    double x=0;
    double y=0;
    for(int i=0; i<_numOfdots; i++){
        Points* carrier = points.pop();
        x = carrier->getX();
        y = carrier->getY();

        array.push_back(new Circle(x,y));
    }
//    cout << "updated in system has been called!" << endl;

}


void System::Draw(sf::RenderWindow& window){

    window.clear();

    for(int i=0; i < _numOfdots; i++){
        array[i]->Draw(window);
    }

    window.draw(y_axis);
    window.draw(x_axis);

}



Queue<Points*> System::PlotExpression(string expression, double low, double high, double increments){

    evaluate a(expression);
    Queue<Points*> carrier;

    double y;
    for(double i=low; i <= high; i+= increments){
         y = a.infix_to_postfix(i);
//         cout << i << endl;
//                  cout << y << endl;

         carrier.push(new Points(i*_size+_originX, -y*_size + _originY));  // convert to screen point
//         cout << y << endl;
    }
    return carrier;
}




