#ifndef RPN_H
#define RPN_H
#include "MyQueue.h"
#include "MyStack.h"
#include <math.h>
#include "operator.h"
#include "number.h"
#include "token.h"
#include "varialbe.h"
#include "constant.h"
#define PI 3.14159265

class RPN
{
public:
    RPN();
    RPN(Queue<Token*> input);
    double R_P_N(double value = 0);


private:
    Queue<Token*> _input;

};
#endif // RPN_H
