/*
CSC 134
M3LAB1 - Game
Madison Moon
9/18/24
*/

#include <iostream>
using namespace std;
void enterRoom();
void goForth();

int main() {

  string choice1;

  // ask the question
  cout << "You encounter a dark room, do you wish to enter it?" << endl;
  cout << "Type y or n: "; 
  cin >> choice1;

  if (choice1 == "y") {
    enterRoom();
  }
  else if (choice1 == "n") {
    goForth();
  }
  else {
    cout << "I'm sorry, that is not a valid choice." << endl;
  }

  cout << "Thank you for playing!" << endl;
  return 0;

} 

string choice2;

void enterRoom() {
  cout << "You chose to enter the room." << endl;
  cout << "You encounter a chest! Do you wish to open it?" << endl;
  cout << "Type y or n: ";
  cin >> choice2;
    if (choice2 == "y") {
        cout << "The chest was a mimic! It has grabbed you and will now attempt to eat you whole...";
    }
     else if (choice2 == "n") {
        cout << "The chest seems normal...you continue searching the room." << endl;
    }
    else {
        cout << "I'm sorry, that is not a valid choice." << endl;
    }
}

void goForth() {
  cout << "You chose to continue on." << endl;
  cout << "You journey forth into the unknown..." << endl;
}