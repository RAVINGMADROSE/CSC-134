// CSC134
// M5LAB1 - CYOA
// Madison Moon
// 10/21/24
#include <iostream>
using namespace std;

// Function Prototypes
// Any functions you make will need to
// be listed here, in this format, at the top.
// This is so the compiler knows to save
// room for them in the final program.
void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
// TODO: add more choices here
void choice_order_food();
void choice_order_sub();
void choice_order_nosferatu();
void choice_order_wolfman();
void choice_ar_ar_arar();
void choice_enter_house();
void choice_go_upstairs();
void choice_look_around();

int main() {
  cout << "M5LAB1 - Choose Your Own Adventure" << endl;
  // load up the main menu
  main_menu();
  // when we return here, we're done
  cout << "Thanks for playing!" << endl;
  return 0; // finished with no errors
}

void main_menu() {
  // Write a simple menu that lets the user choose 1,2, or 3, or 4 to quit.
    cout << "Main Menu" << endl;
    cout << "You're in front of a spooky old house..." << endl;
    cout << "You're friends dared you to go inside..." << endl;
    cout << "Do you:" << endl;
    cout << "1. Try the front door" << endl;
    cout << "2. Sneak around back" << endl;
    cout << "3. Forget it, and go home" << endl;
    cout << "4. [Quit]" << endl;
    cout << "Choose: ";
    int choice;
    cin >> choice;
if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    choice_back_door();
  } else if (3 == choice) {
    choice_go_home();
  } else if (4 == choice) {
    cout << "Ok, quitting game" << endl;
    return; // go back to main()
  } else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore(); // clear the user input
    main_menu();  // try again
  }
}

// FUNCTION DEFINITIONS
// OK, we have the prototypes at the top, but
// now we have to actually write the functions.
// They go here, after main().
void choice_front_door() {
    cout << "Try the front door." << endl;
    cout << "It's locked. " << endl;
    cout << "Do you:" << endl;
    cout << "1. Check around back" << endl;
    cout << "2. Give up and go home" << endl;
  int choice;
    cout << "Choose: ";
    cin >> choice;
  if (1 == choice) {
        choice_back_door();
    } else if (2 == choice) {
        choice_go_home();
    }
}

void choice_back_door() {
    cout << "The back door is locked too, but you notice the cat door is unsecured." << endl;
    cout << "Do you:" << endl;
    cout << "1. Let yourself in through the cat door" << endl;
    cout << "2. Keep your dignity and go home" << endl;
    cout << "Choose: ";
    int choice;
    cin >> choice;
    if (1 == choice){
        choice_enter_house();
    } else if (2 == choice){
        choice_go_home();
    }
}

void choice_go_home() {
    cout << "You decide to go home." << endl;
    cout << "Safe at home, do you:" << endl;
    cout << "1. Order some food" << endl;
    cout << "2. Go to bed" << endl;
    cout << "Choose: ";
    int choice;
    cin >> choice;
    if (1 == choice) {
        choice_order_food();
    } else if (2 == choice) {
        cout << "You go to bed." << endl;
        cout << "***Game Over***" << endl;
    }
}

// any new choices go here
void choice_order_food(){
    cout << "You decide to order food." << endl;
    cout << "Do you:" << endl;
    cout << "1. Order a sub on DoorDash." << endl;
    cout << "2. Enjoy a sit down meal at your local pizzeria." << endl;
    cout << "Choose: ";
    int choice;
    cin >> choice;
    if (1 == choice) {
        choice_order_sub();
    } else if (2 == choice) {
        choice_ar_ar_arar();
    }
}

void choice_order_sub(){
    cout << "You decide to DoorDash a sub from Big Tony's Gigantic Submarine Sandwiches" << endl;
    cout << "You must decide which sub you would like to order:" << endl;
    cout << "1. Nosferatu's Garlicious Meatball Sub." << endl;
    cout << "2. Wolfman's Giant Meatlover's Challenge Sub." << endl;
    cout << "Choose: ";
    int choice;
    cin >> choice;
    if (1 == choice) {
        choice_order_nosferatu();
    } else if (2 == choice) {
        choice_order_wolfman();
    }
}

