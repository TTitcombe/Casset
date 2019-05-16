#include "../hdr/presenter.h"
#include "../../API/hdr/stockinfo.h"

#include <algorithm>
#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <regex>


using json = nlohmann::json;

namespace UI {
Presenter::Presenter(MainWindow &v) : m_view(v) {
  QObject::connect(&m_view, SIGNAL(ViewButtonClicked()), this, SLOT(onViewButtonClicked()));
  try {
      m_logger = spdlog::stderr_color_mt("PRESENTER_LOG");
  } catch (spdlog::spdlog_ex &) {
      m_logger = spdlog::get("PRESENTER_LOG");
  }
}

void Presenter::onViewButtonClicked() {
  std::string symbol = m_view.getSymbol();
  // Stock symbols can only be 4 characters at most
  if (symbol.length() > 4) {
    const std::string message = fmt::format("{} is too long for a stock symbol", symbol);
    m_view.updateStockMessage(message);
    return;
  }

  // Stock symbols contain alphabetical characters only
  if (!std::regex_match(symbol, std::regex("^[A-Za-z]+$"))) {
    const std::string message = fmt::format("{} contains not alphabetical characters", symbol);
    m_view.updateStockMessage(message);
    return;
  }
  // Stock symbols are uppercase
  std::transform(symbol.begin(), symbol.end(),symbol.begin(), ::toupper);
  if (m_iex.isValidSymbol(symbol)) {
    const json chart = m_iex.getChart(symbol);
    StockInfo stock(symbol, chart);
    m_view.updateStockMessage(stock.getStockReport());
  } else {
    const std::string message = fmt::format("{} was not a recognised stock symbol", symbol);
    m_view.updateStockMessage(message);
  }
}
} // UI
