#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ZorkUL.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_northButton_clicked();
    void on_southButton_clicked();
    void on_eastButton_clicked();
    void on_westButton_clicked();


    void on_teleportButton_clicked();
    void on_takeButton_clicked();
    void on_putButton_clicked();
    void on_inventoryButton_clicked();

private:
    Ui::MainWindow *ui;
    ZorkUL zork;
    void displayCurrentRoomInfo();
    void updateInventoryLabel();
};

#endif // MAINWINDOW_H
