#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QListWidgetItem"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{  
    QPushButton *pb_t =new QPushButton(this);  //++++
    startTimer(1000);
    ui->setupUi(this);
    this->setWindowTitle("Таймер кругов");
    pb_r = new Clot02(this);
    time = new QTimer(this);
    time->setInterval(1);  
    time1=0; time2=0; time21=0, thema=0;
    ui->pb_round->setChecked(true);
    ui->pb_ss->toggle();
     ui->pb_ss->setText("Старт");
    connect (pb_r, &Clot02::sig_pb_r, this, &MainWindow::get_pb_r);
    connect (pb_r, &Clot02::sig_pb_ss, this, &MainWindow::get_pb_ss);
   connect (pb_r, &Clot02::sig_pb_tema, this, &MainWindow::on_pb_thema);
    connect (time, &QTimer::timeout, this, &MainWindow::time_sl);
    connect (time, &QTimer::timeout, this, &MainWindow::Taimer_slot);
}

MainWindow::~MainWindow(){   delete ui;}

void MainWindow::get_pb_r()
{time1_2=time1-time2;
      ui->tbr->append("круг "+QString::number(time1_2/3600000%60)+" "
                      +QString::number(time1_2/60000%60)+" "
                      +QString::number(time1_2/1000%60)+" "
                      +QString::number(time1_2%60)+" "
                      );
time2=time1;
}
void MainWindow::get_pb_ss()
{
   ui->lb_time->setText("Время *****: "+QTime::currentTime().toString()+" ");

}

void MainWindow::time_sl()
{int a, b, c, d;
    a=time21%1000; //milliseconds
    b=time21/1000%60; //seconds
    c=time21/60000%60; //minutes
    d=time21/3600000%60; //hours
    time1++; time21++;

 ui->lb_time->setText("Время после старта: "
                      +QString::number(d)+" "
                      +QString::number(c)+" "
                      +QString::number(b)+" "
                      +QString::number(a)+" ");
}

void MainWindow::on_pb_thema()
{
pb_r->SendSignal_tema();

   ui->tbr->setStyleSheet("background-color: green");
}
void MainWindow::on_pb_round_clicked()
{
    if(ui->pb_round->isEnabled())
        pb_r->SendSignal_r();
}
void MainWindow::on_pb_ss_toggled(bool agv)
{
    int a, b, c, d;
        a=time21%1000; //milliseconds
        b=time21/1000%60; //seconds
        c=time21/60000%60; //minutes
        d=time21/3600000%60; //hours
    if(agv) {time->start();
        ui->pb_ss->setText("Стоп");

    ui->lb_time->setText("Время после старта: "
                         +QString::number(d)+" "
                         +QString::number(c)+" "
                         +QString::number(b)+" "
                         +QString::number(a)+" ");

    }
    else {time->stop();
        ui->pb_ss->setText("Продолжить");
        ui->lb_time->setText("Время после старта: "
                               +QString::number(d)+" "
                               +QString::number(c)+" "
                               +QString::number(b)+" "
                               +QString::number(a)+" ");
    }
}

void MainWindow::Taimer_slot(){}
void MainWindow::on_pb_clear_clicked()
{
    time21=0;
    time->stop(); 
    ui->lb_time->setText("Время");
    ui->pb_ss->setText("Старт");
}

