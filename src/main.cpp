#include <iostream>
#include <map>
#include <string>
#include <cpr/cpr.h>

int main(int argc, char **argv) {
  std::cout << "Please enter your IEX token: " << std::endl;
  std::string token;
  std::cin >> token;

  std::cout << "Starting GET req" << std::endl;

  const std::string url = "https://cloud.iexapis.com/beta/tops";
  auto params = cpr::Parameters{{"token", token},
                                {"symbols", "aapl"}};
  auto r = cpr::Get(cpr::Url{url}, params);

  std::cout << "Status code: " << r.status_code << std::endl;
  std::cout << "Done." << std::endl;
}
