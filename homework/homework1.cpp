// HW
// In ancient India, a simple algorithm was used to compute the length of the hypotenuse of a right triangle. Let  h be the hypotenuse and let a and b be the two other sides of the triangle. Select the shorter side to be a, and let the longer side be b. Then the length of the hypotenuse is calculated as h = a + b/2.  For example, let the two sides of a right triangle be 3 and 4. Then a =3, and b = 4.  And h = a + b/2 = 3 + 4/2 = 3 + 2 = 5.
// Following all guidelines discussed in class, write a program to calculate the hypotenuse by using the above approximation method. Test your program for 5 different right triangles. For each triangle, also calculate the hypotenuse using the Pythagoras formula and compute the difference between the two results for each triangle.  Note that the user can enter the sides in any order. Your program must decide which is the longer side.
// Sample message and user input:
// Enter the two sides of a right triangle separated by a space:  3 4
// Sample output:
// Shorter side	Longer side 	Hypotenuse	Pythagoras method	Difference
// 3		4		5		5			0
// 1		1		1.500		1.414			0.086
//
// Submissions:
// Your source (.cpp) file
// Word File containing a screen shot of your output. To get a screen capture, use Alt+Prt Screen. Paste inside the Word file.
// DUE:  2/17/2015. NO LATER THAN 5.00 pm
//
//
// h = a + b/2

#define CATCH_CONFIG_MAIN


#include "../utils/catch.hpp"

#include <iostream>
#include <iomanip>


double a,b,hypotenuse,
      longer,shorter,
      approximation,pythagoran,
      difference;
bool sidesAreEqual;

 double determineOrder(double a, double b) {
    if (a > b) {
      longer = a;
    } else if (a < b) {
      longer = b;
    } else if (a == b) {
      sidesAreEqual = true;
      return sidesAreEqual;
    }
    return longer;
  }

  double approximateHypotenus(double a, double b){
    return hypotenuse = a + (b / 2);
  }

SCENARIO("Calculating the hypotenuse"){
  GIVEN("two lengths of two sides of a right triangle; a < b ") {
    // double a, b, h;
    WHEN("two sides are given"){
      THEN("it should decided which is larger and report that"){
        REQUIRE( determineOrder(2,1) == 2.0);
        REQUIRE( determineOrder(2,3) == 3.0);
        REQUIRE( determineOrder(2,2) == true);
        REQUIRE( determineOrder(2.1,-2) == 2.1);
        REQUIRE( determineOrder(-2.1,-2.0) == -2.0);

      }
    }

    WHEN("we try to approximate the hypotenuse"){
      THEN("it should return the approximated hypotenuse") {
        REQUIRE( approximateHypotenus(1.0,1.0) == 1.5);
        REQUIRE( approximateHypotenus(2.0,10.0) == 7);
        REQUIRE( approximateHypotenus(1.0,12.2) == 7.1);
        REQUIRE( approximateHypotenus(1.0,100.0) == 51);

      }
    }

    // WHEN("two sides are given"){
    //   THEN("the hypotenuse should be approximated"){
    //
    //   }
    // }
    //
    // WHEN("two sides are given"){
    //   THEN("the hypotenuse should be calculated using the Pythagoran theorem"){
    //
    //   }
    // }
    //
    // WHEN("both approximation and pyth. calculation have been done"){
    //   THEN("find the difference between the two methods"){
    //
    //   }
    // }
    //
    // WHEN("All the business logic has done its work"){
    //   THEN("we need to log everything out to the console"){
    //
    //   }
    // }
  }
}
