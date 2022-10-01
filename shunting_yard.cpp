#include "shunting_yard.h"
shunting_yard::shunting_yard()
{

}

shunting_yard::shunting_yard(Queue<Token*> infix){
    _infix = infix;
}

Queue<Token*> shunting_yard::postfix(){

    Queue<Token*> postfix;
    Stack<Token*> op;

    while(!_infix.empty()){
        Token* carrier = _infix.pop();
        switch (carrier->getType()){
        case 2:
            postfix.push(carrier);
            break;
        case 3:
            if(postfix.empty() && op.empty()){
                if(static_cast<Operator*>(carrier)->op() == "-"){
//                    cout << "shunting yard , - as been detected" << endl;
                   if(postfix.empty() && op.empty()){
//                        cout << "shunting yard , - as been detected in the if sattement " << endl;

                        Token* unary(new Operator("-",true));
                        op.push(unary);
//                         _infix.pop();
                      }
                 }
            }

            else if(op.empty()){
                cout << __LINE__ << endl;
                op.push(carrier);
            }
            else if(op.top()->getType() == BRACKETS){
                op.push(carrier);
            }
            else if(!op.empty() && static_cast<Operator*>(carrier)->prec() >= static_cast<Operator*>(op.top())->prec()){
                op.push(carrier);
            }
            else if(!op.empty() && static_cast<Operator*>(carrier)->prec() < static_cast<Operator*>(op.top())->prec()){
                while(!op.empty() &&  op.top()->getType() != BRACKETS && static_cast<Operator*>(op.top())->prec() > static_cast<Operator*>(carrier)->prec()){
                    postfix.push(op.pop());
                }
                op.push(carrier);
            }

            break;
        case 4:
            if(static_cast<brackets*>(carrier)->op() == "("){
                op.push(carrier);
                Token* temp = _infix.front();
                if(temp->getType() == OPERATOR){
                    if(static_cast<Operator*>(temp)->op() == "-"){
                        Token* unary(new Operator("-",true));
                        op.push(unary);
                        _infix.pop(); // pop out the unary
                    }
                }


            }
            else if(static_cast<brackets*>(carrier)->op() == ")"){
                while(op.top()->getType() != BRACKETS){
                    postfix.push(op.pop());
                }
                op.pop();
            }
            break;
        case 5:
            postfix.push(carrier);
            break;
        }

    }

    while(!op.empty()){
        postfix.push(op.pop());
    }


    _postfix = postfix;



    return  postfix;
}
