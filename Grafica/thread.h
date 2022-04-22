#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QObject>
#include <string>
#include <vector>
#include "server.h"
using namespace std;
class Thread : public QThread
{
    Q_OBJECT
public:
     Thread(QObject *parent = nullptr,string* mensaje= nullptr);
     void sendmsj(string);
     void startServer();
     Server *Servidor;
     string *mensaje;

protected:
     void run() override;




};

#endif // THREAD_H
