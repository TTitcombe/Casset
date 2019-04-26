#include "API/IEX.h"
#include <CLI/CLI.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QPushButton hello("Hello world!");
    hello.resize(100, 30);

    hello.show();
    return app.exec();
    /*
    std::string symbol = "AAPL";
    std::string spdlog_level = "info";

    auto Logger = spdlog::stderr_color_mt("MAIN_LOG");

    CLI::App App{"Casset"};
    App.add_option("-s, --symbol", symbol,
                   "A stock ticker symbol");
    App.add_option("-l, --loglevel", spdlog_level,
                   "A string describing the log level: debug, info, warn, "
                   "critical");
    CLI11_PARSE(App, argc, argv);

    if (spdlog_level == "debug") {
        spdlog::set_level(spdlog::level::debug);
    } else if (spdlog_level == "info") {
        spdlog::set_level(spdlog::level::info);
    } else if (spdlog_level == "warn") {
        spdlog::set_level(spdlog::level::warn);
    } else if (spdlog_level == "critical") {
        spdlog::set_level(spdlog::level::critical);
    }

    API::IEX iex;
    const json chart = iex.getChart(symbol);
    Logger->info("Chart is {}", chart.dump());*/
}
