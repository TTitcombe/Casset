#include <map>
#include <string>
#include <iostream>
#include <cpr/cpr.h>

int main(int argc, char **argv) {
  std::cout << "Starting GET req" << std::endl;

  const std::string url = "https://cloud.iexapis.com/beta/tops";

  auto parameters = cpr::Parameters{{"token",""},
				    {"symbols","aapl"}};
  auto r = cpr::Get(cpr::Url{url}, parameters);

  std::cout << "Status code: " << r.status_code;
  std::cout << "Done.";
}
