#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;
        int nodes;

    public:
        List(){
			start= nullptr;
			nodes=0;
        };

        T front(){
        	if(!start){
        		throw "Lista Vacia";
        	}else{
        		cout<<start->data;
        	}

        };

        T back(){
			Node<T>* temp= new Node<T>;
        	if(!start){
        		throw "Lista Vacia";
        	}else{
        		temp=start->prev;
        		cout<<temp->data;
        	}
        	delete temp;
        };

        void push_front(T value){
        	Node<T>* temp = new Node<T>;
			temp -> data = value;
			if(!start){
				start -> next = start;
                start -> prev = start;
            }else{
			    temp ->next=start;
                temp -> prev = start -> prev;
                temp->next->prev=temp;
                temp->prev->next=temp;
            }
            start = temp;
			nodes++;
            delete temp;
        };

        void push_back(T value){
            Node<T>* temp = new Node<T>;
            temp -> data = value;
            if(!start){
                start -> next = start;
                start -> prev = start;
            }else{
                temp -> next = start;
                temp -> next->prev = temp;
                temp -> prev = start -> prev;
                temp -> prev -> next = temp
                start -> prev = temp -> prev;
            }
            start=temp;
            nodes++;
            delete temp;
        };

        void pop_front(){
            if(!start){
                throw "Lista vacia";
            }else if(nodes==1){
                start= nullptr;
            }else{
                Node<T>* temp = start;
                start ->prev ->next=start->next;
                start->next->prev=start->prev;
                start = start -> next;
            }
            nodes--;
            delete temp;
        };

        void pop_back(){
            if(!start){
                throw "Lista vacia";
            }else if(nodes==1){
                start= nullptr;
            }else{
                Node<T>* temp = start->prev;
                start->prev->prev->next=start;
                start->prev=start->prev->prev;
            }
            nodes--;
            delete temp;
        };

        T get(int position){
			if(position<0 || position>nodes){
				throw "Poss... null";
			}
			position=position % nodes;
			int index =0;
			Node<T>* temp = start;
			while(index>position){
				if(index == position){
					return temp->data;
				}
				temp=temp->next;
				index ++;
			}
			delete temp;
        };

        void concat(List<T> &other){
            Iterator<T> temp;
            temp= other.begin();
            while(Auxiliar != other.end()){
                push_back(*temp);
            }
        };

        bool empty(){
            if(!start){
                throw "Lista vacia";
            }else {
                return nodes==0;
            }
        };

        int size(){
		    return nodes;
        };

        void clear(){
            while(start){
                pop_front();
            }
        };

        Iterator<T> begin(){
            return Iterator<T>(start);
        };

        Iterator<T> end(){
            return Iterator<T>(start -> prev);
        };

        ~List() {
			clear();
		};
};

#endif
