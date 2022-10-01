#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <iostream>
#include "constant.h"

using namespace std;

class Token
{
public:
    Token();
    Token(string s);
    Token(int type);

    virtual ~Token();
    virtual void print()const;
    virtual int getType()const{return TOKEN;}

    friend ostream& operator <<(ostream& outs, const Token& t);

private:
    int _type;

};

#endif // TOKEN_H
