#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "../../src/API/IEX.h"

class IEX_Mock : public API::IEX {
public:
  MAKE_MOCK2(getParsedJson, json(const std::string &, const bool), override);
};

SCENARIO("JSON objects can be searched for a user-provided company ticker",
         "[API][IEX]") {
  IEX_Mock iex_mock;

  GIVEN("An array containing a single JSON object") {
    json json_mock = json::parse(R"([{"symbol": "CORRECT_TOKEN"}])");
    WHEN("We search for the ticker symbol present in the JSON object") {
      REQUIRE_CALL(iex_mock, getParsedJson("/ref-data/symbols", false))
          .RETURN(json_mock);

      const bool ticker_was_found = iex_mock.isValidSymbol("CORRECT_TOKEN");
      THEN("The ticker symbol should have been found") {
        REQUIRE(ticker_was_found);
      }
    }
  }
  GIVEN("An array containing multiple JSON objects") {
    json json_mock = json::parse(
        R"([{"symbol": "A_TOKEN"}, {"symbol": "CORRECT_TOKEN"}, {"symbol": "A_THIRD_TOKEN"}])");
    WHEN("We search for a ticker symbol present in one of the JSON objects") {
      REQUIRE_CALL(iex_mock, getParsedJson("/ref-data/symbols", false))
          .RETURN(json_mock);

      const bool ticker_was_found = iex_mock.isValidSymbol("CORRECT_TOKEN");
      THEN("The ticker symbol should have been found") {
        REQUIRE(ticker_was_found);
      }
    }
    WHEN("We search for a ticker symbol not present in the JSON objects") {
      REQUIRE_CALL(iex_mock, getParsedJson("/ref-data/symbols", false))
          .RETURN(json_mock);
      const bool ticker_was_found =
          iex_mock.isValidSymbol("AN_INCORRECT_TOKEN");
      THEN("The ticker symbol should not have been found") {
        REQUIRE(!ticker_was_found);
      }
    }
  }
}
