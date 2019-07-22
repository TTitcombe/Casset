#include "../hdr/IEX.h"

namespace API {

IEX::IEX() {
    try {
        m_logger = spdlog::stderr_color_mt("IEX_LOG");
    } catch (spdlog::spdlog_ex &) {
        m_logger = spdlog::get("IEX_LOG");
    }
}

cpr::Response IEX::makeGetRequest(const std::string &endpoint,
                                  const bool verifySSL) {
  const std::string full_url = m_url + endpoint;
  m_logger->debug("Starting GET req at url {}. \n", full_url);
  const auto response = cpr::Get(cpr::Url{full_url}, cpr::VerifySsl{verifySSL});
  if (response.status_code == 200) {
    m_logger->debug("GET successful.\n");
  } else if (response.status_code == 404) {
    m_logger->debug("Could not find url {}.\n", full_url);
  } else {
    m_logger->debug("Error code {} at GET request.\n", response.status_code);
  }
  return response;
}

json IEX::parseGetRequest(const cpr::Response &response) {
  const auto j3 = json::parse(response.text);
  return j3;
}

json IEX::getParsedJson(const std::string &endpoint, const bool verifySSL) {
  json parsed_json;
  const auto response = makeGetRequest(endpoint, verifySSL);
  if (response.status_code == 200) {
    parsed_json = parseGetRequest(response);
  }
  return parsed_json;
}

bool IEX::isValidSymbol(const std::string &symbol) {
  const auto j = getParsedJson("/ref-data/symbols");
  for (const auto &j2 : j) {
    const auto sym = j2["symbol"].get<std::string>();
    if (sym == symbol) {
      return true;
    }
  }
  m_logger->info("Cannot find symbol {}.\n", symbol);
  return false;
}

json IEX::getChart(const std::string &symbol) {
  json chart;
  const auto j = getParsedJson("/stock/" + symbol + "/chart");
  chart = j[j.size() - 1];
  return chart;
}
} // namespace API