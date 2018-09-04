#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;
    
    public:
        Iterator(){
            current= nullptr;
        };
        Iterator(Node<T>* node){
            current=node;
        };
         
        Iterator<T> operator=(Iterator<T> node){
            current=current.node;
            return *current;
        };
        bool operator!=(Iterator<T> cmp){
            return cmp.current != current;
        };
        Iterator<T> operator++(){
            if (current)
            {
                current = current -> next;
                return *current;
            }
        };
        Iterator<T> operator--(){
            if (current)
            {
                current = current -> prev;
                return *current;
            }
        };
        T operator*(){
            return current -> data;
        };
};

#endif