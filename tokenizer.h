#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "MyQueue.h"
#include "MyStack.h"
#include <math.h>
#include "operator.h"
#include "number.h"
#include "token.h"
#include "brackets.h"
#include "constant.h"
#include "rpn.h"
#include "shunting_yard.h"


class evaluate
{
public:
    evaluate();
    evaluate(string s);
    void convert();
    double infix_to_postfix(double value = 0);
    bool getShunting()const{return _shunting;}


private:
    string _s;
    Queue<Token*> _input;
    bool _shunting;
};

#endif // TOKENIZER_H
