#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>

#include "../../src/API/hdr/portfolio.h"

#include <iostream>

SCENARIO("Portfolios can manage a number of stocks.") {
  StockInfo aapl("AAPL", "2019-01-01", 100.);
  StockInfo abcd("ABCD", "2019-10-01", 123.);

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
      portfolio.addStock(100, aapl);

      THEN("The value of the portfolio should go up") {
        REQUIRE(portfolio.getValue() == 100 * 100.);
      }
    }

    WHEN("We add zero shares off a new stock") {

      THEN("An error should be raised") {
        REQUIRE_THROWS_AS(portfolio.addStock(0, aapl), std::invalid_argument);
      }
    }

    WHEN("We add a stock which the portfolio already contains") {
      portfolio.addStock(10, aapl); // add it once
      THEN("An error should be raised") {
        REQUIRE_THROWS_AS(portfolio.addStock(10, aapl), std::invalid_argument);
      }
    }

    WHEN("We remove a stock the portfolio contains") {
      portfolio.addStock(10, abcd);
      portfolio.removeStock("ABCD");

      THEN("The portfolio should no longer contain the stock") {
        REQUIRE(!portfolio.hasStock("ABCD"));
      }

      THEN("The portfolio value should have decreased") {
        REQUIRE(portfolio.getValue() == 0.);
      }
    }

    WHEN("We remove a stock which the portfolio does not contain") {

      THEN("An error should be raised") {
        REQUIRE_THROWS_AS(portfolio.removeStock("ABCD"), std::invalid_argument);
      }
    }
  }

  GIVEN("Two portfolios") {
    Portfolio p1;
    Portfolio p2;

    WHEN("The portfolios have the same value") {
      p1.addStock(10, aapl);
      p2.addStock(10, aapl);

      THEN("They should be equal") {
        REQUIRE(p1 == p2);
      }
    }

    WHEN("The portfolios do not have the same value") {
      p1.addStock(10, aapl);
      p2.addStock(15, aapl);

      THEN("They should not be equal") {
        REQUIRE(!(p1 == p2));
      }
    }
  }
}
