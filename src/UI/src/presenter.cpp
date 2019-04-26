#include "../hdr/mainwindow.h"
#include "../hdr/presenter.h"

#include <iostream>

Presenter::Presenter(MainWindow *v) : m_view(v)
{
    QObject::connect(m_view,SIGNAL(ViewButtonClicked()),this,SLOT(onViewButtonClicked()));

}

void Presenter::onViewButtonClicked()
{
    std::cout << "Hello\n";
}
