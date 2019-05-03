#ifndef UI_MAINWINDOW_H_
#define UI_MAINWINDOW_H_

#include <string>
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace UI {
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateStockMessage(const std::string &message);
    std::string getSymbol() const;

    signals:
            void ViewButtonClicked();
private:
    ::Ui::MainWindow *m_ui;

};
} // UI
#endif // UI_MAINWINDOW_H_