#ifndef BUILDTOWERBUTTON_H
#define BUILDTOWERBUTTON_H

#include <QWidget>
#include <mybutton.h>

class Buildtowerbutton : public Mybutton
{
    Q_OBJECT
public:
    Buildtowerbutton(QString pix,int n);
    int cost;


};

#endif // BUILDTOWERBUTTON_H
