#include "stockinfo.h"

#include <fmt/format.h>
#include <map>
#include <string>
#include <utility>

using PortfolioMap = std::map<std::string, StockInfo>;

class Portfolio {
public:
    Portfolio();
    void addStock(const int numberOfShares, StockInfo &stock);
    void removeStock(const std::string &stockSymbol);
    bool hasStock(const std::string &stockSymbol) const;
    void rename(const std::string &name);
    std::string getName() const;
    float getValue() const;

    bool operator==(const Portfolio &p) const{
      return m_value == p.getValue();
    };
private:
    std::string m_name = "MyPortfolio";
    float m_value = 0.0;
    Currency m_currency = Currency::usd;
    PortfolioMap m_stocks;
};