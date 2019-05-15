#ifndef API_IEX_H_
#define API_IEX_H_

#include <string>

#include <cpr/cpr.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace API {

class IEXInterface {
public:
    virtual json getChart(const std::string &symbol) = 0;
    virtual bool isValidSymbol(const std::string &symbol) = 0;
};

class IEX : public IEXInterface {
public:
  IEX();
  json getChart(const std::string &symbol);
  virtual json getParsedJson(const std::string &endpoint,
                             const bool verifySSL = false);
  bool isValidSymbol(const std::string &symbol);

private:
  cpr::Response makeGetRequest(const std::string &endpoint,
                               const bool verifySSL);
  json parseGetRequest(const cpr::Response &response);
  const std::string m_url = "https://api.iextrading.com/1.0";
  std::shared_ptr<spdlog::logger> m_logger;
};
} // namespace API
#endif // API_IEX_H_