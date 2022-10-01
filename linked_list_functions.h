#ifndef MINHAO_LIST_FUNCTIONS_H
#define MINHAO_LIST_FUNCTIONS_H


#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

#include "node.h"


//Linked List General Functions:
template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE>* head);

    //recursive fun! :)
    template <typename ITEM_TYPE>
    void _print_list_backwards(node<ITEM_TYPE> *head);

    //return ptr to key or NULL
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head,
                                ITEM_TYPE key);


    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head,
                                ITEM_TYPE insert_this);

    //insert after ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head,
                                 node<ITEM_TYPE> *after_this,
                                 ITEM_TYPE insert_this);

    //insert before ptr
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head,
                                  node<ITEM_TYPE>* before_this,
                                  ITEM_TYPE insert_this);

    //ptr to previous node
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head,
                                  node<ITEM_TYPE>* prev_to_this);

    //delete, return item
    template <typename ITEM_TYPE>
    ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head,
                         node<ITEM_TYPE>* delete_this);

    //duplicate the list...
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head);

    //delete all the nodes
    template <typename ITEM_TYPE>
    void _clear_list(node<ITEM_TYPE>*& head);

    template <typename ITEM_TYPE>
    bool valid_node(node<ITEM_TYPE>* head, node<ITEM_TYPE>* target_node);

    //_item at this position
    template <typename ITEM_TYPE>
    ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos);

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    //      Sorted List Routines. order: 0: ascending, order: other: descending
    //                              Assume a Sorted List
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head,       //insert
                                  ITEM_TYPE item,
                                  bool ascending=true);

    //insert or add if a dup
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head,
                                          ITEM_TYPE item,
                                          bool ascending=true);
    //node after which this item goes order: 0 ascending
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head,
                                   ITEM_TYPE item,
                                   bool ascending=true);
    //Last Node in the list
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head);            //

    template <typename ITEM_TYPE>
    int thesize(node<ITEM_TYPE>* head);

//==============================================================================

// Definition ==================================================================

    template <typename ITEM_TYPE>
    int thesize(node<ITEM_TYPE>* head)
    {
        node<ITEM_TYPE>* walker = head;

        int count = 0;
        while(walker != nullptr)
        {
            count++;
            walker = walker->next;
        }

        return count;

    }

template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE>* head)
{

    bool debug = false;
    node<ITEM_TYPE> *walker = head;
    
    cout << "head ->";
    while(walker != nullptr)
    {
        cout << " |" << walker->_item << "|";
        walker = walker->next;
    }
    cout << " |||" << endl;

    walker = head;
    debug = false;
    if(debug)
    {
        cout << "head ->";
        while(walker != nullptr)
        {
            cout << " |" << walker << "|";
            walker = walker->next;
        }
        cout << " |||" << endl;
    }
    



}

//recursive fun! :)
template <typename ITEM_TYPE>
void _print_list_backwards(node<ITEM_TYPE>* head)
{
    node<ITEM_TYPE> *walker = head;

    while(walker->next != nullptr)
    {
        walker = walker->next; 
    }


    cout << "||| -> ";
    while(walker != head)
    {
        cout << " |" << walker->_item << "|";
        walker = _previous_node(head,walker); 
    }

    cout << " |" << walker->_item << "| " << "head" << endl;

}

//return ptr to key or NULL
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head,ITEM_TYPE key)
{

    node<ITEM_TYPE>* walker = head;

    while(walker != nullptr)
    {
        if(walker->_item == key)
        return walker;

        walker = walker->next;
    }

    return nullptr;

}


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head,ITEM_TYPE insert_this)
{
  
    node<ITEM_TYPE>* newnode = new node<ITEM_TYPE>();

    newnode->next = head;
    newnode->_item = insert_this;

    head = newnode;

    return head;
}

//insert after ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head, node<ITEM_TYPE> *after_this, ITEM_TYPE insert_this)
{
    
    if(after_this != nullptr)
    {
        node<ITEM_TYPE>* newnode = new node<ITEM_TYPE>();

        newnode->next = after_this->next;
        newnode->_item = insert_this;

        after_this->next = newnode;        
    }
    else 
    _insert_head(head,insert_this);
    
    return head;
}

//insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head,node<ITEM_TYPE>* before_this,ITEM_TYPE insert_this)
{

    
    if(before_this != nullptr)
    {
        node<ITEM_TYPE>* after = _previous_node(head,before_this);
        return _insert_after(head,after,insert_this);
    }
    // else if(head->next != nullptr)  {
    //     cout << "\ninserting last node\n";
    // _insert_after(head,_last_node(head),insert_this);
    // }
    else 
    _insert_head(head,insert_this);
    
    
    return head;

}

//ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head,node<ITEM_TYPE>* prev_to_this)
{

    if(prev_to_this == head)
    return nullptr;
    
    node<ITEM_TYPE> *walker = head;

    while(walker != nullptr)
    {
        if(walker->next == prev_to_this)
        return walker;

        walker = walker->next;
    }
    
    return nullptr;

}

//delete, return item
template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head,node<ITEM_TYPE>* delete_this)
{

    if(valid_node(head,delete_this))
    {
        ITEM_TYPE deleted = delete_this->_item;

        if(delete_this == head)
        head = delete_this->next;
        else
        _previous_node(head,delete_this)->next = delete_this->next;
        
        delete delete_this;

        
        return deleted;
    }

    return ITEM_TYPE();

}

template <typename ITEM_TYPE>
bool valid_node(node<ITEM_TYPE>* head, node<ITEM_TYPE>* target_node)
{

    node<ITEM_TYPE>* walker = head;

    while(walker != nullptr)
    {
        if(walker == target_node)
        return true;
        
        walker = walker->next;
    }

    return false;

}

//duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head)
{

    node<ITEM_TYPE>* newnode = nullptr;
    node<ITEM_TYPE>* walker = head;
    node<ITEM_TYPE>* nwalker = nullptr;

    if(head == nullptr)
    return nullptr;
    else
    _insert_head(newnode,head->_item);

    walker = walker->next;
    nwalker = newnode;

    while(walker != nullptr)
    {
        _insert_after(newnode,nwalker,walker->_item);
        nwalker = nwalker->next;
        walker = walker->next;
    }
    
    return newnode;

}

//delete all the nodes
template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE>*& head)
{

    node<ITEM_TYPE>* walker = head;
    node<ITEM_TYPE>* next_node = nullptr;

    bool debug = false;
    

    while(walker != nullptr)
    {
        next_node = walker->next;
        delete walker;
        walker = next_node;

        if(debug)
        cout << "\ndestruct\n";
    }

    head = nullptr;

}

//_item at this position
template <typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos)
{

    node<ITEM_TYPE>* walker = head;

    for(int i=0;i<pos;i++)
    {
        walker = walker->next;
    }

    return walker->_item; 

}
    

    // //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    // //      Sorted List Routines. order: 0: ascending, order: other: descending
    // //                              Assume a Sorted List
    // //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head,ITEM_TYPE item)
{
    node<ITEM_TYPE>* walker = head;
    node<ITEM_TYPE>* next = nullptr;
    node<ITEM_TYPE>* prev = nullptr;

    prev = _where_this_goes(head,item);

    _insert_after(head,prev,item);

    return head;

}

//insert or add if a dup
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head,ITEM_TYPE item)
{

    node<ITEM_TYPE>* walker = head;
    node<ITEM_TYPE>* next = nullptr;
    node<ITEM_TYPE>* prev = nullptr;

    prev = _where_this_goes(head,item);
    next = prev->next;

    if(next->_item == item)
    next->_item = item*2;

    return head;

}

//node after which this item goes order: 0 ascending
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head,ITEM_TYPE item,bool ascending)
{
    node<ITEM_TYPE>* walker = head;
    node<ITEM_TYPE>* prev = nullptr;

    while(walker != nullptr)
    {
        if(ascending == true)    {

            if(walker->_item < item)
            {
                prev = walker;
            }
        }
        else if(ascending == false)  {

            if(walker->_item > item)
            {
                prev = walker;
            }
        }

        //1-2-3-4-6

        walker = walker->next;
    }


    return prev;    
}
                                   
    //Last Node in the list
    template <typename ITEM_TYPE>
    node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head)
    {
        if(head == nullptr)
        return nullptr;
        
        node<ITEM_TYPE>* walker = head;

        while(walker->next != nullptr)
        {
            walker = walker->next;
        }

        return walker;
    }            //



    #endif

