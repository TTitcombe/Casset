#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <iostream>

#include "../hdr/mainwindow.h"

namespace UI {
MainWindow::MainWindow() :
        QMainWindow() {
    setWindowTitle("Casset");
    QWidget *wdg = new QWidget(this);
    QVBoxLayout *vlay = new QVBoxLayout(wdg);
    QPushButton *button = new QPushButton("Get AAPL");
    vlay->addWidget(button);
    wdg->setLayout(vlay);
    setCentralWidget(wdg);

    QObject::connect(button, SIGNAL(clicked()), this, SIGNAL(ViewButtonClicked()));
}
} // UI
