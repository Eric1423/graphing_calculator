#include "brackets.h"

brackets::brackets()
{
    _precedence = 0;
}

brackets::brackets(string op): Token(getType()){
    if(op == "(" || op == ")"){
        _precedence = 0;
        _op = op;
    }
}

void brackets::print()const{
    cout << _op;
}

ostream& operator <<(ostream& outs, const brackets& op){
    op.print();
    return  outs;
}
