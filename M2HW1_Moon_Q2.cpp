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
    // set up variables
    string name;
    int length;
    int width;
    int height;
    int volume; // in cubic feet

    // the price related variables
    const double COST_PER_CU_FT = 0.3;
    const double PRICE_PER_CU_FT = 0.52;
    double cost;
    double customer_price;
    double profit;

    // say hi
    /*
    cout << "Hi, what's your name? ";
    cin >> name;
    cout << "Nice to meet you, " << name << endl;
    */

    //Ask user questions
    cout << "Let's get the crate dimensions. " << endl;
    cout << "What's the length? ";
    cin >> length;
    cout << "What's the width? ";
    cin >> width;
    cout << "Finally, what's the height? ";
    cin >> height;

    //Calculations
    volume = length * width * height;
    cost = volume * COST_PER_CU_FT;
    customer_price = volume * PRICE_PER_CU_FT;
    profit = customer_price - cost;

    //Output
    // next line requires iomanip
    cout << setprecision(2) << fixed;
    cout << "Crate is: " << length << " x " << width << " x " << height << endl;
    cout << "Total volume is: " << volume << " cubic feet." << endl;
    cout << "The cost to build it is: $" << cost << endl;
    cout << "The charge to the customer is: $" << customer_price << endl;
    cout << "The profit is: $" << profit << endl;

}