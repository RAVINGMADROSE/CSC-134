// CSC 134
// M2T1 - Receipt Calculator
// Madison Moon
// 8/28/24

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
// Declare variables
double meal_price = 5.99;
double tax_pct = 0.08;
double tax_amnt;
double total;

// Calculate the values
tax_amnt = meal_price * tax_pct;
total = meal_price + tax_amnt;

//set all decimals to 2 places
cout << fixed << setprecision(2);

// Print the results
cout << "RECEIPT" << endl;
cout << "---------------------" << endl;
cout << "Thank you for dining with us." << endl;
cout << "Your meal price is \t$" << meal_price << endl;
cout << "The tax is \t\t$" << tax_amnt << endl;
cout << "Your total is \t\t$" << total << endl;
cout << "---------------------" << endl;
cout << "Have a nice day :)" << endl;

}