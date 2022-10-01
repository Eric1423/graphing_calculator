#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cassert>
using namespace std;
#include "../../Ch13_07_Iterated_List/Ch13_07_Iterated_List/iterated.h"



template <class T>
class Queue{
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

    Queue(){
        _front = _list.BEGIN(); // thest two are pointing to null when they were created
        _rear = _list.END();    // remember to update these two before the call the functions.
        _size = -1;  // size start with 0, so it's -1 when the list is empty;
    }
    Queue(const Queue& other){
        _list = other._list;
        _size = other._size;
        _front = _list.BEGIN();
        _rear = _list.END();

    }
    Queue& operator =(const Queue& RHS){
        if(this == &RHS){
            return *this;
        }
        else{
            _list = RHS._list;
            _size = RHS._size;
            _front = _list.BEGIN();
            _rear = _list.END();
            return *this;
        }
    }

    void print_queue()const;
    ITERATOR push(T i);
    T pop();
    T top();
    int return_size()const;
    bool empty()const;


//    template <class U>
    friend ostream& operator <<(ostream& outs, Queue<T>& s){
        typename List<T>::Iterator end = s._list.END();
        for(typename List<T>::Iterator it = s._list.BEGIN(); it != end; it++){
            outs << *it << " ";
        }
        return  outs;
    }


private:
    List<T> _list;
    int _size;
    typename List<T>::Iterator _front;
    typename List<T>::Iterator _rear; // pointing to NULL




};

template <class T>
T Queue<T>::top(){
    return *_list.BEGIN();
}




template <class T>
void Queue<T>::print_queue()const{
    _list.PRINT();
}

template <class T>
bool Queue<T>::empty()const{
    return _list.IS_EMPTY();
}


template <class T>
typename Queue<T>::ITERATOR Queue<T>::push(T i){
    if(_size == -1){
        typename List<T>::Iterator temp = _list.INSERTHEAD(i);
        _size++;
        return temp;
    }
    else{
        typename List<T>::Iterator temp = _list.INSERTBEFORE(i,_rear);
        _size++;
        return temp;
    }

}

template <class T>
T Queue<T>::pop(){
    if(_size >= 0){
        _front = _list.BEGIN();
        _size--;
        return _list.DELETE(_front);
    }

}

template <class T>
int Queue<T>::return_size()const{
    return _size;
}




#endif // QUEUE_H
