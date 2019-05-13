#include "../hdr/portfolio.h"

Portfolio::Portfolio() {
}

void Portfolio::addStock(const int numberOfShares, const StockInfo stock) {
  if (numberOfShares <= 0) {
    throw std::invalid_argument("You can only hold a positive, non-zero number of shares");
  }

  const std::string stockSymbol = stock.getSymbol();
  if (!hasStock(stockSymbol)) {
    m_value += numberOfShares * stock.getClose();
    m_stocks.insert({stockSymbol, numberOfShares});
  }
  else {
    throw std::invalid_argument(fmt::format("This portfolio already contains {}.", stockSymbol));
  }
}

void Portfolio::removeStock(const std::string &stockSymbol) {
  if (hasStock(stockSymbol)) {
    //PortfolioPair stock = m_stocks[stockSymbol];
    int valueToRemove = m_stocks[stockSymbol];
    m_value -= valueToRemove;
    m_stocks.erase(stockSymbol);
  } else {
    throw std::invalid_argument(fmt::format("This portfolio does not contain {}", stockSymbol));
  }
}

bool Portfolio::hasStock(const std::string &stockSymbol) const {
  return (m_stocks.find(stockSymbol) != m_stocks.end());
}

void Portfolio::rename(const std::string &name) {
  m_name = name;
}

std::string Portfolio::getName() const {
  return m_name;
}

float Portfolio::getValue() const {
  return m_value;
}
