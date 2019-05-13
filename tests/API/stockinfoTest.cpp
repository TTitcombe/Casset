#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "../../src/API/hdr/stockinfo.h"


SCENARIO("StockInfo objects can store useful information on a stock.") {
  GIVEN("A chart containing all relevant stock information") {
    json chart = json::parse(R"({"close": 210.0, "date": "2019-01-01"})");

    WHEN("We initialise a StockInfo object with the chart") {
      StockInfo stock("AAPL", chart);

      THEN("StockInfo should extract the symbol and close") {
        REQUIRE(stock.getSymbol() == "AAPL");
        REQUIRE(stock.getClose() == 210.0);
      }

      THEN("StockInfo should create a stock report") {
        const std::string expected = "AAPL closed on 2019-01-01 at $210.00";
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
        const std::string expected = "AAPL closed on 2019-01-01 at $210.00";
        const std::string actual = stock.getStockReport();
        REQUIRE(actual == expected);
      }
    }
  }

  GIVEN("Two different types of stock") {
    json chart1 = json::parse(R"({"close": 210.0, "date": "2019-01-01"})");
    json chart2 = json::parse(R"({"close": 100.0, "date": "2019-01-01"})");

    WHEN("Two StockInfo objects are created from the same data but have a different symbol") {
      const StockInfo stock1("AAPL", chart1);
      const StockInfo stock2("ABCD", chart1);

      THEN("The stocks should not be equal") {
        REQUIRE(!(stock1 == stock2));
      }
    }

    WHEN("Two StockInfo objects have the same symbol but different data") {
      const StockInfo stock1("AAPL", chart1);
      const StockInfo stock2("AAPL", chart2);

      THEN("The stocks should not be equal") {
        REQUIRE(!(stock1 == stock2));
      }
    }

    WHEN("Two StockInfo objects have the same symbol and data") {
      const StockInfo stock1("AAPL", chart1);
      const StockInfo stock2("AAPL", chart1);

      THEN("The stocks should be equal") {
        REQUIRE(stock1 == stock2);
      }
    }
  }
}
