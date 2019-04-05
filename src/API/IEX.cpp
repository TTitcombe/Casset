#include "IEX.h"

#include <fmt/format.h>

namespace API {

cpr::Response IEX::makeGetRequest(const std::string endpoint, const bool verifySSL) {
  const std::string full_url = m_url + endpoint;
  fmt::print("Starting GET req at url {}. \n", full_url);
  const auto response = cpr::Get(cpr::Url{full_url}, cpr::VerifySsl{verifySSL});
  if (response.status_code == 200) {
    fmt::print("GET successful.\n");
  } else if (response.status_code == 404) {
    fmt::print("Could not find url {}.\n", full_url);
  } else {
    fmt::print("Error code {} at GET request.\n", response.status_code);
  }
  return response;
}

json IEX::parseGetRequest(const cpr::Response &response) {
  const auto j3 = json::parse(response.text);
  return j3;
}

bool IEX::isValidSymbol(const std::string symbol) {
  const auto response = makeGetRequest("/ref-data/symbols", false);
  if (response.status_code == 200) {
    const auto j = parseGetRequest(response);
    for (const auto &j2 : j) {
      const auto sym = j2["symbol"].get<std::string>();
      if (sym == symbol) {
        fmt::print("Found {}\n", symbol);
        return true;
      }
    }
  }
  fmt::print("Cannot find symbol {}.\n", symbol);
  return false;
}

std::string IEX::getChart(const std::string symbol) {
  std::string date;
  if (isValidSymbol(symbol)) {
    const auto response = makeGetRequest("/stock/" + symbol + "/chart", false);
    if (response.status_code == 200) {
      const auto j3 = parseGetRequest(response);
      date = j3[0]["date"].get<std::string>();
    }
  }
  return date;
}
} // API