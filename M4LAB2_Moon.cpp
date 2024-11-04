// CSC 134
// M4LAB2 - Craps (was M3T3)
//Madison Moon
// 10/9/24

#include <iostream>
#include <cstdlib> //for rand()
#include <ctime>   //for time()
using namespace std;

int roll () {
// get a random number from 1 to 6
int die = (rand() % 6) + 1;
return die;
}

bool play_round();

int main()
{
    // set up your variables
    int die1, die2, total;
    int seed; // random seed
    bool is_winner;
    // get input
    cout << "Welcome to the craps table." << endl;
    seed = time(0);
    srand (seed); // seed the RNG
    //play a round of craps
    is_winner = play_round();
    if (is_winner){
        cout << "You won!" << endl;
    }
    else {
        cout << "You lost." << endl;
    }
    return 0;
}

bool play_round(){
    bool is_winner = false; //house wins by default
    int die1 = roll();
    int die2 = roll();
    int point;
    // give the results
    int total = die1 + die2;
    cout << " You rolled "
         << die1 << " + "
         << die2 << " = " << total << endl;

    // did they win or lose?
    if (total == 7 || total == 11) {
        cout << "You win!!! : )" << endl;
        is_winner = true;
    }
    else if (total == 2 || total == 3 || total == 12){
        cout << "You lose : (" << endl;
        is_winner = false;
    }
    else {
        // TODO : handle "rolling a point"
        cout << "Your point is: " << total << endl;
        point = total; // save the point
        // we need a do while loop
        total = roll() + roll();
        cout << "Reroll: " << total << endl;
        // keep rolling until you get point (win) or 7 (lose)
        do {
            total = roll() + roll();
            cout << "Come on lucky " << point << " rolled: " << total << endl;
            if (total == 7) {
                is_winner = false;
            }
            if (total == point) {
                is_winner = true;
            }
        } while (total != 7 && total != point);
    }
    return is_winner;
}