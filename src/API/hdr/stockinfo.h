#include <string>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class StockInfo {
public:
  StockInfo(const std::string &symbol, const json &stockChart);
  StockInfo(const std::string &symbol, const std::string &date,
            const float close);
  std::string getSymbol() const;
  std::string getStockReport() const;
  float getClose() const;
private:
  float m_open;
  float m_close;
  float m_low;
  float m_high;
  std::string m_date;
  std::string m_symbol;
  template <class T>
  T extractFromJson(const std::string &key, const json &stockChart) const;
};