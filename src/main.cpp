#include <iostream>
#include <map>
#include <string>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <fmt/format.h>

using json = nlohmann::json;

const std::string IEX_ENDPOINT = "https://api.iextrading.com/1.0";

bool isValidSymbol(const std::string &symbol) {
  const std::string url = IEX_ENDPOINT + "/ref-data/symbols";
  const auto response = cpr::Get(cpr::Url{url}, cpr::VerifySsl{false});
  if (response.status_code == 200) {
    const auto json_objects = json::parse(response.text);
    for (const auto &symbol_data : json_objects)
      if (symbol_data["symbol"].get<std::string>() == symbol)
        return true;
    fmt::print("Tickers must be in uppercase.\n");
  }
  return false;
}

cpr::Response getChart(const std::string &symbol) {
  const std::string url = IEX_ENDPOINT + "/stock/"+symbol+"/chart";

  fmt::print("Starting GET req at url {}. \n", url);
  return cpr::Get(cpr::Url{url},
                  cpr::VerifySsl{false});  // CPR issue #194
}

int main(int argc, char **argv) {
  std::string symbol;
  fmt::print("Enter a stock symbol to collect data for: \n");
  std::cin >> symbol;

  if (isValidSymbol(symbol)) {
    auto r = getChart(symbol);
    if (r.status_code == 200) {
      fmt::print("GET successful.\n");

      auto j3 = json::parse(r.text);
      const auto date = j3[0]["date"].get<std::string>();
      fmt::print("Date: {}\n",  date);

    } else {
      fmt::print("GET not successful. Status code is {}. \n", r.status_code);
    }
    fmt::print("Done. \n");
  } else {
    fmt::print("Sorry, we did not recognise the ticker symbol {}.\n", symbol);
  }
}
