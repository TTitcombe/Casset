#include <nlohmann/json.hpp>

#include "../hdr/presenter.h"
#include "../../API/hdr/stockinfo.h"


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
  StockInfo stock(chart);
  m_view->updateStockMessage(stock.getStockReport());
}
} // UI
