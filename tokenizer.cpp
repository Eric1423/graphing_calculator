//evaluate is tokenize, it change string to infix

#include "tokenizer.h"
evaluate::evaluate()
{
    _shunting = false;
}

evaluate::evaluate(string s){
    _s = s;  // 3+4-5+6
    _shunting = false;
}

void evaluate::convert(){//convert string to shunting yard

    string result;

    for(int i= 0; _s[i] != NULL; i++){

        string carrier;
        string trig;


      switch (_s[i]) {

        case '+':{
            if(result[0] != NULL){
                _input.push(new Number(result));
                result.clear();
            }//if the result string is not empty, push the number to infix, then push the opratpr.
            _input.push(new Operator("+"));
      }
            break;
        case '-':{
            if(result[0] != NULL){
                _input.push(new Number(result));
                result.clear();
            }
            _input.push(new Operator("-"));
      }
            break;
        case '*':{
            if(result[0] != NULL){
                _input.push(new Number(result));
                result.clear();
            }
            _input.push(new Operator("*"));
      }
            break;
        case '/':{
            if(result[0] != NULL){
                _input.push(new Number(result));
                result.clear();
            }
            _input.push(new Operator("/"));
      }
            break;
        case '^':{
            if(result[0] != NULL){
                _input.push(new Number(result));
                result.clear();
            }
            _input.push(new Operator("^"));
      }
            break;
        case '(':{
//          cout << "( has been converted" << endl;
            if(result[0] != NULL){
                _input.push(new Number(result));
                result.clear();
            }
            _input.push(new brackets("("));
      }
            break;
        case ')':{
//          cout << ") has been converted" << endl;
            if(result[0] != NULL){
                _input.push(new Number(result));
                result.clear();
            }
            _input.push(new brackets(")"));
      }
            break;
        case 'x':{
//          cout << "i after s is  ---" << i << "----" << endl;
//          cout << "x has been converted" << endl;
            _input.push(new Varialbe("x"));
      }
            break;
        case 's':
        {
//cout << "s has been converted" << endl;
            int j = 3;
            while (j !=0){
                trig = trig + _s[i];
                j--;
                i++;
            }
//cout << "i before s finished is  ---" << i << "----" << endl;
            i--;
//cout << "i after s finish is  ---" << i << "----" << endl;

            if(trig == "sin"){
                _input.push(new Operator("sin"));
                trig.clear();
            }
            else if(trig == "sec"){
                _input.push(new Operator("sec"));
                trig.clear();
            }
        }
            break;

        case 'c':
        {
            int count = 3;
            while (count !=0) {
                count--;
                trig = trig + _s[i];
                i++;
            }


            i--;
            if(trig == "cos"){
                _input.push(new Operator("cos"));
                trig.clear();
            }
            else if(trig == "csc"){
                _input.push(new Operator("csc"));
                trig.clear();
            }
            else if(trig == "cot"){
                _input.push(new Operator("cot"));
                trig.clear();
            }
        }
            break;

        case 't':
        {
            int count = 3;
            while (count !=0) {
                count--;
                trig = trig + _s[i];
                i++;
            }
            i--; // move the i back one
            if(trig == "tan"){
                _input.push(new Operator("tan"));
                trig.clear();
            }
        }
            break;

        case 'p':
        {

            string a;
            a += _s[i];
            i++;
            a += _s[i];
            if(a == "pi"){
                _input.push(new Number("3.1415926"));
            }
        }
            break;
        default:{
//          cout << "case defalut!!" << endl;
//          cout << "the s[i] is " << _s[i] << endl;
            result = result + _s[i];
          }
            break;
       }
//cout << "i at last is  ---" << i << "----" << endl;
//cout << "173 in evaluete!" << endl;

    }

    if(result[0] != NULL){
        _input.push(new Number(result));
    }
}


double evaluate::infix_to_postfix(double value){
//    cout << value << endl;

    if(!_shunting){
        convert();
        shunting_yard shunting(_input);
        _input = shunting.postfix();
        _shunting = true;
    }

    RPN R(_input);
    return R.R_P_N(value);

}





