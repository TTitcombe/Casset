#include "../hdr/portfolio.h"

Portfolio::Portfolio() {
}

void Portfolio::addStock(const int numberOfShares, const StockInfo stock) {
  const std::string stockSymbol = stock.getSymbol();
  if (m_stocks.find(stockSymbol) == m_stocks.end()) {
    m_value += numberOfShares * stock.getClose();
    m_stocks.insert(std::pair<std::string, int>(stockSymbol,numberOfShares));
  }
  else {
    throw std::invalid_argument("This portfolio already contains the stock.");
  }
}

void Portfolio::removeStock(const std::string &stockSymbol) {
  if (m_stocks.find(stockSymbol) != m_stocks.end()) {
    //PortfolioPair stock = m_stocks[stockSymbol];
    int valueToRemove = m_stocks[stockSymbol];
    m_value -= valueToRemove;
    m_stocks.erase(stockSymbol);
  }
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
