#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startBut_clicked();
    void advanceProgress();
    void react();
    void on_spinBox_valueChanged(int arg1);
    void on_leftBut_clicked();
    void on_rightBut_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer = nullptr;
    enum class dir{left,right} butDir = dir::left;
};
#endif // MAINWINDOW_H
