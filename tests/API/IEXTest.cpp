#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "../../src/API/IEX.h"

using trompeloeil::_;

class IEX_Mock : public API::IEX
{
public:
    MAKE_MOCK2(getParsedJson, json(const std::string, const bool));
};

TEST_CASE( "Test IEX isValidSymbol", "[API]") {
  IEX_Mock iex_mock;

  json json_mock1 = json::array({ {"symbol", "CORRECT_TOKEN"} });
  json json_mock2 = json::array({ {"symbol", "A_TOKEN"}, {"symbol", "CORRECT_TOKEN"}, {"symbol", "A_THIRD_TOKEN"} });
  json json_mock3 = json::array({ {"symbol", "A_TOKEN"}, {"symbol", "ANOTHER_TOKEN"}, {"symbol", "A_THIRD_TOKEN"} });

  // Test can find a symbol
  ALLOW_CALL(iex_mock, getParsedJson(_ , _))
    .RETURN(json_mock1);
  REQUIRE(iex_mock.isValidSymbol("CORRECT_TOKEN") == true);

  // test that it loops through the json object until it finds the correct symbol
  /*ALLOW_CALL(iex_mock, parseGetRequest(_))
    .RETURN(json_mock2);
  REQUIRE( iex_mock.isValidSymbol("CORRECT_TOKEN") == true);

  // test that it return false if can't find anywhere
  ALLOW_CALL(iex_mock, parseGetRequest(_))
    .RETURN(json_mock1);
  REQUIRE( iex_mock.isValidSymbol("CORRECT_TOKEN") == false);*/
}
