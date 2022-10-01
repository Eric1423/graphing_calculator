#ifndef VARIALBE_H
#define VARIALBE_H
#include "token.h"
#include "constant.h"

class Varialbe : public Token
{
public:
    Varialbe();
    Varialbe(string s);

    string Str()const{return _s;}
    void print()const;
    friend ostream& operator <<(ostream& outs, const Varialbe& v);
    int getType()const{return VARIABLE;}


private:
    string _s;
};
#endif // VARIALBE_H
