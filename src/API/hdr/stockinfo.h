#include <string>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

enum class Currency {usd};

class StockInfo {
public:
  StockInfo();
  StockInfo(const std::string &symbol, const json &stockChart);
  StockInfo(const std::string &symbol, const std::string &date,
            const float close);
  std::string getSymbol() const;
  std::string getStockReport() const;
  float getClose() const;
  void setShares(const int numberOfShares);
  float getValue() const;

  bool operator==(const StockInfo &s) const {
    if (m_symbol != s.getSymbol()) {
      return false;
    } else {
      return m_close == s.getClose();
    }
  }

private:
  float m_open;
  float m_close;
  float m_low;
  float m_high;
  int m_shares = 0;
  Currency m_currency = Currency::usd;
  std::string m_date;
  std::string m_symbol;
  template <class T>
  T extractFromJson(const std::string &key, const json &stockChart) const;
};