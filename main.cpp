#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
	w.setStyleSheet("QPushButton#RedSelectedButton {  border: 2px solid red; outline: none; }");
    w.show();
    return a.exec();
}
