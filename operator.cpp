#include "operator.h"


Operator::Operator() :Token (getType())
{
    _precedence = 0;
}

Operator::Operator(string op, bool unary) :Token (getType()){
    if(op == "+"){
        _precedence = 1;
        _op = op;
    }
    else if(op == "-"){
        _unary = unary;
        if(_unary){
            _precedence = 5;
        }
        else{
            _precedence = 1;
        }
        _op = op;
    }
    else if(op == "*" || op == "/"){
        _precedence = 2;
        _op = op;
    }
    else if(op == "^"){
        _precedence = 3;
        _op = op;
    }
    else if(op == "sin" || op == "cos" || op == "tan" ||
            op == "sec" || op == "csc" || op == "cot"){
        _precedence = 4;
        _op = op;
    }
}

void Operator::print()const{
    cout << _op;
}

ostream& operator <<(ostream& outs, const Operator& op){
    op.print();
    return  outs;
}
