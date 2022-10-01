#include "number.h"

Number::Number():Token (getType())
{
    _num = 0;
}

Number::Number(string s):Token (getType()){
    _num = stod(s);
}

double Number::Num(){
    return _num;
}

void Number::print()const{
    cout << _num;
}

ostream& operator <<(ostream& outs, const Number& num){
    num.print();
    return outs;
}
