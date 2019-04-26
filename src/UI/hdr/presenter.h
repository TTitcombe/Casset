#include <QObject>

#include "mainwindow.h"

class Presenter : public QObject
{
    Q_OBJECT
public:
    Presenter(MainWindow* v);


public slots:
            void onViewButtonClicked();
private:
    MainWindow *m_view = nullptr;

};