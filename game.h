#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "enemy.h"
#include "QTimer"
#include "vector"
#include "tower.h"
#include "QTime"
#include <cmath>

using namespace std;

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    bool Isstart();
    void startgame();
    void initialgame();
    void createenemy();
    void show(QPainter * painter);
    //void timerEvent(QTimerEvent *e);
    vector<Enemy *> _enemys;
    vector<Tower *> _towers;
private:
    bool isstart;

    int waveenemy;
    QPixmap tower1;
    int timeid1;
    int timeid2;
    QTimer *timer1;
    QTimer *timer2;

signals:

public slots:
    void enemytime();
    void bullettime();
};

#endif // GAME_H
