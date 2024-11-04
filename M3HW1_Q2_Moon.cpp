/*
CSC 134
M3HW1 - Gold
Madison Moon
10/6/24
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
// Declare variables
double meal_price = 5.99;
double tax_pct = 0.08;
double tax_amnt;
double tip_pct = 0.15;
double tip_amnt;
double total;
string choice;

// Calculate the values
tax_amnt = meal_price * tax_pct;
tip_amnt = meal_price * tip_pct;
total = meal_price + tax_amnt + tip_amnt;

//set all decimals to 2 places
cout << fixed << setprecision(2);

//dine-in or to-go
cout << "Please enter 1 if the order is dine in, 2 if it is to go. ";
cin >> choice;
cout << endl;

// Print the results
if (choice == "1"){
cout << "RECEIPT" << endl;
cout << "---------------------" << endl;
cout << "Thank you for dining with us." << endl;
cout << "Your meal price is \t$" << meal_price << endl;
cout << "The tip is \t\t$" << tip_amnt << endl;
cout << "The tax is \t\t$" << tax_amnt << endl;
cout << "Your total is \t\t$" << total << endl;
cout << "---------------------" << endl;
cout << "Have a nice day :)" << endl;
}
else if (choice == "2"){
tip_amnt = 0;
cout << "RECEIPT" << endl;
cout << "---------------------" << endl;
cout << "Thank you for dining with us." << endl;
cout << "Your meal price is \t$" << meal_price << endl;
cout << "The tax is \t\t$" << tax_amnt << endl;
cout << "Your total is \t\t$" << total << endl;
cout << "---------------------" << endl;
cout << "Have a nice day :)" << endl;
}
else {
    cout << "Please enter a valid input (1 or 2)." << endl;
}

return 0;
}