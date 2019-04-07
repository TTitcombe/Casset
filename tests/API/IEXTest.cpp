#include <catch2/catch.hpp>
#include <trompeloeil.hpp>

#include "../../src/API/IEX.h"

using json = nlohmann::json;

class IEX_Mock : public API::IEX
{
public:
    MAKE_MOCK2(makeGetRequest, cpr::Response(const std::string, const bool));
    MAKE_MOCK1(parseGetRequest, json(const cpr::Response&));
};

TEST_CASE( "Test IEX parsing functionality", "[API]") {
  IEX_Mock iex_mock;
  REQUIRE( iex_mock.isValidSymbol("AAPL") == true);
}
