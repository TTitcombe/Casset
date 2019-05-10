#include "stockinfo.h"

#include <map>
#include <string>

//using PortfolioPair = std::pair<int, StockInfo>;
using PortfolioMap = std::map<std::string, int>;

class Portfolio {
public:
    Portfolio();
    void addStock(const int numberOfShares, const StockInfo stock);
    void removeStock(const std::string &stockSymbol);
    void rename(const std::string &name);
    std::string getName() const;
    float getValue() const;
private:
    std::string m_name = "MyPortfolio";
    float m_value = 0.0;
    Currency m_currency = Currency::usd;
    PortfolioMap m_stocks;
};