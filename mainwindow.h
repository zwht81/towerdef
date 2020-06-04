#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <map.h>
#include <player.h>
#include "mybutton.h"
#include "game.h"
#include <QTimer>
#include <vector>
#include "towerarea.h"
#include <QMouseEvent>
#include "buildtowerbutton.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *e);
    void mousePressEvent(QMouseEvent *ev);
    ~MainWindow();
signals:
    void tostart();

private:
    Ui::MainWindow *ui;
    Map _map;
    Player _player;
    Game _game;

    Mybutton* playerbutton1;
    Mybutton* playerbutton2;
    Mybutton* startbutton;
    Buildtowerbutton* buildtowerbutton;


    int timeid1;
    int timeid2;
};

#endif // MAINWINDOW_H
