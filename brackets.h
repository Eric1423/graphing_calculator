#ifndef BRACKETS_H
#define BRACKETS_H
#include "token.h"
#include "constant.h"

class brackets : public Token
{
public:
    brackets();
    brackets(string op);

    int prec()const{return _precedence;}
    string op()const{return _op;}

    void print()const;
    int getType()const{return BRACKETS;}
    friend ostream& operator <<(ostream& outs, const brackets& b);


private:
    string _op;
    int _precedence;
};
#endif // BRACKETS_H
