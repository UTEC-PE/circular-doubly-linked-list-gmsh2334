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
            current=current.node;// Esto está mal, no va a compilar. Current no tiene node, current es un puntero
            return *current;
        };
        bool operator!=(Iterator<T> cmp){
            return cmp.current != current;
        };
        Iterator<T> operator++(){
            if (current) // No es necesario
            {
                current = current -> next;
                return *current;
            }
        };
        Iterator<T> operator--(){
            if (current) // No es necesario
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