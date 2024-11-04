/*
CSC 134
M3HW1 - Gold
Madison Moon
10/6/24
*/

#include <iostream>
using namespace std;
void enterRoom1();
void enterRoom2();
void goForth();

int main() {

  string choice1;

  // ask the question
  cout << "You find yourself standing in front of two doors deep inside an ancient, forgotten temple. The air is thick with mystery." << endl;
  cout << endl;
  cout << "Do you:" << endl << "1. Open the left door." << endl << "2. Open the right door." << endl; 
  cout << "Please type 1 or 2. ";
  cin >> choice1;
  cout << endl;

  if (choice1 == "1") {
    enterRoom1();
  }
  else if (choice1 == "2") {
    enterRoom2();
  }
  else {
    cout << "I'm sorry, that is not a valid choice." << endl;
  }

  cout << "Thank you for playing!" << endl;
  return 0;

} 

string choice2;
string choice3;

void enterRoom1() {
  cout << "You open the left door and step inside. The room is dimly lit, but you notice a chest at the far end of the room." << endl;
  cout << "Suddenly, you hear a faint hissing sound, and you realize you're not alone-snakes begin slithering from the shadows!" << endl;
  cout << endl;
  cout << "Do you:" << endl << "1. Run for the chest in hopes of finding something useful." << endl;
  cout << "2. Retreat and close the door behind you, escaping the snakes." << endl; 
  cout << "Please type 1 or 2. ";
  cin >> choice2;
  cout << endl;
    if (choice2 == "1") {
        cout << "You dash toward the chest, hoping it holds something to save you. As you reach it, you fling it open and find..." << endl;
        cout << "A pair of venomous fangs waiting inside. The snake hidden within strikes before you can reach" << endl;
        cout << endl;
        cout << "GAME OVER" << endl;
        cout << endl;
    }
     else if (choice2 == "2") {
        cout << "You quickly retreat and slam the door shut, blocking the snakes from following you. You breathe a sigh of relief and turn back to the hallway." << endl;
        cout << "There's another path ahead that leads deeper into the temple." << endl;
        cout << endl;
        cout << "Do you:" << endl << "1. Continue forward down the mysterious path." << endl;
        cout << "2. Leave the temple, deciding it's too dangerous to proceed." << endl; 
        cout << "Please type 1 or 2. ";
        cin >> choice3;
        cout << endl;
            if (choice3 == "1"){
            goForth();
        }
            else if (choice3 == "2"){
            cout << "Like a coward, you flee from the temple and decide to leave your adventuring days behind." << endl;
            cout << endl;
            cout << "GAME OVER" << endl;
            cout << endl;
        }
            else {
            cout << "I'm sorry, that is not a valid choice." << endl;
        }
    }
    else {
        cout << "I'm sorry, that is not a valid choice." << endl;
    }
}

string choice4;

void enterRoom2() {
  cout << "You open the right door and step inside. The room is illuminated by a soft glow, and at the center, a pedestal holds a shining gem." << endl;
  cout << "It looks valuable, but you can feel a strange energy surrounding it." << endl;
  cout << endl;
  cout << "Do you:" << endl << "1. Take the gem, hoping it will lead to treasure." << endl;
  cout << "2. Leave the gem and explore the room for other exits." << endl; 
  cout << "Please type 1 or 2. ";
  cin >> choice4;
  cout << endl;
    if (choice4 == "1") {
        cout << "You reach out and take the gem. As soon as you grasp it, the ground shakes, and the walls begin to close in!" << endl;
        cout << "You realize that taking the gem has triggered a trap." << endl;
        cout << endl;
        cout << "GAME OVER" << endl;
        cout << endl;
    }
     else if (choice4 == "2") {
        cout << "You decide to leave the gem and explore the room. As you search the walls, you find a hidden passage behind a tapestry." << endl;
        cout << "Stepping through the passage, you emerge into a bright chamber filled with gold and ancient artifacts." << endl;
        cout << "You've found the treasure room!" << endl;
        cout << endl;
        cout << "Congratulations! YOU WIN!" << endl;
        cout << endl;
    }
    else {
        cout << "I'm sorry, that is not a valid choice." << endl;
    }
}

string choice5;

void goForth(){
  cout << "You gather your courage  and continue forward down the mysterious path. The cooridor twists and turns, finally leading you to a grand hall." << endl;
  cout << "At the center of the room is a glowing artifact on a pedestal, surrounded by strange markings on the floor." << endl;
  cout << endl;
  cout << "Do you:" << endl << "1. Take the artifact, risking what may happen." << endl;
  cout << "2. Examine the markings before making a decision." << endl; 
  cout << "Please type 1 or 2. ";  
  cin >> choice5;
  cout << endl;
    if (choice4 == "1"){
        cout << "You boldly step forward and take the glowing artifact from the pedestal. The moment you touch it, the ground begins to shake violently!" << endl;
        cout << "The markings on the floor light up, and a loud rumbling fills the air." << endl;
        cout << "Suddenly, a trapdoor opens beneath you, and you fall into the darkness!" << endl;
        cout << endl;
        cout << "GAME OVER" << endl;
        cout << endl;
    }
    else if (choice5 == "2"){
        cout << "You decide to examine the markings on the floor first. As you study them closely, you realize they form an incantation." << endl;
        cout << "You decide to read the incantation and a passage opens." << endl;
        cout << "Stepping through the passage, you emerge into a dusty chamber filled with ancient tomes and old relics." << endl;
        cout << "You've found the library!" << endl;
        cout << endl;
        cout << "Congratulations! YOU WIN!" << endl;
        cout << endl;
    }
    else {
        cout << "I'm sorry, that is not a valid choice." << endl;
    }
}