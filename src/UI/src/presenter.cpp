#include "../hdr/mainwindow.h"
#include "../hdr/presenter.h"

#include <iostream>

namespace UI {
Presenter::Presenter(MainWindow *v) : m_view(v) {
    QObject::connect(m_view, SIGNAL(ViewButtonClicked()), this, SLOT(onViewButtonClicked()));
    try {
        m_logger = spdlog::stderr_color_mt("PRESENTER_LOG");
    } catch (spdlog::spdlog_ex) {
        m_logger = spdlog::get("PRESENTER_LOG");
    }
}

void Presenter::onViewButtonClicked() {
    const json chart = m_iex.getChart("AAPL");
    m_logger->info("Chart is {}", chart.dump());
}
} // UI
