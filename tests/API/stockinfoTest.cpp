#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "../../src/API/hdr/stockinfo.h"


SCENARIO("StockInfo objects can store useful information on a stock.") {
  GIVEN("A chart containing all relevant stock information") {
    json chart = json::parse(R"({"symbol": "AAPL", "close": 210.0, "date": "2019-01-01"})");
    WHEN("We initialise a StockInfo object with the chart") {
      StockInfo stock("AAPL", chart);
      THEN("StockInfo should extract the symbol and close") {
        REQUIRE(stock.getSymbol() == "AAPL");
        REQUIRE(stock.getClose() == 210.0);
      }
      THEN("StockInfo should create a stock report") {
        const std::string expected = "AAPL closed on 2019-01-01 at 210.00";
        const std::string actual = stock.getStockReport();
        REQUIRE(actual == expected);
      }
    }
    WHEN("We initialise a StockInfo object with information directly") {
      StockInfo stock("AAPL", "2019-01-01", 210.0);
      THEN("StockInfo should extract the symbol and close") {
        REQUIRE(stock.getSymbol() == "AAPL");
        REQUIRE(stock.getClose() == 210.0);
      }
      THEN("StockInfo should create a stock report") {
        const std::string expected = "AAPL closed on 2019-01-01 at 210.00";
        const std::string actual = stock.getStockReport();
        REQUIRE(actual == expected);
      }
    }
  }
}
