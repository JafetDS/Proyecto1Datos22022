//
// Created by Jafet on 22/04/2022.
//
#include <iostream>
#include <fstream>
using namespace std;
#ifndef SERVER_MEMORY_H
#define SERVER_MEMORY_H


class Memory {
public:
    Memory();
    string getImage(int);
private:

    int Page;
    int Point;
    ifstream images[2];
    void ChangePage(int n);
    string compimg(int);
};


#endif //SERVER_MEMORY_H
