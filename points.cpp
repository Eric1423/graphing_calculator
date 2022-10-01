#include "points.h"

Points::Points()
{
    _x = 0;
    _y = 0;
}

Points::Points(double x, double y){
    _x = x;
    _y = y;
}

void Points::print()const{
    cout << "(" << _x << ", " << _y << ")";
}

ostream& operator <<(ostream& outs, const Points& p){
    p.print();
    return outs;
}
