#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "MyQueue.h"
#include "MyStack.h"
#include <math.h>
#include "operator.h"
#include "number.h"
#include "brackets.h"

class shunting_yard
{
public:
    shunting_yard();
    shunting_yard(Queue<Token*> infix);

    Queue<Token*> postfix();

private:
    Queue<Token*> _infix;
    Queue<Token*> _postfix;
};
#endif // SHUNTING_YARD_H
