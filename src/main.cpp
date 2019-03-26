#include <iostream>
#include <map>
#include <string>
#include <cpr/cpr.h>

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
    std::cout << "GET successful." << std::endl;
    std::cout << "Text " << r.text << std::endl;
  } else {
    std::cout << "GET not successful. Status code is " << r.status_code << std::endl;
  }
  std::cout << "Done." << std::endl;
}
