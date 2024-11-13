// CSC134
// M5LAB1 - Raspberry Roulette
// Madison Moon
// 10/21/24

#include <iostream>
using namespace std;

//constant
const int NUM_ROUNDS = 3;
const int RED = 1; // LIVE
const int BLACK = 0; // BLANK

int main() {
    // load the chamber
    int chamber[] = {RED, BLACK, RED};
   // cout << chamber << endl; // Note: This doesn't work!
   //Use a range-based loop to print all rounds instead!
   for (int round:chamber){
    if (round == RED) {
        cout << "RED ";
    }
    if (round == BLACK) {
        cout << "BLACK ";
    }
   }
   cout << endl;
}