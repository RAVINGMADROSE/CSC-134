// CSC134
// M5HW2 - Spooky House Adventure Game
// Madison Moon
// 10/21/24

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <windows.h> // For Beep() function
#include <thread>    // For sleep
#include <chrono>    // For sleep duration
using namespace std;

// Cool stuff I learned about in class!
int health = 100;
int sanity = 100;  // New stat! Tracks how scared you are
int flashlightBattery = 3;
vector<string> backpack;  // Changed name from inventory to backpack
bool hasCat = false;
bool hasKey = false;
bool hasMap = false;
string playerName;

// Function list (I learned about prototypes!)
// Main menu and game state functions
void mainMenu(); // Kept from the second list
void showStats(); // Kept from the second list
void addItem(string item); // Kept from the second list
void checkBackpack(); // Kept from the second list
void takeScaryDamage(int damage, int scariness); // Kept from the second list

// Game sound and visual effects
void spookySound(); // Kept from the second list
void jumpscareSound(); // Kept from the second list
void victorySound(); // Kept from the second list
void gameOverSound(); // Kept from the second list

// Door and navigation choices
void choice_front_door(); // Kept from the second list
void choice_back_door(); // Kept from the second list
void choice_go_home(); // Kept from the second list

// Room choices
void basementChoice(); // Kept from the second list
void atticChoice(); // Kept from the second list
void kitchenChoice(); // Kept from the second list
void libraryChoice(); // Kept from the second list
void secretPassage(); // Kept from the second list
void choice_enter_house(); // Unique from the first list
void choice_go_upstairs(); // Unique from the first list
void choice_look_around(); // Unique from the first list
void choice_find_flashlight(); // Unique from the first list
void choice_dark_room(); // Unique from the first list

// Interactive gameplay mechanics
void solve_puzzle(); // Kept from the second list

// Special events and battles
void finalBattle(); // Kept from the second list

// Miscellaneous choices
void choice_order_food(); // Unique from the first list
void choice_order_sub(); // Unique from the first list
void choice_order_nosferatu(); // Unique from the first list
void choice_order_wolfman(); // Unique from the first list
void choice_ar_ar_arar(); // Unique from the first list

// Makes spooky sounds!
void spookySound() {
    Beep(300, 300);
    Beep(200, 300);
}

void jumpscareSound() {
    Beep(800, 100);
    Beep(1000, 100);
    Beep(600, 100);
}

void victorySound() {
    Beep(500, 200);
    Beep(600, 200);
    Beep(700, 200);
    Beep(800, 400);
}

void gameOverSound() {
    Beep(400, 400);
    Beep(300, 400);
    Beep(200, 800);
}

// Shows your current stats
void showStats() {
    cout << "\n=== " << playerName << "'s Stats ===" << endl;
    cout << "Health: " << health << "/100" << endl;
    cout << "Sanity: " << sanity << "/100" << endl;
    cout << "Flashlight Battery: " << flashlightBattery << endl;
    if (hasCat) {
        cout << "Cat Friend: Yes!" << endl;
    }
    cout << "===================" << endl;
}

// Handles taking damage and getting scared
void takeScaryDamage(int damage, int scariness) {
    health -= damage;
    sanity -= scariness;
    
    if (hasCat) {  // Cat friend makes you braver!
        sanity += 5;
        cout << "Your cat friend helps calm you down!" << endl;
    }
    
    spookySound();
    cout << "Ouch! You took " << damage << " damage and lost " << scariness << " sanity!" << endl;
    
    if (health <= 0) {
        cout << "\nYou collapsed from fear..." << endl;
        gameOverSound();
        cout << "GAME OVER - You died!" << endl;
        exit(0);
    }
    
    if (sanity <= 0) {
        cout << "\nYou lost your mind from fear!" << endl;
        gameOverSound();
        cout << "GAME OVER - You went insane!" << endl;
        exit(0);
    }
}

void addItem(string item) {
    backpack.push_back(item);
    cout << "\nYou got: " << item << "!" << endl;
    Beep(600, 200); // Item pickup sound
}

void checkBackpack() {
    cout << "\n=== Your Backpack ===" << endl;
    if (backpack.empty()) {
        cout << "Empty... maybe you'll find something useful!" << endl;
    } else {
        for (string item : backpack) {
            cout << "- " << item << endl;
        }
    }
}

// New scenarios!
void basementChoice() {
    cout << "\nYou enter the dark basement..." << endl;
    spookySound();
    cout << "1. Search the old boxes" << endl;
    cout << "2. Check the weird glowing corner" << endl;
    cout << "3. Run back upstairs" << endl;
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << "\nYou find an ancient key in the boxes!" << endl;
        addItem("Ancient Key");
        hasKey = true;
    } else if (choice == 2) {
        cout << "\nOh no! It's a ghost!" << endl;
        jumpscareSound();
        takeScaryDamage(20, 30);
    } else {
        cout << "\nYou run back upstairs, tripping on the way..." << endl;
        takeScaryDamage(5, 10);
    }
}

