#ifndef MAP_H
#define MAP_H

#include <QPainter>
#include <vector>
#include "towerarea.h"
#include <iostream>

using namespace std;

class Map
{
public:
    Map();
    void drawmap(QPainter* painter);
    void initialmap();
    vector<Towerarea *> _towerarea;
private:
    int maparr[16][27];
    QPixmap grass;
    QPixmap road;
    QPixmap towerarea;
    QPixmap entrance;
    QPixmap home;


};

#endif // MAP_H
