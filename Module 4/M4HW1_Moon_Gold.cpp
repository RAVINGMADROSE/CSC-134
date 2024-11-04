/*
CSC 134
M4HW1 - Gold
Madison Moon
10/20/24
*/

#include <iostream>
using namespace std;

int main() {
    // declare variables
    int firstNum, answer;
    //firstNum = 5;
    cout << "Enter a number from 1 to 12?" << endl;
    cin >> firstNum;
    
    while (firstNum <= 0 || firstNum > 12) {
        cout << "***Invalid Entry***" << endl;
        cout << "Please enter a number from 1 to 12." << endl;
        cin.clear();  // Clear the error flag if input was non-integer
        cin.ignore(1000, '\n');  // Ignore the rest of the invalid input
        cin >> firstNum;
    }

    for (int i = 1; i <= 12; i++) {
        answer = firstNum * i;
        cout << firstNum << " times " << i << " is " << answer << endl;
    }
    return 0;
}