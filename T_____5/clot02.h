#ifndef CLOT02_H
#define CLOT02_H
//#include "mainwindow.h"
#include <QObject>
#include <QDebug>


class Clot02: public QObject
{
    Q_OBJECT

public:

bool value1=true;
void setvalue(bool val);
//bool value() const;
   explicit Clot02(QObject *parent = nullptr);
    ~Clot02();

void SendSignal_ss();
void SendSignal_r();
void SendSignal_time();
void SendSignal_tema();  //++++

signals:
void sig_pb_tema();  //++++
    void sig_pb_ss();
    void sig_pb_r();
    void time();
};

#endif // CLOT02_H
