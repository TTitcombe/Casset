#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "../../src/API/hdr/portfolio.h"

#include <iostream>

SCENARIO("Portfolios can manage a number of stocks.") {

  GIVEN("An empty portfolio") {
    Portfolio portfolio;
    REQUIRE(portfolio.getName() == "MyPortfolio");
    REQUIRE(portfolio.getValue() == 0.0);

    WHEN("We change its name") {
      portfolio.rename("MyFirstPortfolio");

      THEN("The portfolio name should have changed") {
        REQUIRE(portfolio.getName() == "MyFirstPortfolio");
      }
    }

    WHEN("We add a new stock") {
      StockInfo newStock("AAPL", "2019-01-01", 100.);
      portfolio.addStock(100, newStock);

      THEN("The value of the portfolio should go up") {
        REQUIRE(portfolio.getValue() == 100 * 100.);
      }
    }

    WHEN("We add a stock which the portfolio already contains") {
      StockInfo stock("AAPL", "2019-01-01", 100.);
      //portfolio.addStock(10, stock); // add it once
      THEN("An error should be raised") {
        REQUIRE_THROWS_AS(portfolio.addStock(10, stock), std::invalid_argument);
      }
    }

  }
}
