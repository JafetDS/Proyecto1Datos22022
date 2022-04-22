//
// Created by Jafet on 22/04/2022.
//
#include "Matriz.h"
#include "Server.h"
#include "Memory.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#ifndef SERVER_GAME_H
#define SERVER_GAME_H


class Game {
public:
    Matriz<int> matriz;
    Memory memory;

    Game();
    Server server;
    int *Cplayer;
    int player1;
    int player2;
    int turn;
    int Pcard;
    Memory Memo;
    string Nameplayer1;
    string Nameplayer2;




    void Player_Points(int);
    void Send_image();
    void print();
    void Create_game();
    void Swap();
    bool Selec(int a, int b, int c, int d);

    void set_Players(string name1, string name2);

    void Start();

    string checkWinner();

    bool checkWin();
};


#endif //SERVER_GAME_H
