#ifndef PLAYER_H
#define PLAYER_H

#include "QPainter"
#include "mybutton.h"

class Player
{
public:
    Player();
    void Initialplayer();
    void show(QPainter * painter);
    void healthminus(int n);
    int  getmoney();
    void spendmoney(int n);
    void gainmoney();
private:

    int health;
    int money;
};

#endif // PLAYER_H
