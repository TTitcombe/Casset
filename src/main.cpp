#include "IEX.h"

#include <iostream>

#include <fmt/format.h>

int main(int argc, char **argv) {
  IEX iex;
  const std::string date = iex.getChart("AAPL");
  fmt::print("Date is {}", date);
}
