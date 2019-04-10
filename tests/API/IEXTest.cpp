#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "../../src/API/IEX.h"

using trompeloeil::_;

class IEX_Mock : public API::IEX
{
public:
    MAKE_MOCK2(getParsedJson, json(const std::string, const bool));i
};

TEST_CASE( "Test IEX isValidSymbol", "[API]") {
  IEX_Mock iex_mock;
  {
    json json_mock1 = json::array({{"symbol", "CORRECT_TOKEN"}});
    //json json_mock2 = json::array({ {"symbol", "A_TOKEN"}, {"symbol", "CORRECT_TOKEN"}, {"symbol", "A_THIRD_TOKEN"} });
    //json json_mock3 = json::array({ {"symbol", "A_TOKEN"}, {"symbol", "ANOTHER_TOKEN"}, {"symbol", "A_THIRD_TOKEN"} });

    // Test can find a symbol
    REQUIRE_CALL(iex_mock, getParsedJson("/ref-data/symbols", false))
      .RETURN(json_mock1);

    const bool return_val = iex_mock.isValidSymbol("CORRECT_TOKEN");
    REQUIRE(return_val == true);
  }
}
