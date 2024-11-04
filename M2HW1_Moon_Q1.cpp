/*
CSC 134
M2HW1 - Gold
Madison Moon
9/12/24
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
//Set up our variables
    string name;
    double acct_balance;
    double deposit;
    double withdrawal;
    double fin_balance;
    int acct_num = 12345678;

// Get user input
    cout << "What is your name? ";
    getline (cin, name);
    cout << "What is your current account balance? ";
    cin >> acct_balance;
    cout << "How much are you depositing today? ";
    cin >> deposit;
    cout << "How much are you withdrawing? ";
    cin >> withdrawal;

// Calculations
    fin_balance = acct_balance + (deposit - withdrawal);

//set all decimals to 2 places
    cout << fixed << setprecision(2);

// Output
    cout << "----------------------------"<< endl;
    cout << "Account Name: " << name << endl;
    cout << "Account Number: " << acct_num << endl;
    cout << "Final Account Balance: " << fin_balance << endl;

}