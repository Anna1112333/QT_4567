#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "clot02.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <chrono>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void get_pb_r();
    void get_pb_ss();
    void time_sl();
    void on_pb_thema(); //++++
private slots:

    void on_pb_round_clicked();
    void on_pb_ss_toggled(bool checked);
    void Taimer_slot();
    void on_pb_clear_clicked();
private:
    Ui::MainWindow *ui;
    Clot02 *pb_r;
    QTimer *time;

int  time1_2, time1, time2, time21, time22, thema;

};
#endif // MAINWINDOW_H
