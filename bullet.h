#ifndef BULLET_H
#define BULLET_H

#include <QPainter>
#include <cmath>

class Bullet
{
public:
    Bullet();
    void move();
    void show(QPainter * painter);
    void initialbullet(int x,int y);
    void setbullet();
    bool crash();
    void settarget(int x,int y);
    bool hasenemy;
    bool isexploded;
private:
    int x;
    int y;
    int initialx;
    int initialy;
    int speed;
    int targetx;
    int targety;
    QPixmap bulletpic;
    QPixmap explosion;

};

#endif // BULLET_H
