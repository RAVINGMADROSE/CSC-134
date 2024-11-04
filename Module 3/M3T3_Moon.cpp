// CSC 134
// M3T3 - Craps
//Madison Moon
// 9/25/24

#include <iostream>
#include <cstdlib> //for rand()
#include <ctime>   //
using namespace std;

int roll () {
// get a random number from 1 to 6
int die = (rand() % 6) + 1;
return die;
}

int main()
{
    // set up your variables
    int die1, die2, total;
    int seed; // random seed

    // get input
    cout << "Welcome to the craps table." << endl;
    //cout << "Enter your lucky number: ";
    //cin >> seed;
    seed = time(0);
    srand (seed); // seed the RNG
    //cout << "Enter your two dice rolls" << endl;
    //cin >> die1 >> die2;
    // roll two random numbers
    // rand() mod 6 gives 0 to 5, so add 1
    die1 = roll();
    die2 = roll();
    //die1 = (rand() % 6) + 1;
    //die2 = (rand() % 6) + 1;

    // give the results
    total = die1 + die2;
    cout << " Your rolled "
         << die1 << " + "
         << die2 << " = " << total << endl;

    // did they win or lose?
    if (total == 7 || total == 11) {
        cout << "You win!!! : )" << endl;
    }
    else if (total == 2 || total == 3 || total == 12){
        cout << "You lose : (" << endl;
    }
    else {
        // TODO : handle "rolling a point"
        cout << "Your point is: " << total << endl;
        cout << "We'll handle this later." << endl;
    }

    return 0;
}
