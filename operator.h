#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"
#include "constant.h"

class Operator :public Token
{
public:
    Operator();
    Operator(string op, bool unary = false);

    int prec()const{return _precedence;}
    string op()const{return _op;}

    void print()const;
    int getType()const{return OPERATOR;}
    bool getUnary()const{return _unary;}
    friend ostream& operator <<(ostream& outs, const Operator& op);




private:
    int _precedence;
    string _op;
    bool _unary;
};
#endif // OPERATOR_H
