//
// Created by Jafet on 22/04/2022.
//

#ifndef SERVER_MATRIZ_H
#define SERVER_MATRIZ_H
#include "Node.h"
#include <algorithm>
#include <functional>

using namespace std;


template <class T>

class Matriz {
    typedef const function<void()>& lambdaNode_down_next;

private:
    Node<T> head;
    void roll(int direc, lambdaNode_down_next func) {
        for(int i = 0; i<direc; i++){
            func();
        }
    }


    Node<T>* roller(int row, int column) {
        Node<T> *puntero = &(this->head);
        roll(row,[&](){puntero = puntero->getDown();});
        roll(column,[&](){puntero = puntero->getNext();});
        return puntero;
    }

public:

    void setData(int row, int column, T data) {
        this->roller(row,column)->setData(data);
    }

    T getData(int row, int column) {
        return this->roller(row,column)->getData();
    }
};


#endif //SERVER_MATRIZ_H
