#ifndef TOWER_H
#define TOWER_H

#include <QPainter>
#include <bullet.h>
#include <enemy.h>
#include <vector>

using namespace std;

class Tower
{
public:
    Tower();
    void initialtower(int x,int y);
    void show(QPainter * painter);
    int GetX() const;     //获取横坐标
    int GetY() const;     //获取横坐标
    int getrange() const{
        return range;
    }
    bool hasbullet;
    Bullet  bullet;
    Enemy * targetenemy=NULL;
    void settarget(Enemy *p);
    int getpower()const{
        return power;
    }



private:
    QPixmap towerpic;
    int x;
    int y;
    int range;
    int cost;
    int power;


};


#endif // TOWER_H
