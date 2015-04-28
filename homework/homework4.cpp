//============================Student Information=====================
// Student Name: Mark Thomas
//
// Date: 4/28/2015
//
// Program Purpose: This program takes in a number of students surveyed, creates an arry based on that number, then allows the user to input survey data for each student in the array. The total, median, and average are returned based on that data. 
//====================================================================

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
        int *studentResponses; // used to dynamically allocate an array
        int studentsSurveyed; // number of student surveyed
        double total;
        double average;
        double median;

        // Initialize total to 0
        total = 0;

        // Get the total number of students
        cout << "How many students were surveyed about their moviegoing habits?" << endl;
        cout << "Number of students: ";
        cin >> studentsSurveyed;

        // Dynamically allocate an array large enough to hold the number of students surveyed
        studentResponses = new int[studentsSurveyed];

        // Get the number of movies watched by each student
        cout << "Enter the number of movies each college student watched. Negative numbers will be converted to their positive counterpart." << endl;

        for (int count = 0; count < studentsSurveyed; count++)
        {
                cout << "Student #"<< count + 1 << " : ";
                cin >> studentResponses[count];
        }

        // Total the number of movies seen by all students
        for (size_t i = 0; i < studentsSurveyed; i++) {
                total += abs(studentResponses[i]);
        }

        // Sort responses
        sort(studentResponses, studentResponses + studentsSurveyed);

        // Calculate median
        if (studentsSurveyed % 2 != 0) {
                median = studentResponses[((studentsSurveyed - 1 ) / 2)];
        } else {
                // Check to see if the two most-middle are the same
                if (studentResponses[(studentsSurveyed / 2 )] == studentResponses[(studentsSurveyed / 2 ) - 1]) {
                        median = studentResponses[(studentsSurveyed / 2 )];
                } else {
                        median = (studentResponses[(studentsSurveyed / 2 )] + (double)studentResponses[(studentsSurveyed / 2 ) - 1]) / 2;
                }
        }

        // Calculate the average number of movies watched
        average = total / studentsSurveyed;

        // Show the total and averaged of movies watched
        cout << "###### RESULTS ######" << endl;
        cout << setprecision(3) << "The total number of movies watched by all students is: " << total << " movies." <<endl;
        cout << "The average number of movies watched per student is: " << average << " movies." << endl;
        cout << "The median number of movies watched is: " << median << " movies." << endl;

        // Free up the dynamically allocated memory
        delete[] studentResponses;
        return 0;
}
