#include "varialbe.h"

Varialbe::Varialbe()
{

}

Varialbe::Varialbe(string s):Token (getType()){
    _s = s;
}


void Varialbe::print()const{
    cout << _s;
}

ostream& operator <<(ostream& outs, const Varialbe& v){
    v.print();
    return outs;
}
