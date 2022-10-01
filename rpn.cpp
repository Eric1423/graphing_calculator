#include "rpn.h"
RPN::RPN()
{

}

RPN::RPN(Queue<Token *> input){
    _input = input;
}

double RPN::R_P_N(double value){
    Stack<double> s;

    while(!_input.empty()){
        Token* carrier = _input.pop();

        if(carrier->getType() == 2){
            double num =  static_cast<Number*>(carrier)->Num();
            s.push(num);
        }

        else if(carrier->getType() == 3){
            string str = static_cast<Operator*>(carrier)->op();
            if(str == "+"){
                double second = s.pop();
                double first = s.pop();

                double sum = first + second;
                s.push(sum);
            }
            else if(str == "-"){
                double second = s.pop();
                cout << "here we are, in thr - inRPN" << endl;

                if(static_cast<Operator*>(carrier)->getUnary()){
                    double sum = second * -1;
                    s.push(sum);
                    cout << "hiii" << endl;
                }
                else{
                    cout << "there !!2 " << endl;

                    double first = s.pop();
                    double sum = first - second;
                    s.push(sum);
                }
            }
            else if(str == "*"){
                double second = s.pop();
                double first = s.pop();

                double sum = first * second;
                s.push(sum);
            }
            else if(str == "/"){
                double second = s.pop();
                double first = s.pop();

                double sum = first / second;
                s.push(sum);
            }
            else if(str == "^"){
                double second = s.pop();
                double first = s.pop();

                double sum = pow(first,second);
                s.push(sum);
            }
            else if(str == "cos"){
                double num = s.pop();
                double sum = cos(num);
                s.push(sum);
            }
            else if(str == "sin"){
//                double num = (s.pop()*PI/180);  // change to degree
                double num = s.pop();
                double sum = sin(num);
                s.push(sum);
            }
            else if(str == "tan"){
                double num = s.pop();
                double sum = tan(num);
                s.push(sum);
            }
            else if(str == "csc"){
                double num = s.pop();
                double sum = 1/sin(num);
                s.push(sum);
            }
            else if(str == "sec"){
                double num = s.pop();
                double sum = 1/cos(num);
                s.push(sum);
            }
            else if (str == "cot") {
                double num = s.pop();
                double sum = 1/tan(num);
                s.push(sum);
            }
        }

        else if (carrier->getType() == 5) {
            s.push(value);
        }


    }
    double result = s.pop();
    return result;
}
