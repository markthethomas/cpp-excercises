//============================Student Information=====================
// Student Name: Mark Thomas
//
// Date: 2/17/2015
//
// Program Purpose: this program takes two numbers given by the user and calculates both a pythagoran hypotenus, an approximated hypotenus, and the difference between the two.
//====================================================================

// Include the necessary headers
#include <cmath>
#include <iostream>
#include <iomanip>

// We are using the standard namespace
using namespace std;

// Variables we will use throughout our program
double a,b,hypotenuse,
      longer,shorter,
      approximation,pythagoran,
      difference;

// Declare a helper variable
bool sidesAreEqual;


// Before declaring our main function, set up helper functions to perform needed operations on user data

 // Determine the order of the user's input and set the sides to be either shorter/longer, depending on value
 double determineOrder(double a, double b) {
    if (a > b) {
      longer = a;
      shorter = b;
    } else if (a < b) {
      longer = b;
      shorter = a;
    } else if (a == b) {
      a = a;
      b = b;
      sidesAreEqual = true;
    }
    return 0;
  }

  // Approximate the hypotenuse
  double approximateHypotenus(double shorter, double longer){
    return shorter + (longer / 2);
  }

  // Calculate the actual hypotenuse using pyth. theorem
  double calculateHypotenuseWithPyth(double a, double b) {
    return sqrt(pow(a,2) + pow(b,2));
  }

  // Return the difference btween the pythagoran theorem and the approximation
  double returnDifference() {
    return abs(pythagoran - approximation);
  }


int main() {
  // Prompt the user for two sides of a right triangle
  cout << fixed << showpoint << setprecision(3) << "Enter two sides of a triangle; press return after entering the first side" << endl;
  cout << "Enter the first side: ";
  cin >> a;
  cout << "Enter the second side: ";
  cin >> b;

  // Return feedback to the user about what sides they entered
  cout << "You entered sides " << a << " and " << b << endl;

  // Perform ordering and evaluation functions on user input
  determineOrder(a, b);
  approximation = approximateHypotenus(a, b);
  pythagoran = calculateHypotenuseWithPyth(a, b);
  difference = abs(pythagoran - approximation);

  // Report back to the user data about their input(s); use logical switch based on whether the sides are equal
  if (sidesAreEqual == true){
    cout << "First side |	Second side | Hypotenuse | Pythagoras method | Difference" << endl;
    cout << setw(10) << a << setw(15) << b << setw(15) << approximation << setw(20) << pythagoran << setw(10) << difference << endl;
  } else {
    cout << "Shorter side |	Longer side | Hypotenuse | Pythagoras method | Difference" << endl;
    cout << setw(10) << shorter << setw(15) << longer << setw(15) << approximation << setw(20) << pythagoran << setw(10) << difference << endl;
  }
  return 0;

}
