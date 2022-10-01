#ifndef MINHAO_NODE_H
#define MINHAO_NODE_H


#include <iostream>
#include <iomanip>
using namespace std;

template <typename ITEM_TYPE>
struct node
{
public:
    
    node();

    node(ITEM_TYPE item);

    template <typename T>
    friend ostream& operator <<(ostream& outs, const node<T> &printMe);

    ITEM_TYPE _item;
    node* next;
};

    template <typename T>
    ostream& operator <<(ostream& outs, const node<T> &printMe){

        if(&printMe == nullptr)
        outs << "none";
        else 
        outs << "|" << printMe._item << "|";

        return outs;
    }


template <typename ITEM_TYPE>
node<ITEM_TYPE>::node()
    {
        _item = ITEM_TYPE();
        next = nullptr;
    }

template <typename ITEM_TYPE>
node<ITEM_TYPE>::node(ITEM_TYPE item)
    {
        next = nullptr;
        _item = item;
    }


#endif
