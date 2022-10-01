#ifndef POINTS_H
#define POINTS_H
#include <iostream>
using namespace std;

class Points
{
public:
    Points();
    Points(double x, double y);
    void print()const;
    double getX()const{return _x;}
    double getY()const{return _y;}
    friend ostream& operator <<(ostream& outs, const Points& p);

private:
    double _x;
    double _y;
};

#endif // POINTS_H
