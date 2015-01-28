// Type conversion

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int books, months;
    double readRate;
    int sum = 5;

    cout << "How many books do you plan to read? ";
    cin >> books;

    cout << "how many months will it take you to read? ";
    cin >> months;

    readRate = static_cast<double>(books) / months;
    cout << "That is" << readRate << " books per month.\n";
    cout << (typeid(sum));

}
