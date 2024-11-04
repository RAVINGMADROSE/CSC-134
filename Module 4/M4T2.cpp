// CSC 134
// M4T2 - Input Validation
// Madison Moon
// 10/2/24
#include <iostream>

using namespace std;

void counting();

int main()
{
    // Quick loop example
    //counting();

    // input validation examples
    const int MIN_PLAYERS = 1;
    const int MAX_PLAYERS = 4;
    int num_players;
    cout << "How many players? (1-4): ";
    cin >> num_players;
    while (num_players < MIN_PLAYERS || num_players > MAX_PLAYERS) {
        //error!
        cout << "Please choose between " << MIN_PLAYERS;
        cout << " and " << MAX_PLAYERS << " players." << endl;
        cout << "How many players? (1-4): ";
        cin >> num_players;
    }
    cout << "You're playing with " << num_players << " players." << endl;

    // ready to start?
    string ready;
    do {
        cout << "waiting..." << endl;
        cout << "Are all players ready?(yes/no) ";
        cin >> ready;
    } while (ready != "yes");

    return 0;
}

void counting() {
    cout << "version 1: while" << endl;
    int num = 0;
    while (num < 5) {
    cout << num << endl;
    num++;
}
    cout << "version 2: for" << endl;
    for (int n=0; n<5; n++) {
        cout << n << endl;
    }
}

