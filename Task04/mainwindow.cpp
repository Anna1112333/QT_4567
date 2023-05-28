#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include "QListWidgetItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

ui->rButton->setText("Кнопка1");
ui->rButton_2->setText("Кнопка2");
ui->pButton->setText("Кнопка ");

ui->pButton->toggle();
ui->prBar->setMinimum(0);
ui->prBar->setMaximum(100);
ui->prBar->setValue(0);
ui->prBar->value();

for(int i=1; i<11; ++i)
{
ui->LW->addItem("Элемент списка № "+QString::number(i));
}


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LE_textChanged(const QString &arg1){}

int i=-10;
//void MainWindow::on_pButton_toggle(bool toggled){}


void MainWindow::on_pButton_toggled(bool checked)
{
    if(checked)
        ui->prBar->setValue(i);
        i+=5;
        if(i==110) i=0;
}

