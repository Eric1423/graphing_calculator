#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"
#include "constant.h"

class Number : public Token
{
public:
    Number();
    Number(string s);

    double Num();
    void print()const;
    friend ostream& operator <<(ostream& outs, const Number& num);
    int getType()const{return NUMBER;}

private:
    double _num;

};

#endif // NUMBER_H