void choice_order_nosferatu(){
    cout << "You have decided to order 'Nosferatu's Garlicious Meatball Sub.'" << endl;
    cout << "After 20 minutes, your doorbell rings and the app chimes alerting you that your doordash has arrived." << endl;
    cout << "You slowly open the door, the hinges creaking from years of use..." << endl;
    cout << "creEeEaaAaaaaaAaaaaaak........" << endl;
    cout << "...Oh- it looks like the Nosferatu got a sidegig on DoorDash." << endl;
    cout << "You take your food, but ultimately decide to skip out on the tip- he was a bit rude after all..." << endl;
    cout << "Nosferatu drains all your blood." << endl;
    cout << "***Game Over***" << endl;
    cout << "*Don't forget to tip your driver OoooOOOoooo*" << endl;
}

void choice_order_wolfman(){
    cout << "You have decided to order 'Wolfman's Giant Meatlover's Challenge Sub.'" << endl;
    cout << "After 20 minutes, your doorbell rings and the app chimes alerting you that your doordash has arrived." << endl;
    cout << "You slowly open the door, the hinges creaking from years of use..." << endl;
    cout << "creEeEaaAaaaaaAaaaaaak........" << endl;
    cout << "...Oh- it looks like the wolfman got a sidegig on DoorDash." << endl;
    cout << "You take your food, but ultimately decide to skip out on the tip- he was a bit rude after all..." << endl;
    cout << "The wolfman eats you." << endl;
    cout << "***Game Over***" << endl;
    cout << "*Don't forget to tip your driver OoooOOOoooo*" << endl;
}

void choice_ar_ar_arar(){
    cout << "You decide to go to your local pizzeria: 'Freddy Fazbear's Pizzeria.'" << endl;
    cout << "You decide to walk, since it's only a 10 minute walk from your house, and you need to get some steps in." << endl;
    cout << "You walk for five minutes, but you're quickly growing bored..." << endl;
    cout << "You decide to take a shortcut through a sketchy alleyway" << endl;
    cout << "After exiting the alleyway, you make it to Freddy Fazbear's Pizzeria!" << endl;
    cout << "You have a fun night filled with delicious pizza and totally not possessed animatronics." << endl;
    cout << "***Game Over***" << endl;
}

void choice_enter_house(){
    cout << "You enter the dim and dusty old house." << endl;
    cout << "The floorboards creak beneath your weight, as you come across a staircase" << endl;
    cout << "You hear a woman singing faintly, and ever-so hauntingly up the stairs." << endl;
    cout << "Do you:" << endl;
    cout << "1. Go up the stairs" << endl;
    cout << "2. Resume looking around." << endl;
    cout << "Choose: ";
    int choice;
    cin >> choice;
    if (1 == choice) {
        choice_go_upstairs();
    } else if (2 == choice) {
        choice_look_around();
    }
}

void choice_look_around(){
    cout << "You take the chance to look around, noticing the sweltering heat of the room." << endl;
    cout << "The overwhelming smell of tender flesh and baked goods mingle in your nostrils." << endl;
    cout << "Out of the corner of your eye, you notice a cross stitch on the wall with the message..." << endl;
    cout << "...'I <3 eating children'...!" << endl;
    cout << "This is a witches house! You hear a creaking, as someone begins to descend the stairs." << endl;
    cout << "You decide to flee home with haste, barely escaping the grasp of a hungry witch." << endl;
    choice_go_home();
}

void choice_go_upstairs(){
    cout << "The floorboards groan beneath you, as you take a tentative step up the stairs..." << endl;
    cout << "Then another..." << endl;
    cout << "...then another..." << endl;
    cout << "... until you finally reach the top of the stairs, and come across an eerily long hallway." << endl;
    cout << "There is a door at the very end of the hallway, where you can still here the faint singing." << endl;
    cout << "Do you:" << endl;
    cout << "1. Enter the room" << endl;
    cout << "2. Flee the house" << endl;
    cout << "Choose: ";
    int choice;
    cin >> choice;
    if (1 == choice) {
        cout << "The door creaks open and you spot a woman in the corner brushing her hair in front of an antique vanity." << endl;
        cout << "She tenses, and slowly turns to face you..." << endl;
        cout << "Her face is young and beautiful..." << endl;
        cout << "You approach her, but as you get closer her countenance evolves into the haggard maw of a witch!" << endl;
        cout << "She devours you whole, on the spot." << endl;
        cout << "***Game Over***" << endl;
    } else if (2 == choice) {
        choice_go_home();
    }
}