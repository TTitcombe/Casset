#ifndef API_IEX_H_
#define API_IEX_H_

#include <string>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace API {

class IEX {
public:
  std::string getChart(const std::string symbol);

private:
  cpr::Response makeGetRequest(const std::string endpoint, const bool verifySSL);
  json parseGetRequest(const cpr::Response &response);
  bool isValidSymbol(const std::string symbol);
  const std::string m_url = "https://api.iextrading.com/1.0";
};
} // API
#endif // API_IEX_H_