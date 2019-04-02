#include "IEX.h"

#include <fmt/format.h>

namespace API {

cpr::Response IEX::makeGetRequest(const std::string &endpoint, const bool verifySSL) const {
  const std::string full_url = m_url + endpoint;
  fmt::print("Starting GET req at url {}. \n", url);
  const auto response cpr::Get(cpr::Url{url}, cpr::VerifySsl{verifySSL});
  switch (response.status_code) {
    case 200:
      fmt::print("GET successful.\n");
      break;
    case 404:
      fmt::print("Could not find url {}.\n", full_url);
      break;
    default:
      fmt::print("Error code {} at GET request.\n", response.status_code);
  }
  return response;
}

json IEX::parseGetRequest(const cpr::Response &response) const {
  const auto j3 = json::parse(response.text);
  return j3;
}

bool isValidSymbol(const std::string &symbol) const {
  const std::string endpoint = "/ref-data/symbols";
  const auto response = makeGetRequest(endpoint);

  if (response.status_code == 200) {
    const auto json_objects = parseGetRequest(response);

    for (const auto &symbol_data : json_objects)
      if (symbol_data["symbol"].get<std::string>() == symbol)
        return true;
    fmt::print("Tickers must be in uppercase.\n");
  }
  return false;
}

std::string getChart(const std::string &symbol) const {
  if (isValidSymbol(symbol)) {
    const std::string endpoint = "/stock/"+symbol+"/chart";
    const auto response = makeGetRequest(endpoint);
    const auto json_object = parseGetRequest(response);
    return json_object[0]["date"].get<std::string>();
  } else {
    return "";
  }

};

} // namespace API
