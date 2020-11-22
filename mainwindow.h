#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <qdebug.h>


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
    void moveUpdate();
    void on_runBut_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer = nullptr;
    QTimer moveTimer;
    enum class dir{left,right} butDir = dir::left;
    enum class state{running,stationary}
                    butState = state::stationary;
};
#endif // MAINWINDOW_H
