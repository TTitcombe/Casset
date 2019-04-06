#include <iostream>
#include <fmt/format.h>

#include "API/IEX.h"

int main(int argc, char **argv) {
  API::IEX iex;

  std::string symbol;
  fmt::print("Enter a stock symbol to collect data for: \n");
  std::cin >> symbol;

  const json chart = iex.getChart(symbol);
  fmt::print("Chart is {}", chart.dump());
}
