#include "thread.h"
#include <QtCore>
#include <QDebug>
#include <iostream>
#include<stdlib.h>




using namespace std;
Thread::Thread(QObject *parent, string* mensaje): QThread(parent),
    mensaje(mensaje)
{
        Servidor = new Server();
}

void Thread::sendmsj(string codeText){
    Servidor->Enviar(codeText);
}

void  Thread::startServer(){
    this->Servidor->Start();
}

void Thread::run(){
    while(true){
        *mensaje = Servidor->Recibir();
    }

}
