/*
CSC 134
M4LAB1 - emojis
Madison Moon
10/7/24
*/

#include <iostream>
using namespace std;

int main(){
    //cout << "M4LAB1" << endl;
    string emoji = "💀";
    // cout << "emoji" << endl;
    // Print sideways (row)
    /*
    for (int i = 0; i < 9; i++){
        cout << emoji << " " ;
    }
    cout << endl; // finish the row
   
    // Print down (column)
    for (int j = 0; j < 9; j++){
        cout << emoji << endl;
    }
    */
    cout << "Full version: " << endl << endl;

    const int ROWS = 4;
    const int COLS = 6;

    //put both together, to fill in the rectangle
    for (int i = 0; i < 9; i++){
        for (int j =0; j < 9; j++){
            cout << emoji << " ";
        }
        cout << endl;
    }
    cout << endl;
}