/*
CSC 134
M3HW1 - Gold
Madison Moon
10/6/24
*/

#include <iostream>
using namespace std;

int main (){
string choice;

cout << "Hello! I'm a C++ program!" << endl;
cout << "Do you like me? Please type yes or no. ";
cin >> choice;

if (choice == "yes"){
    cout << "That's great! I'm sure we'll get along." << endl;
}
else if (choice == "no"){
    cout << "Well, maybe you'll learn to like me later." << endl;
}
else {
    cout << "If you're not sure...that's okay." << endl;
}
    cout << "Thanks for talking with me!" << endl;
    return 0;
}