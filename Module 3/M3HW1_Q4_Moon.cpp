/*
CSC 134
M3HW1 - Gold
Madison Moon
10/6/24
*/

#include <iostream>
#include <cstdlib> //for rand()
#include <ctime> //
using namespace std;
int roll () {
// get a random number from 1 to 9
int die = (rand() % 9) + 1;
return die;
}
int main()
{
 
// set up your variables
int die1, die2, total, correct_total;
int seed; // random seed
 
// get input
 
cout << "Welcome to Math Practice." << endl;
seed = time(0);
srand (seed); // seed the RNG
 
die1 = roll();
die2 = roll();
correct_total = die1 + die2;
 
// give the results
 
cout << "What is " 
<< die1 << " + "
<< die2 << " ? " << endl;
cin >> total;

if (total == correct_total){
    cout << "Correct!" << endl;
}
else if (total != correct_total){
    cout << "Incorrect :(" << endl;
}
else {
    cout << "Input is not valid." << endl;
}
}