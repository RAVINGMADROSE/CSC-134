// CSC134
// M5HW2 - Halloween++ CYOA
// Madison Moon
// 10/21/24
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

// Global variable for flashlight battery life
int flashlightBattery = 3; // The flashlight can be used 3 times before running out
int health = 100;
vector<string> inventory;
bool hasCompanion = false;

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
void choice_find_cat();
void take_damage(int damage);
void add_item(string item);
void check_inventory();
void solve_puzzle();
void display_ascii_art();
void choice_locked_room();
void choice_find_flashlight();
void choice_dark_room();

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
    cout << "You're in front of a spooky old house..." << endl;
    cout << "You're friends dared you to go inside..." << endl;
    cout << "1. Try the front door" << endl;
    cout << "2. Sneak around back" << endl;
    cout << "3. Forget it, and go home" << endl;
    cout << "4. Check your inventory" << endl;
    cout << "5. [Quit]" << endl;
    cout << "Choose: ";
    int choice;
    cin >> choice;
if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    choice_back_door();
  } else if (3 == choice) {
    choice_go_home();
  } else if (choice == 4) {
    cout << endl;
    check_inventory();
    main_menu(); // Return to main menu after checking inventory
  } else if (5 == choice) {
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
    cout << endl;
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
    cout << endl;
    cout << "The back door is locked too, but you notice a cat door is unsecured and there is a shed near the back fence." << endl;
    cout << "Do you:" << endl;
    cout << "1. Enter through the cat door" << endl;
    cout << "2. Search around the yard" << endl;
    cout << "3. Search the shed for useful items" << endl;
    int choice;
    cout << "Choose: ";
    cin >> choice;
    if (choice == 1) {
        choice_enter_house();
    } else if (choice == 2) {
        cout << endl;
        cout << "You find a stray cat that looks friendly. It follows you." << endl;
        hasCompanion = true;
        add_item("Lucky Cat Companion");
        main_menu();
    } else if (choice == 3) {
        choice_find_flashlight();
    }
}

void choice_find_flashlight() {
    cout << endl;
    cout << "You search the shed and find an old, slightly rusty flashlight." << endl;
    cout << "Do you want to take it?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int choice;
    cout << "Choose: ";
    cin >> choice;
    if (choice == 1) {
        cout << endl;
        add_item("Flashlight");
        cout << "You added the flashlight to your inventory." << endl;
    } else {
        cout << endl;
        cout << "You decide to leave the flashlight behind." << endl;
    }
    main_menu(); // Go back to main menu
}

void choice_go_home() {
    cout << endl;
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
        cout << endl;
        cout << "You go to bed." << endl;
        cout << "***Game Over***" << endl;
    }
}

// any new choices go here
void choice_order_food(){
    cout << endl;
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
    cout << endl;
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
    cout << endl;
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
    cout << endl;
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
    cout << endl;
    cout << "You decide to go to your local pizzeria: 'Freddy Fazbear's Pizzeria.'" << endl;
    cout << "You decide to walk, since it's only a 10 minute walk from your house, and you need to get some steps in." << endl;
    cout << "You walk for five minutes, but you're quickly growing bored..." << endl;
    cout << "You decide to take a shortcut through a sketchy alleyway" << endl;
    cout << "After exiting the alleyway, you make it to Freddy Fazbear's Pizzeria!" << endl;
    cout << "You have a fun night filled with delicious pizza and totally not possessed animatronics." << endl;
    cout << "***Game Over***" << endl;
}

void choice_enter_house() {
    cout << endl;
    cout << "You are in the 'living room'. The floorboards creak under your weight." << endl;
    cout << "You notice a dark room to your left." << endl;
    cout << "Do you:" << endl;
    cout << "1. Go upstairs" << endl;
    cout << "2. Look around the room" << endl;
    cout << "3. Enter the dark room" << endl;
    int choice;
    cout << "Choose: ";
    cin >> choice;
    if (choice == 1) {
        choice_go_upstairs();
    } else if (choice == 2) {
        choice_look_around();
    } else if (choice == 3) {
        choice_dark_room();
    }
}

void choice_dark_room() {
    cout << endl;
    cout << "The room is pitch black, and you can barely see a thing." << endl;
    if (find(inventory.begin(), inventory.end(), "Flashlight") != inventory.end()) {
        cout << endl;
        cout << "You use your flashlight to illuminate the room. You find an old key on the floor!" << endl;
        add_item("key");
    } else {
        cout << endl;
        cout << "It's too dark to see anything. You hear strange noises and decide to leave before it's too late." << endl;
        take_damage(10); // Player takes damage due to a scary encounter in the dark
        cout << endl;
    }
    choice_enter_house();
}

void choice_go_upstairs() {
    cout << endl;
    cout << "The stairs creak as you ascend. You find a long hallway with a locked door at the end." << endl;
    cout << endl;
    if (find(inventory.begin(), inventory.end(), "key") != inventory.end()) {
        cout << "You use the key to unlock the door and find an old journal." << endl;
        cout << "Reading it reveals dark secrets about the house. You win the game with this knowledge!" << endl;
        cout << "***Game Over - You discovered the truth***" << endl;
    } else {
        cout << "The door is locked. You need to find a key first." << endl;
        cout << endl;
        choice_look_around();
    }
}

void choice_look_around() {
    cout << "You search the room and notice a hidden compartment behind an old painting." << endl;
    cout << endl;
    solve_puzzle();
}

void solve_puzzle() {
    cout << "Solve this riddle to open the compartment: What comes once in a minute, twice in a moment, but never in a thousand years?" << endl;
    string answer;
    cin >> answer;
    if (answer == "m" || answer == "M") {
        cout << "Correct! You find a key inside the compartment." << endl;
        add_item("key");
        cout << endl;
    } else {
        cout << "Wrong answer. You hear footsteps approaching and take 10 damage." << endl;
        take_damage(10);
        cout << endl;
    }
}

void take_damage(int damage) {
    health -= damage;
    if (health <= 0) {
        cout << "Your health has reached 0. You collapse, and the world fades to black..." << endl;
        cout << "***Game Over***" << endl;
        exit(0);
    } else {
        cout << "Your current health is: " << health << endl;
        cout << endl;
    }
}

void add_item(string item) {
    inventory.push_back(item);
    cout << "You added " << item << " to your inventory." << endl;
    cout << endl;
}

void check_inventory() {
    cout << "Your inventory contains: ";
    if (inventory.empty()) {
        cout << "nothing" << endl;
    } else {
        for (string item : inventory) {
            cout << item << " ";
        }
        cout << endl;
    }
}

void display_ascii_art() {
    cout << "        .-. " << endl;
    cout << "       (o o) Boo!" << endl;
    cout << "       | O \\ " << endl;
    cout << "        \\   \\ " << endl;
    cout << "         `~~~' " << endl;
    cout << "A ghostly figure appears momentarily, then vanishes..." << endl;
}