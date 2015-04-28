//============================Student Information=====================
// Student Name: Mark Thomas
//
// Date: 4/7/2015
//
// Program Purpose: This program takes user input and compares that input to an array of correct input; it non-destructively normalizes the input to allow for comparison to the correct master array
//====================================================================

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Declare prototype for use later
void checkAnswers(char[], char[], int, int);

// Main function
int main() {
        // Establish the number of right questsions
        const int numQuestions = 20;

        // Minimum number of answers needed to pass the exam
        const int minCorrect = 15;

        // Correct Answers
        char answers[numQuestions] = {
                'B', 'D', 'A', 'A', 'C',
                'A', 'B', 'A', 'C', 'D',
                'B', 'C', 'D', 'A', 'D',
                'C', 'C', 'B', 'D', 'A'
        };

        // Student Answers
        char studentAnswers[numQuestions];

        // Display a cool(ish) DMV logo
        cout << setw(28) << " ______     ____    ____   ____   ____\n";
        cout << setw(30) << "|_   _ `.  |_   \\  /   _| |_  _| |_  _|\n";
        cout << setw(30) <<"  | |  \\ \\   |   \\/   |     \\ \\   / /\n";
        cout << setw(30) <<"  | |  | |   |  _||_  |      \\ \\ / /  \n";
        cout << setw(30) << " _| |_.' /  _| |_  _| |_      \\ ' /\n";
        cout << setw(30) << "|______.'  |_____||_____|      \\_/\n\n";
        cout << setw(30) << "Department of Motor Vehicles\n\n";

        cout << "Welcome to the California DMV Driving Exam.\nCongratulations, after waiting for 15 hours, you can at long last take your exam!\n \nRemember: You must have at least 15 correct to pass.\n\nEnter your answers in the following prompts:\n";

        // Loop through until the number of questions has been exhausted
        for (int replies = 0; replies < numQuestions; replies++) {
                cout<< " "
                    << (replies + 1) << ": ";
                cin >> studentAnswers[replies];

                // Validate users' answers and make sure that only upper- or lower-cased a-d are being used
                while ((studentAnswers[replies] != 'A' && studentAnswers[replies] !='a') && (studentAnswers[replies] != 'B' && studentAnswers[replies] != 'b') && (studentAnswers[replies] != 'C' && studentAnswers[replies] != 'c') && (studentAnswers[replies] != 'D' && studentAnswers[replies] != 'd')) {
                        cout << "You must enter A, B, C, or D\n";
                        // Display the number of question
                        cout<< " " << (replies + 1) << ": ";
                        // Accept question
                        cin >> studentAnswers[replies];
                }
        }
        // run our check answers question on the submitted answers
        checkAnswers(answers, studentAnswers, numQuestions, minCorrect);
        // return 0 when done
        return 0;
}

// Check answers function
void checkAnswers(char answers[], char studentAnswers[], int numQuestions, int minCorrect) {
        // initialize the number of correct answers to be 0
        int correctAnswers = 0;

        // Check replies to see if they're correct
        for (int i = 0; i < numQuestions; i++) {
                // // Normalize the answers so we can compare to the correct ones regardless of whether or not a upper/lower char was submitted
                if (answers[i] == toupper(studentAnswers[i])) {
                        correctAnswers++;
                }
        }

        // Check to see if student passed based on number of correct answers
        correctAnswers >= minCorrect ? cout << "\n You passed the exam! Congratulations!\n\n" : cout <<"\nYou failed the exam :( Please try again once you have waited in line for another 15 hours.  \n\n";

        // Display incorrect answers
        cout << "Incorrect answers:\n";
        for (int i = 0; i < numQuestions; i++) {
                // Ensure that we compare normalized versions of the students answers
                if (answers[i] != toupper(studentAnswers[i])) {
                        cout << "Question # " << i + 1 << " is incorrect." << endl;
                }
        }

        // Display correct and incorrect answer totals
        cout << "\nCorrect Answers: " << correctAnswers << endl;
        cout << "Incorrect Answers: " << numQuestions - correctAnswers << endl;
}
