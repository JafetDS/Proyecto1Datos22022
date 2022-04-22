#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Flujo(){
    Iniciar();
    Setear();
   // Jugar();
}
void MainWindow::Iniciar(){
    sThread = new Thread(this,&mensaje);
    this->sThread->startServer();

    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("User name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);

    this->ui->J1->setText(text);
    this->sThread->sendmsj(text.toStdString());

    text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("User name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    this->ui->J2->setText(text);
    this->sThread->sendmsj(text.toStdString());



}

void MainWindow::Setear(){

    this->FCard = 0;

    QPixmap *pixmap = new QPixmap("://Image/Back.jpg");
    QIcon *icon = new QIcon(*pixmap);
    for (int i = 0; i<3;i++){
        for(int j = 0; j<4; j++){
            QPushButton *button = new QPushButton(this);
            button->setIcon(*icon);
            connect(button,SIGNAL(clicked()),this,SLOT(int a = i; int b = j; Play(a,b,button)));

        }
    }
}


void MainWindow::Play(int a, int b,QPushButton *button){

    FCard = FCard + 1;
    prevcard = button;

    this->sThread->sendmsj(to_string(a*10+b));

    ofstream image("://Image/carta.png", ios::out | ios::binary);
    string ms = this->mensaje;
    char c;
        for (int i = 0; i<ms.size();i++){
            image.put(c);
        }
        image.clear();

    QPixmap *pixmap = new QPixmap("://Image/carta.jpg");
    QIcon *icon = new QIcon(*pixmap);
    button->setIcon(*icon);

    ms = this->mensaje;

    if(ms =="false"){
        pixmap = new QPixmap("://Image/Back.jpg");
        icon = new QIcon(*pixmap);
        button->setIcon(*icon);

        pixmap = new QPixmap("://Image/Back.jpg");
        icon = new QIcon(*pixmap);
        prevcard->setIcon(*icon);
    }

    ms = this->mensaje;

    if(player1){
        sum();
        player1=false;
    }else{
        player1=true;
    }



}
