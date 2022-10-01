#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cassert>
using namespace std;
#include "../../Ch13_07_Iterated_List/Ch13_07_Iterated_List/iterated.h"




template <class T>
class Stack{
public:

    class ITERATOR{
    public:
        ITERATOR(){
            _ptr = NULL;
        }
        ITERATOR(typename List<T>::Iterator i){
            _ptr = i;
        }

        T operator *(){                //dereference operator
            return *_ptr;
        }

        operator bool(){        //true if not null
            if(_ptr){
//                cout << "bool operator: true, it's not null." << endl;
                return true;
            }
        }

        T* operator ->(){              //member access operator
           T* temp = _ptr->_item;
           return temp;
        }

        bool is_null(){                 //true if _ptr is NULL
            // 1 if true, 0 if false
            return _ptr.is_null();
        }

        friend bool operator !=(const ITERATOR& left, const ITERATOR& right){
            return left._ptr != right._ptr;
        }

        friend bool operator ==(const ITERATOR& left, const ITERATOR& right){
            return left._ptr == right._ptr;
        }

        ITERATOR& operator++(){                          //member operator: ++it; or ++it = new_value
            assert(!_ptr.is_null());
            ++_ptr;
            return *this;
        }

        friend ITERATOR operator++(ITERATOR& it, int unused){
            assert(!it.is_null());
            ITERATOR hold = it._ptr;
            it._ptr++;
            return hold;
        }



    private:
        typename List<T>::Iterator _ptr;

    };

    Stack(){
        _top = _list.BEGIN(); // pointing to null! need to update when usd

    }
    Stack(const Stack& other){
        _list = other._list;
        _top = _list.BEGIN();

    }
    Stack& operator =(const Stack& RHS){
        if(this == RHS){
            return *this;
        }
        else{
            _list = RHS._list;
            _top = _list.BEGIN();
            return *this;
        }
    }

    void print_stack()const;
    ITERATOR push(T i);
    T pop();
    T top();
    bool empty()const;

//    template <class U>
    friend ostream& operator <<(ostream& outs, Stack<T>& s){
        typename List<T>::Iterator end = s._list.END();
        for(typename List<T>::Iterator it = s._list.BEGIN(); it != end; it++){
            outs << *it << " ";
        }
        return  outs;
    }


private:
    List<T> _list;
    typename List<T>::Iterator _top;




};

template <class T>
void Stack<T>::print_stack()const{
    _list.PRINT();
}

template <class T>
bool Stack<T>::empty()const{
    return _list.IS_EMPTY();
}

template <class T>
typename Stack<T>::ITERATOR Stack<T>::push(T i){
    return _list.INSERTHEAD(i);
}

template <class T>
T Stack<T>::pop(){
    _top = _list.BEGIN();
    return _list.DELETE(_top);
}

template <class T>
T Stack<T>::top(){
    return *_list.BEGIN();
}














#endif // STACK_H
