#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPrinter>
#include <string>
#include<iostream>
#include<stdlib.h>
#include <vector>
#include <QPushButton>
#include "server.h"
#include "thread.h"
#include <QInputDialog>
#include <QDir>
#include <iostream>
#include <fstream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Thread;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Iniciar();
    void Setear();
    void Play(int,int,QPushButton);


private:
    Ui::MainWindow *ui;
    string mensaje;
    Server *Servidor;
    Thread *sThread;
    QPushButton* prevcard;
    int FCard;



};
#endif // MAINWINDOW_H
