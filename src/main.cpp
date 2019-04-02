#include "API/IEX.h"

#include <iostream>

#include <fmt/format.h>

int main(int argc, char **argv) {
  const auto iex = API::IEX();

  fmt::print("Enter a stock ticker in uppercase...\n");
  std::string symbol;
  std::cin >> symbol;

  const std::string data_date = iex.getChart(symbol);
  if (data_date != "") {
    fmt::print("Date for ticker {} is {}.\n", symbol, data_date);
  } else {
    fmt::print("Could not retrieve data date.\n");
  }
}
