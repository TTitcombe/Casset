#include <catch2/catch.hpp>

#include "../../src/API/IEX.h"

using json = nlohmann::json;

class IEX_MOCK : API::IEX {
public:
cpr::Response makeGetRequest(const std::string endpoint, const bool verifySSL) {
  (void)endpoint;
  (void)verifySSL;
  cpr::Response return_object;
  return return_object;
}

json parseGetRequest(const cpr::Response &response) {
  (void)response;
  json mock_symbols = json::array({ {"AAPL", "APPL_value"}, {"GOOG", "GOOG_VALUE"},
                                    {"TTT", "TTT_value"}, {"ZZZ", "ZZZ_value"}});
  return mock_symbols;
}
};

TEST_CASE( "Test IEX parsing functionality", "[API]") {
  IEX_MOCK iex_mock;
  REQUIRE( iex_mock.isValidSymbol("AAPL") == true );
}
