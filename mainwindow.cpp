#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


using namespace std;

#define msclick(X, Width, Y, Height)    \
    (ev->x() >= (X) && ev->x() <= (X) + (Width) &&  \
    ev->y() >= (Y) && ev->y() <= (Y) + (Height))

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1440,640);
    _map.initialmap();
    _player.Initialplayer();
    _game.initialgame();

    playerbutton1= new Mybutton(":/image/player.jpg");
    playerbutton1->setFixedSize(280,200);
    playerbutton1->setIconSize(QSize(280,200));
    playerbutton1->setParent(this);
    playerbutton2= new Mybutton(":/image/player2.jpg");
    playerbutton2->setFixedSize(280,200);
    playerbutton2->setIconSize(QSize(280,200));
    playerbutton2->setParent(this);
    playerbutton1->move(1110,20);
    playerbutton2->move(1110,20);
    playerbutton2->hide();
    connect(playerbutton1,&QPushButton::clicked,this,[=](){
        playerbutton1->hide();
        playerbutton2->show();
    });
    connect(playerbutton2,&QPushButton::clicked,this,[=](){
        playerbutton2->hide();
        playerbutton1->show();
    });
    startbutton= new Mybutton(":/image/startgame.jpg");
    startbutton->setFixedSize(100,100);
    startbutton->setIconSize(QSize(100,100));
    startbutton->setParent(this);
    startbutton->move(1100,430);

    connect(startbutton,&QPushButton::clicked,this,[=](){
        if(!_game.Isstart()){
            _game.startgame();
            timeid1=startTimer(100);
        }
    });
    buildtowerbutton=new Buildtowerbutton(":/image/greenbutton.png",10);
    buildtowerbutton->setParent(this);
    buildtowerbutton->hide();

    buildtowerbutton->move(500,500);
    connect(buildtowerbutton,&QPushButton::clicked,this,[=](){
        buildtowerbutton->hide();
        if(_player.getmoney()>=buildtowerbutton->cost){
            _player.spendmoney(buildtowerbutton->cost);
            Tower* p1=new Tower;
            p1->initialtower(buildtowerbutton->x(),buildtowerbutton->y());
            _game._towers.push_back(p1);
            repaint();
        }
    });





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    QPainter * pa;
    pa = new QPainter();
    pa->begin(this);
    _map.drawmap(pa);
    _player.show(pa);
    _game.show(pa);

}


void MainWindow::timerEvent(QTimerEvent *e){
    Q_UNUSED(e);

    int n = _game._enemys.size();
    int i;
    for(i=0;i<n;i++){
        _game._enemys[i]->move();
        if(_game._enemys[i]->arrive()){
            _game._enemys.erase(_game._enemys.begin()+i);
            _player.healthminus(1);
        }
        if(_game._enemys[i]->death()){
            _game._enemys.erase(_game._enemys.begin()+i);
            _player.gainmoney();
        }
    }


    repaint();
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
    int n=_map._towerarea.size();
    int i,j;
    for(i=0;i<n;i++){
        if(msclick(_map._towerarea[i]->GetX(), _map._towerarea[i]->GetWidth(), _map._towerarea[i]->GetY(), _map._towerarea[i]->GetHeight())){
            int m=_game._towers.size();
            int flag=1;
            for(j=0;j<m;j++){
                if(_game._towers[j]->GetX()==_map._towerarea[i]->GetX()&&_game._towers[j]->GetY()==_map._towerarea[i]->GetY()){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                buildtowerbutton->move(_map._towerarea[i]->GetX(),_map._towerarea[i]->GetY()-40);
                buildtowerbutton->show();
                break;
            }
        }
        else{
            buildtowerbutton->hide();
        }
    }



}
