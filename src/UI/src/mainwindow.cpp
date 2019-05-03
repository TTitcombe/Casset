#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QString>

#include "../hdr/mainwindow.h"
#include "../hdr/ui_mainwindow.h"

namespace UI {
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), m_ui(new ::Ui::MainWindow)
{
        m_ui->setupUi(this);
        this->setWindowTitle("Casset");

        QObject::connect(m_ui->stockButton, SIGNAL(clicked()), this, SIGNAL(ViewButtonClicked()));
}

MainWindow::~MainWindow() {
    delete m_ui;
}

std::string MainWindow::getSymbol() const {
  return m_ui->symbolLineEdit->text().toStdString();
}

void MainWindow::updateStockMessage(const std::string &message) {
    m_ui->stockInfoLabel->setText(QString::fromStdString(message));
}
} // UI
