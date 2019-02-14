#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

int PracticeFunction(const int number) {
  return number <= 5 ? number : 5;
} 

TEST_CASE( "Practice test case", "[practice]" ) {
    REQUIRE( PracticeFunction(1) == 1 );
    REQUIRE( PracticeFunction(2) == 2 );
    REQUIRE( PracticeFunction(5) == 5 );
    REQUIRE( PracticeFunction(111) == 5 );
}
