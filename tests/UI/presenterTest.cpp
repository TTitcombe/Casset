#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>
#include <QApplication>

#include "../../src/UI/hdr/presenter.h"
#include "../../src/UI/hdr/mainwindow.h"

namespace API {
class IEXMockFalse : public IEXInterface {
public:
    json getChart(const std::string &symbol) override {
      json j;
      return j;
    };

    bool isValidSymbol(const std::string &symbol) override {
      return false;
    };
};

class IEXMockTrue : public IEXInterface {
public:
    json getChart(const std::string &symbol) override {
      json j = {{"open",  10.0},
                {"close", 50.0},
                {"low",   5.0},
                {"high",  55.0},
                {"date",  "2019-01-01"}};
      return j;
    }

    bool isValidSymbol(const std::string &symbol) override {
      return true;
    }
};

} // namespace API

class MainWindowMock : public UI::MainWindow {
public:
    MAKE_MOCK0(getSymbol, std::string(), override);
    MAKE_MOCK1(updateStockMessage, void(const std::string &), override);
};

SCENARIO("The Presenter object can handle user actions and model updates.") {
  GIVEN("A presenter object, which holds a view, and can make API calls") {
    char *argv[] = {"program name", NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;
    QApplication app(argc, argv);
    UI::MainWindow *casset_window = new MainWindowMock();
    std::unique_ptr<API::IEXInterface> iex = std::make_unique<API::IEXMockFalse>();
    UI::Presenter presenter(casset_window, iex);
    WHEN("The click the button to get stock data for a symbol greater than 4 characters long") {
      REQUIRE_CALL(*casset_window, getSymbol())
        .RETURN("aLongStock");
      THEN("We should expect the view message to explain the stock symbol is too long") {
        REQUIRE_CALL(*casset_window, updateStockMessage("aLongStock is too long for a stock symbol"));
      }
    }
    delete casset_window;
  }
}