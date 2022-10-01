#include "token.h"
Token::Token()
{
    _type = TOKEN;
}

Token::Token(string s):_type(TOKEN){

}

Token::Token(int type){
    _type = type;
}

Token::~Token(){

}



void Token::print()const{

}


ostream& operator <<(ostream& outs, const Token& t){
    t.print();
    return  outs;
}
