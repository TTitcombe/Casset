#include <catch2/catch.hpp>
#include <catch2/trompeloeil.hpp>
#include <memory>
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

// Having to mock the low-tech way currently,
// as can't get trompeloeil to work with pointers
class MainWindowMock : public UI::MainWindow {
public:
  explicit MainWindowMock(const std::string &mock_symbol, QWidget *parent = nullptr) :
    m_mock_symbol(mock_symbol), UI::MainWindow(parent) {}
  std::string getSymbol() override {
    return m_mock_symbol;
  };
private:
  std::string m_mock_symbol;
};


class PresenterMock : public UI::Presenter {
public:
    MAKE_MOCK1(updateStockMessage, void(const std::string &), override);
    explicit PresenterMock(std::shared_ptr<UI::MainWindow> v, std::unique_ptr<API::IEXInterface> iex) :
      Presenter(v, iex) {}
};

SCENARIO("The Presenter object can handle user actions and model updates.") {
  GIVEN("A presenter object, which holds a view, and can make API calls") {
    // Start QApplication
    char *argv[] = {"program name", NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;
    QApplication qapp(argc, argv);

    // Create the presenter with mocked view and IEX
    std::shared_ptr<UI::MainWindow> casset_window = std::make_shared<MainWindowMock>("aLongStock");
    std::unique_ptr<API::IEXInterface> iex = std::make_unique<API::IEXMockFalse>();
    PresenterMock presenter(casset_window, std::move(iex));

    WHEN("We click the button to get stock data for a symbol greater than 4 characters long") {
      THEN("We should expect the view message to explain the stock symbol is too long") {
        REQUIRE_CALL(presenter, updateStockMessage("aLongStock is too long for a stock symbol"));
        presenter.onStockButtonClicked();
      }
    }
  }

  GIVEN("A presenter with a mocked view which returns a non-alphanumerical stock") {
    char *argv[] = {"program name", NULL};
    int argc = sizeof(argv) / sizeof(char*) - 1;
    QApplication qapp(argc, argv);

    // Create the presenter with mocked view and IEX
    std::shared_ptr<UI::MainWindow> casset_window = std::make_shared<MainWindowMock>("a!a");
    auto iex = std::make_unique<API::IEXMockFalse>();
    PresenterMock presenter(casset_window, std::move(iex));

    WHEN("We click the button to get stock data for a symbol which contains non alphanumeric characters") {

      THEN("We should expect the view message to explain that non alphanumeric characters were used") {
        REQUIRE_CALL(presenter, updateStockMessage("a!a contains non alphabetical characters"));
        presenter.onStockButtonClicked();
      }
    }
  }
}
