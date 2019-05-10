#include <fmt/format.h>

#include "../hdr/stockinfo.h"

StockInfo::StockInfo(const std::string &symbol, const json &stockChart) {
  m_open = extractFromJson<float>("open", stockChart);
  m_close = extractFromJson<float>("close", stockChart);
  m_low = extractFromJson<float>("low", stockChart);
  m_high = extractFromJson<float>("high", stockChart);
  m_date = extractFromJson<std::string>("date", stockChart);
  m_symbol = symbol;
}

StockInfo::StockInfo(const std::string &symbol, const std::string &date,
                     const float close) : m_close(close), m_date(date), m_symbol(symbol) {
}

std::string StockInfo::getSymbol() const {
  return m_symbol;
}

std::string StockInfo::getStockReport() const {
  const std::string report = fmt::format("{} closed on {} at ${:.2f}", m_symbol, m_date, m_close);
  return report;
}

float StockInfo::getClose() const {
  return m_close;
}

template <class T>
T StockInfo::extractFromJson(const std::string &key, const nlohmann::json &stockChart) const {
    T value;
    if (stockChart.find(key) != stockChart.end())
      value = stockChart[key].get<T>();
    return value;
}