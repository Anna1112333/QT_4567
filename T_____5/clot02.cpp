#include "clot02.h"
#include "QTimer"

Clot02::Clot02(QObject *parent): QObject{parent}{}

Clot02::~Clot02()
{
    qDebug() << "Получен деструктор Signals";
}

void Clot02::SendSignal_ss()  {
    emit sig_pb_ss();
qDebug() << "Получен Signals_ss";
}
void Clot02::SendSignal_r()
{
qDebug() << "Получен Signals_r  "<<qVersion();
    emit sig_pb_r();
}
void Clot02::SendSignal_time()
{
qDebug() << "Получен Signals_time  ";
}

void Clot02::setvalue(bool val)
{Clot02::value1=val;}

void Clot02::SendSignal_tema(){  //****
    emit sig_pb_tema();

}
//bool Clot02::value()  {return Clot02::value1;}