void atticChoice() {
    cout << "\nThe attic is filled with cobwebs..." << endl;
    spookySound();
    if (!hasKey) {
        cout << "The door is locked! You need a key." << endl;
        return;
    }
    
    cout << "1. Look through the old trunk" << endl;
    cout << "2. Read the dusty diary" << endl;
    cout << "3. Follow the ghostly whispers" << endl;
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << "\nYou found a map of secret passages!" << endl;
        addItem("Secret Map");
        hasMap = true;
    } else if (choice == 2) {
        cout << "\nThe diary reveals dark secrets about the house..." << endl;
        cout << "Your sanity takes a hit from the revelations!" << endl;
        takeScaryDamage(0, 20);
    } else {
        cout << "\nThe whispers lead you to a hidden room..." << endl;
        secretPassage();
    }
}

void kitchenChoice() {
    cout << "\nThe kitchen looks abandoned..." << endl;
    cout << "1. Check the fridge" << endl;
    cout << "2. Look in the cabinets" << endl;
    cout << "3. Investigate the strange noises" << endl;
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << "\nYou found some old pizza! Gross!" << endl;
        takeScaryDamage(10, 5);
    } else if (choice == 2) {
        cout << "\nYou found some health potions!" << endl;
        addItem("Health Potion");
        health += 30;
        if (health > 100) health = 100;
        cout << "You feel better! Health restored to " << health << endl;
    } else {
        cout << "\nA ghost chef throws pots and pans at you!" << endl;
        jumpscareSound();
        takeScaryDamage(15, 20);
    }
}

void libraryChoice() {
    cout << "\nThe library is filled with floating books!" << endl;
    cout << "1. Try to read a floating book" << endl;
    cout << "2. Look for clues about the house" << endl;
    cout << "3. Run away!" << endl;
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << "\nThe book tries to eat you!" << endl;
        jumpscareSound();
        takeScaryDamage(20, 25);
    } else if (choice == 2) {
        cout << "\nYou find an old newspaper..." << endl;
        cout << "It reveals the house is built on an ancient burial ground!" << endl;
        takeScaryDamage(0, 15);
        if (!hasMap) {
            cout << "You also find a strange map!" << endl;
            addItem("Secret Map");
            hasMap = true;
        }
    } else {
        cout << "\nYou escape the library safely!" << endl;
    }
}

void secretPassage() {
    if (!hasMap) {
        cout << "\nYou need a map to navigate the secret passages!" << endl;
        return;
    }
    
    cout << "\nYou enter a hidden passage..." << endl;
    cout << "The walls are covered in glowing symbols..." << endl;
    cout << "1. Follow the red symbols" << endl;
    cout << "2. Follow the blue symbols" << endl;
    cout << "3. Go back" << endl;
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << "\nThe symbols lead to a treasure room!" << endl;
        addItem("Ghost Charm");
        cout << "You feel braver with the Ghost Charm!" << endl;
        sanity += 30;
        if (sanity > 100) sanity = 100;
    } else if (choice == 2) {
        cout << "\nYou found the final boss room!" << endl;
        finalBattle();
    } else {
        cout << "\nYou return to safety." << endl;
    }
}

void finalBattle() {
    cout << "\n=== FINAL BATTLE ===" << endl;
    cout << "You face the Ghost King!" << endl;
    jumpscareSound();
    
    if (hasCat && find(backpack.begin(), backpack.end(), "Ghost Charm") != backpack.end()) {
        cout << "\nYour cat friend and Ghost Charm protect you!" << endl;
        cout << "The Ghost King recognizes your bravery..." << endl;
        cout << "He gives you his crown and disappears!" << endl;
        victorySound();
        cout << "\nCONGRATULATIONS! You won the game!" << endl;
        cout << "You are now the ruler of the ghost house!" << endl;
        exit(0);
    } else {
        cout << "\nYou're not prepared for this battle!" << endl;
        cout << "The Ghost King is too powerful..." << endl;
        gameOverSound();
        cout << "GAME OVER - Get the cat friend and Ghost Charm first!" << endl;
        exit(0);
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    cout << "Welcome to the Spooky House Adventure!" << endl;
    cout << "What's your name, brave explorer? ";
    getline(cin, playerName);
    
    cout << "\nHi " << playerName << "! Ready for a spooky adventure?" << endl;
    spookySound();
    
    mainMenu();
    return 0;
}

void mainMenu() {
    while (true) {
        showStats();
        cout << "\nYou're in front of a creepy old house..." << endl;
        cout << "Your friends dared you to go inside..." << endl;
        cout << "\nWhat do you do?" << endl;
        cout << "1. Try the front door" << endl;
        cout << "2. Check the back door" << endl;
        cout << "3. Go to the basement window" << endl;
        cout << "4. Check your backpack" << endl;
        cout << "5. Give up and go home" << endl;
        
        int choice;
        cout << "Your choice (1-5): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                frontDoor();
                break;
            case 2:
                backDoor();
                break;
            case 3:
                basementChoice();
                break;
            case 4:
                checkBackpack();
                break;
            case 5:
                cout << "\nYou chickened out! Game Over!" << endl;
                gameOverSound();
                exit(0);
            default:
                cout << "Please pick a valid choice!" << endl;
        }
    }
}
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