#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "../../src/API/IEX.h"

class IEX_Mock : public API::IEX
{
public:
    MAKE_MOCK2(getParsedJson, json(const std::string, const bool), override);
};

TEST_CASE( "Test IEX isValidSymbol", "[API]") {
  IEX_Mock iex_mock;
  {
    json json_mock1 = json::parse("[{\"symbol\": \"CORRECT_TOKEN\"}]");

    // Test can find a symbol
    REQUIRE_CALL(iex_mock, getParsedJson("/ref-data/symbols", false))
      .RETURN(json_mock1);

    const bool return_val = iex_mock.isValidSymbol("CORRECT_TOKEN");
    REQUIRE(return_val == true);
  }
  {
    json json_mock2 = json::parse("[{\"symbol\": \"A_TOKEN\"}, {\"symbol\": \"CORRECT_TOKEN\"}, {\"symbol\": \"A_THIRD_TOKEN\"}]");

   // Test can loops through the json object until the correct symbol is found
    REQUIRE_CALL(iex_mock, getParsedJson("/ref-data/symbols", false))
      .RETURN(json_mock2);

    const bool return_val = iex_mock.isValidSymbol("CORRECT_TOKEN");
    REQUIRE(return_val == true);
  }
  {
   json json_mock3 = json::parse("[{\"symbol\": \"A_TOKEN\"}, {\"symbol\": \"ANOTHER_TOKEN\"}, {\"symbol\": \"A_THIRD_TOKEN\"}]");

    // Test will return false if symbol is not found in json object
    REQUIRE_CALL(iex_mock, getParsedJson("/ref-data/symbols", false))
      .RETURN(json_mock3);

    const bool return_val = iex_mock.isValidSymbol("CORRECT_TOKEN");
    REQUIRE(return_val == false);
  }
}
