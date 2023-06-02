#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QKeyEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int i_prbar=0;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LE_textChanged(const QString &arg1);
   // void on_pButton_toggle(bool);
//void on_pButton_toggle(bool);
void on_pButton_toggled(bool checked);

void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
