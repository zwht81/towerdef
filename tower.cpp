#include "tower.h"

Tower::Tower()
{

}



void Tower::initialtower(int x,int y){
    towerpic.load(":/image/GreenBottle.png");
    this->x=x;
    this->y=y+40;
    range=200;
    bullet.initialbullet(this->x,this->y);
    hasbullet=true;
    power=50;
}

void Tower::settarget(Enemy *p){
    targetenemy=p;
}

/*bool Tower::searchenemy(Enemy * p){

    if(range>sqrt(double(p->getx()-this->GetX())*double(p->getx()-this->GetX())
                  +double(p->gety()-this->GetY())*double(p->gety()-this->GetY())
                  )){
        this->bullet.hasenemy=true;
        this->bullet.settarget(p->getx(),p->gety());
        return true;
    }
    return false;





}*/

void Tower::show(QPainter *painter){
    painter->drawPixmap(x,y,80,80,towerpic);
    this->bullet.show(painter);
}

int Tower::GetX() const     //获取横坐标
{
    return x;
}

int Tower::GetY() const     //获取横坐标
{
    return y;
}




