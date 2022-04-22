//
// Created by Jafet on 22/04/2022.
//

#include "Server.h"


Server::Server()
{

}

void Server::Start()
{

    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5555);

    bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    listen(server, 0);

    cout << "Escuchando para conexiones entrantes." << endl;
    int clientAddrSize = sizeof(clientAddr);
    if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
    {
        cout << "Cliente conectado!" << endl;
    }

}

string Server::Recibir()
{
    recv(client, buffer, sizeof(buffer), 0);
    cout << "El cliente dice: " << buffer << endl;
    memset(buffer, 0, sizeof(buffer));
}
void Server::Enviar(string mensaje)
{
    for(int i = 0; i<=(int)mensaje.length();i++){
        this->buffer[i]=mensaje[i];
    }

    //cout<<"Escribe el mensaje a enviar: ";
    //cin>>this->buffer;
    send(client, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    cout << "Mensaje enviado!" << endl;
}
void Server::CerrarSocket()
{
    closesocket(client);
    cout << "Socket cerrado, cliente desconectado." << endl;
}


