// CSC 134
// M1LAB - Apple Orchard
// Madison Moon
// 8/21/24
// versuib 2, now with input

#include <iostream>
using namespace std;

int main() {
  //Set up our variables
  string name;
  int    num_apples;
  double price_per_apple;
  double total_cost;

// Get user input
  cout << "What is your name? ";
  cin >> name;
  cout << "How many apples in stock? ";
  cin >> num_apples;
  cout << "How much is one apple? ";
  cin >> price_per_apple;
  
  
  //Say hello
  cout << "-----------------" << endl;
  cout << "Welcome to ";
  cout << name << "'s apple orchard!" << endl;
  
  // Ask some questions
  // TODO, using cin

  //Calculate the total cost
  total_cost = num_apples * price_per_apple;
  
  // Give the answers
  cout << "We have " << num_apples << " apples in stock." << endl;
  cout << "Each apple costs $" << price_per_apple <<  "." << endl;
  cout << "If you want them all, that will be $" <<total_cost << "." << endl;
}