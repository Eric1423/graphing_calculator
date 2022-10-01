#ifndef MYSTACK_H
#define MYSTACK_H

#include "linked_list_functions.h"
//#include "../../includes/Token/integer.h"
//#include "../../includes/Token/operator.h"

template <typename T>
class Stack{
public:
    class Iterator{
    public:
        friend class Stack;                     //give access to list to access _ptr
        Iterator(){_ptr = NULL;}                //default ctor
        Iterator(node<T>* p){_ptr =p;}          //Point Iterator to where
                                                //  p is pointing to
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
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Stack();

    Stack(const Stack<T>& copyMe);
    ~Stack();
    Stack<T>& operator=(const Stack<T>& RHS);

    T top();
    bool empty();
    void push(T item);
    T pop();

    template<typename TT>
    friend ostream& operator<<(ostream& outs,
                                        const Stack<TT>& printMe);

    Iterator begin() const;              //Iterator to the head node
    Iterator end() const;                //Iterator to NULL
    int size() const { return _size; }

private:
    node<T>* _top;
    int _size;
};

//print
template<typename TT>
ostream& operator<<(ostream& outs,const Stack<TT>& printMe){

    _print_list(printMe._top);

    return outs;
}


// Default Ctor ================================================================

template <typename T>
Stack<T>::Stack(){

    _top = nullptr;
    _size = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& copyMe){

    _top = _copy_list(copyMe._top);
    _size = thesize(_top);
}

template <typename T>
Stack<T>::~Stack(){

    _clear_list(_top);
    _size = 0;
}

template <typename T>
Stack<T>& Stack<T>::operator =(const Stack<T>& RHS){

    if(this == &RHS)
    {
        return *this;
    }

    _clear_list(_top);
    _top = _copy_list(RHS._top);
    _size = thesize(_top);

    return *this;
}

template <typename T>
T Stack<T>::top(){

    return _top->_item;
}

template <typename T>
bool Stack<T>::empty(){

    if(_size == 0)
    return true;

    return false;
}

template <typename T>
void Stack<T>::push(T item){

    _top = _insert_head(_top,item);
    _size++;
}

template <typename T>
T Stack<T>::pop(){

    if(empty())
    return T();

    T item;
    node<T>* temp = _top->next;
    item = _delete_node(_top,_top);
    _top = temp;
    _size--;
    return item;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin() const{

    return Iterator(_top);
}             //Iterator to the head node

template <typename T>
typename Stack<T>::Iterator Stack<T>::end() const{

    return Iterator(nullptr);
}               //Iterator to NULL


#endif
