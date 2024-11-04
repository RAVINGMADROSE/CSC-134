/*
CSC 134
M2HW1 - Gold
Madison Moon
9/12/24
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

// set up our variables
    int slices_allow = 3;
    int num_pizzas;
    int slices_per;
    int guests;

// get user input
    cout << "How many pizzas are you ordering? ";
    cin >> num_pizzas;
    cout << "How many slices are there per pizza? ";
    cin >> slices_per;
    cout << "How many guests are you expecting? ";
    cin >> guests;

// calculations
    int total_slices = num_pizzas * slices_per;
    int slices_eaten = guests * slices_allow;

// if the guests eat more slices than available, they only eat the available slices

    if (slices_eaten > total_slices) {
    slices_eaten = total_slices;
}

    int leftovers = total_slices - slices_eaten;

// output
    cout << "------------------------------" << endl;
    cout << "There will be " << leftovers << " slices left over." << endl;

    return 0;

}