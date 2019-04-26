#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <iostream>

#include "../hdr/mainwindow.h"

MainWindow::MainWindow() :
        QMainWindow()
{
    setWindowTitle("Casset");
    QWidget * wdg = new QWidget(this);
    QVBoxLayout *vlay = new QVBoxLayout(wdg);
    QPushButton *button = new QPushButton("Say Hello");
    vlay->addWidget(button);
    wdg->setLayout(vlay);
    setCentralWidget(wdg);

    QObject::connect(button,SIGNAL(clicked()),this,SIGNAL(ViewButtonClicked()));
}
