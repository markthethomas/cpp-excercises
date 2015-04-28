//============================Student Information=====================
// Student Name: Mark Thomas
//
// Date: 3/2/2015
//
// Program Purpose: This program takes a whole number of days and calculates how much a person would earn over a period of time if his/her salary is one penny the first day and two pennies the second, and doubles every day. We print out the day number, the amount earned so far, and the total.
//====================================================================

// Include the necessary headers
#include <iostream>
#include <iomanip>

// Get the number of days from the user
using namespace std;

// Variables we will use throughout our program
int days;
double amount;
double currentAmount;

int main() {
  // Prompt the user for a positive whole number
  cout << fixed << showpoint << setprecision(2) << "Please enter a positive number of days worked: ";
  cin >> days;

  if (days < 1){
    cout << "You need to enter in a positive whole number of days" << endl;
    return 0;
  }

  // Initialize amount to be 1 cent
  amount = 0.01;
  // Display the titles for the table
  cout << setw(9) << "Day" << setw(12) << "Earned" << setw(12) << "Total" << endl;
  // loop through the range and print out the day, amount earned, and total
  for (int count = 0; count < days; count++) {
    currentAmount = amount;
    amount = amount * 2;
    cout << setw(8) << count + 1 << setw(8) << "$" << currentAmount << setw(8) << '$' << amount - 0.01 << endl;
  }
}
