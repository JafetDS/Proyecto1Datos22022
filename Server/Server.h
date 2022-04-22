//
// Created by Jafet on 22/04/2022.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H
#include <iostream>
#include <string>
#include <winsock2.h>
#include <sstream>
using namespace std;
class Server {
public:
    Server();
    WSADATA WSAData;
    SOCKET server, client;
    SOCKADDR_IN serverAddr, clientAddr;
    char buffer[1024*100];

    string Recibir();
    void Enviar(string);
    void CerrarSocket();
    void Start();
};


#endif //SERVER_SERVER_H
