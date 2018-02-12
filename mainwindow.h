#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_northButton_released();

    void on_eastButton_released();

    void on_southButton_released();

    void on_westButton_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
