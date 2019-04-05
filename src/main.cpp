#include "API/IEX.h"

#include <iostream>

#include <fmt/format.h>

int main(int argc, char **argv) {
  API::IEX iex;

  std::string symbol;
  fmt::print("Enter a stock symbol to collect data for: \n");
  std::cin >> symbol;

  const std::string date = iex.getChart(symbol);
  fmt::print("Date is {}", date);
}
