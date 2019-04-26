#include "../hdr/mainwindow.h"
#include "../hdr/presenter.h"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

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
    std::string message;
    try {
        message = "Close: " + std::to_string(static_cast<long double>(chart["close"]));
    } catch(json::exception) {
        message = "Error fetching data";
    }
    m_view->updateStockMessage(message);
}
} // UI
