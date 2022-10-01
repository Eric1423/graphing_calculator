#ifndef MINHAO_MYQUEUE_H
#define MINHAO_MYQUEUE_H

#include "linked_list_functions.h"
//#include "../../includes/Token/integer.h"
//#include "../../includes/Token/operator.h"

template <typename T>
class Queue
{
public:
    class Iterator{
    public:
        friend class Queue;          //give access to list to access _ptr
        Iterator(){
            _ptr = nullptr;
        }                  //default ctor
        Iterator(node<T>* p){
            _ptr = p;
        }        //Point Iterator to where
        //...                        //  p is pointing to
        operator bool(){
            if(_ptr != nullptr)
            {
                return true;
            }
            else
            {
                return false;
            } 
        }                         


        T& operator *()
        {
            return _ptr->_item;
        }                        //dereference operator
        T* operator ->()
        {
            return &_ptr->_item;
        }                       //member access operator

        bool is_null()
        {
            if (_ptr == nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }                                 //true if _ptr is NULL

        friend bool operator !=(const Iterator& left,
                                const Iterator& right){
            if( left._ptr != right._ptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        } //true if left != right

        friend bool operator ==(const Iterator& left,
                                const Iterator& right){
            if( left._ptr == right._ptr)
            {
                return true;
            }
            else
            {
                return false;
            } //true if left == right
        } //true if left == right

        Iterator& operator++(){
           _ptr = _ptr -> next;
            return *this;
        }  //member operator: ++it; or ++it = new_value

        friend Iterator operator++(Iterator& it,
                                   int unused){
            Iterator hold(it._ptr);
            it._ptr = it._ptr -> next;
            return hold;
            
        }         //friend operator: it++
 
    private:
        node<T>* _ptr;               //pointer being encapsulated
    };

    Queue();

    Queue(const Queue<T>& copyMe);
    ~Queue();
    Queue& operator=(const Queue<T>& RHS);

    bool empty();
    T front();
    T back();

    void push(T item);
    T pop();

    Iterator begin() const;            //Iterator to the head node
    Iterator end() const;              //Iterator to NULL
    void print_pointers();
    int size() const { return _size; }
    template<typename TT>
    friend ostream& operator << (ostream& outs, const Queue<TT>& printMe);
private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};

//print
template<typename TT>
ostream& operator << (ostream& outs, const Queue<TT>& printMe){

    _print_list(printMe._front);

    return outs;
}

// Default Ctor ================================================================

template <typename T>
Queue<T>::Queue(){
    _size = 0;
    _front = nullptr;
    _rear = nullptr;
}

// BIG3 ========================================================================

template <typename T>
Queue<T>::Queue(const Queue<T>& copyMe){

    _front = _copy_list(copyMe._front);
    _rear = _last_node(_front);
    _size = thesize(_front);

}

template <typename T>
Queue<T>::~Queue() {

    _clear_list(_front);
    _size = 0;

}

template <typename T>
Queue<T>& Queue<T>::operator =(const Queue<T>& RHS){

    if(this == &RHS)
    {
        return *this;
    }

    _clear_list(_front);
    _front = _copy_list(RHS._front);
    _rear = _last_node(_front);
    _size = thesize(_front);

    return *this;

}

// INFOS =======================================================================

template <typename T>
bool Queue<T>::empty(){

    if(_size == 0)
    return true;

    return false;
}

template <typename T>
T Queue<T>::front(){

    if(empty())
    return T();

    return _front->_item;
}

template <typename T>
T Queue<T>::back(){

    if(empty())
    return T();

    return _rear->_item;
}

template <typename T>
void Queue<T>::push(T item){
    
    _size++;
    _front = _insert_after(_front,_rear,item);

    if(_size == 1)
    _rear = _front;
    else
    _rear = _rear->next;

}

template <typename T>
T Queue<T>::pop(){

    if(empty())
    return T();

    _size--;

    if(_size == 0)
    _rear = nullptr;
    
    T item;
    item = _delete_node(_front,_front);
    
    return item;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() const{

    return Iterator(_front);

}            //Iterator to the head node

template <typename T>
typename Queue<T>::Iterator Queue<T>::end() const{

    return Iterator(nullptr);
}              //Iterator to NULL

void print_pointers();







#endif
