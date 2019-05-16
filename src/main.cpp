#include <CLI/CLI.hpp>
#include <QApplication>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <memory>

#include "API/hdr/IEX.h"
#include "UI/hdr/mainwindow.h"
#include "UI/hdr/presenter.h"

void setLogLevel(const std::string &level) {
    if (level == "debug") {
        spdlog::set_level(spdlog::level::debug);
    } else if (level == "info") {
        spdlog::set_level(spdlog::level::info);
    } else if (level == "warn") {
        spdlog::set_level(spdlog::level::warn);
    } else if (level == "critical") {
        spdlog::set_level(spdlog::level::critical);
    }
}

int main(int argc, char **argv) {
    auto Logger = spdlog::stderr_color_mt("MAIN_LOG");

    // Set default CLI arguments
    std::string spdlog_level = "info";
    std::string symbol = "AAPL";

    // Set-up CLI
    CLI::App App{"Casset"};
    App.add_option("-s, --symbol", symbol,
                   "A stock ticker symbol");
    App.add_option("-l, --loglevel", spdlog_level,
                   "A string describing the log level: debug, info, warn, "
                   "critical");
    CLI11_PARSE(App, argc, argv);

    // Set the log level
    setLogLevel(spdlog_level);

    QApplication app(argc, argv);
    Logger->debug("QApplication created");

    auto casset_window = std::make_shared<UI::MainWindow>();
    UI::Presenter presenter(casset_window);
    Logger->debug("Casset main window created");
    casset_window->show();
    return app.exec();
}
