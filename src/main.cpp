#include <iostream>
#include <map>
#include <string>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <fmt/format.h>

using json = nlohmann::json;

cpr::Response getChart(const std::string &symbol) {
  std::string url = "https://api.iextrading.com/1.0";
  url += "/stock/"+symbol+"/chart";

  std::cout << "Starting GET req at url " << url << std::endl;
  return cpr::Get(cpr::Url{url},
                  cpr::VerifySsl{false});  // CPR issue #194
}

int main(int argc, char **argv) {
  auto r = getChart("aapl");
  if (r.status_code == 200) {
    std::cout << "GET successful." << "\n";

    auto j3 = json::parse(r.text);
    const auto date = j3[0]["date"].get<std::string>();
    fmt::print("Date: {}",  date);

  } else {
    std::cout << "GET not successful. Status code is " << r.status_code << std::endl;
  }
  std::cout << "Done." << "\n";
}
