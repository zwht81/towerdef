#include "enemy.h"

Enemy::Enemy()
{

}

void Enemy:: show(QPainter * painter){
    painter->drawPixmap(x,y,80,80,enemypic);

}

void Enemy::initialenemy(){
    health=100;
    speed=10;
    x=80;
    y=480;
    enemypic.load(":/image/enemy1.jpg");
}

void Enemy::move(){
    x+=5;

}

bool Enemy::arrive(){
    if((x<=680)&&(x>=670)&&(y>=480)&&(y<=520))
        return true;
    return false;
}

void Enemy::injure(int n){
    health-=n;
}

bool Enemy::death(){
    if(health<=0)
        return true;
    return false;
}
