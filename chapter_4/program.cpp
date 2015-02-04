//
// Copyright (c) 2015 by Mark Thomas. All Rights Reserved.
//
#define CATCH_CONFIG_MAIN


#include "../catch/catch.hpp"

#include <iostream>
#include <iomanip>


unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

// Create test cases

TEST_CASE( "Factorials are computed", "[factorial]" ) {
  SECTION("Making sure everything works"){
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
  }
}
