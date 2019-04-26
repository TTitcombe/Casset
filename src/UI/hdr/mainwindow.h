#ifndef UI_MAINWINDOW_H_
#define UI_MAINWINDOW_H_

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow();

    signals:
      void ViewButtonClicked();

};
#endif // UI_MAINWINDOW_H_