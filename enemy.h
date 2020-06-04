#ifndef ENEMY_H
#define ENEMY_H

#include "QPainter"

class Enemy
{
public:
    Enemy();
    void show(QPainter * painter);
    void initialenemy();
    bool arrive();
    void move();
    int getx()const{
        return x;
    }
    int gety()const{
        return y;
    }
    void injure(int n);
    bool death();
    int health;
private:
    QPixmap enemypic;

    int speed;
    int x;
    int y;


};

#endif // ENEMY_H
