#include <iostream>
#include <fmt/format.h>

#include "API/IEX.h"

int main(int argc, char **argv) {
  API::IEX iex;

  std::string symbol;
  fmt::print("Enter a stock symbol to collect data for: \n");
  std::cin >> symbol;

  const std::string chart = iex.getChart(symbol);
  fmt::print("Open is {}", chart);
}
