//
// Copyright (c) 2015 by Mark Thomas. All Rights Reserved.
//
#define CATCH_CONFIG_MAIN


#include "../catch/catch.hpp"

#include <iostream>
#include <iomanip>

// Actual Code
unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

// Create test cases
SCENARIO( "Factorials are computed", "[factorial]" ) {
  WHEN("Making sure everything works"){
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 1 );
    REQUIRE( Factorial(10) == 3628800 );
  }
}



bool isEvenOrOdd(unsigned int testNumber) {
  if (testNumber % 2 == 0) {
    return true;
  } else {
    return false;
  }
}


TEST_CASE("Check if a given number is even or odd"){
  REQUIRE( isEvenOrOdd(2) == true);
  REQUIRE( isEvenOrOdd(3) == false);
  REQUIRE( isEvenOrOdd(100) == true);
  REQUIRE( isEvenOrOdd(4) == true);
  REQUIRE( isEvenOrOdd(5) == false);
}
