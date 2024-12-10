// CSC134  
// M5HW2 - Spooky House Adventure Game  
// Madison Moon  
// 10/21/24  
  
#include <iostream>  
#include <vector>  
#include <algorithm>  
#include <ctime>  
#include <cstdlib>
using namespace std;  
  
// Cool stuff I learned about in class!  
int health = 100;  
int sanity = 100;  // New stat! Tracks how scared you are  
int flashlightBattery = 3;  
vector<string> backpack;
bool hasCat = false;  
bool hasKey = false;  
bool hasMap = false;  
string playerName;  
  
// Function list (I learned about prototypes!)  
// Main menu and game state functions  
void mainMenu();
void showStats();
void addItem(string item);
void checkBackpack();   
void takeScaryDamage(int damage, int scariness);
  
// Visual effects  
void display_ascii_art();
  
// Door and navigation choices  
void frontDoorChoice();
void backDoorChoice();
void goHomeChoice();
  
// Room choices  
void basementChoice();
void atticChoice();
void kitchenChoice();
void libraryChoice();
void secretPassageChoice();
void enterHouseChoice();
void goUpstairsChoice();
void lookAroundChoice();
void darkRoomChoice();

// Interactive gameplay mechanics  
void solvePuzzle();
  
// Special events and battles  
void finalBattle();
  
// Miscellaneous choices  
void orderFoodChoice();
void orderSubChoice();
void orderNosferatuChoice();
void orderWolfmanChoice();
void arArArarChoice();
  
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
   cout << "Ouch! You took " << damage << " damage and lost " << scariness << " sanity!" << endl;  
    
   if (health <= 0) {  
      cout << "\nYou collapsed from fear..." << endl;  
      cout << "GAME OVER - You died!" << endl;  
      exit(0);  
   }  
    
   if (sanity <= 0) {  
      cout << "\nYou lost your mind from fear!" << endl;  
      cout << "GAME OVER - You went insane!" << endl;  
      exit(0);  
   }  
}  
  
void addItem(string item) {  
   backpack.push_back(item);  
   cout << "\nYou got: " << item << "!" << endl;  
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
      display_ascii_art();  
      takeScaryDamage(20, 30); 
      cout << "\nYou run upstairs!" << endl;  
      enterHouseChoice(); 
   } else {  
      cout << "\nYou run upstairs, tripping on the way..." << endl;  
      takeScaryDamage(5, 10);
      enterHouseChoice();  
   }  
}  
  
void atticChoice() {  
   cout << "\nThe attic is filled with cobwebs..." << endl;  
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
      atticChoice();  
   } else if (choice == 2) {  
      cout << "\nThe diary reveals dark secrets about the house..." << endl;  
      cout << "Your sanity takes a hit from the revelations!" << endl;  
      takeScaryDamage(0, 20);  
      atticChoice(); 
   } else {  
      cout << "\nThe whispers lead you to a hidden room..." << endl;  
      secretPassageChoice();  
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
      display_ascii_art();   
      takeScaryDamage(15, 20);  
   } 
   cout << "You head back to the Living Room." << endl;
   enterHouseChoice();
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
   cout << "You head back to the Living Room." << endl;
   enterHouseChoice();  
}  
  
void secretPassageChoice() {  
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
      enterHouseChoice();  
   }  
}  
  
void finalBattle() {  
   cout << "\n=== FINAL BATTLE ===" << endl;  
   cout << "You face the Ghost King!" << endl;  
   display_ascii_art();
    
   if (hasCat && find(backpack.begin(), backpack.end(), "Ghost Charm") != backpack.end()) {  
      cout << "\nYour cat friend and Ghost Charm protect you!" << endl;  
      cout << "The Ghost King recognizes your bravery..." << endl;  
      cout << "He gives you his crown and disappears!" << endl;  
      cout << "\nCONGRATULATIONS! You won the game!" << endl;  
      cout << "You are now the ruler of the ghost house!" << endl;  
      exit(0);  
   } else {  
      cout << "\nYou're not prepared for this battle!" << endl;  
      cout << "The Ghost King is too powerful..." << endl;  
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
           frontDoorChoice();  
           break;  
        case 2:  
           backDoorChoice();  
           break;  
        case 3:  
           basementChoice();  
           break;  
        case 4:  
           checkBackpack();  
           break;  
        case 5:  
           cout << "\nYou chickened out! Game Over!" << endl;  
           exit(0);  
        default:  
           cout << "Please pick a valid choice!" << endl;  
      }  
   }  
}  
  
void frontDoorChoice() {  
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
      backDoorChoice();  
   } else if (2 == choice) {  
      goHomeChoice();  
   }  
}  
  
void backDoorChoice() {  
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
      enterHouseChoice();  
   } else if (choice == 2) {  
      cout << endl;  
      cout << "You find a stray cat that looks friendly. It follows you." << endl;  
      hasCat = true;  
      addItem("Lucky Cat Companion");  
      backDoorChoice(); 
   } else if (choice == 3) {  
      cout << endl;  
      cout << "You search the shed and find an old, slightly rusty flashlight." << endl;  
      cout << "Do you want to take it?" << endl;  
      cout << "1. Yes" << endl;  
      cout << "2. No" << endl;  
      int choice;  
      cout << "Choose: ";  
      cin >> choice;  
      if (choice == 1) {  
        addItem("Flashlight");  
        cout << "You added the flashlight to your inventory." << endl;  
      } else {  
        cout << endl;  
        cout << "You decide to leave the flashlight behind." << endl;  
      }  
      backDoorChoice(); // Go back to backyard 
   }  
}  
  
void goHomeChoice() {  
   cout << endl;  
   cout << "You decide to go home." << endl;  
   cout << "Safe at home, do you:" << endl;  
   cout << "1. Order some food" << endl;  
   cout << "2. Go to bed" << endl;  
   cout << "Choose: ";  
   int choice;  
   cin >> choice;  
   if (1 == choice) {  
      orderFoodChoice();  
   } else if (2 == choice) {  
      cout << endl;  
      cout << "You go to bed." << endl;  
      cout << "***Game Over***" << endl;  
   }  
}  
  
// any new choices go here  
void orderFoodChoice(){  
   cout << endl;  
   cout << "You decide to order food." << endl;  
   cout << "Do you:" << endl;  
   cout << "1. Order a sub on DoorDash." << endl;  
   cout << "2. Enjoy a sit down meal at your local pizzeria." << endl;  
   cout << "Choose: ";  
   int choice;  
   cin >> choice;  
   if (1 == choice) {  
      orderSubChoice();  
   } else if (2 == choice) {  
      arArArarChoice();  
   }  
}  
  
void orderSubChoice(){  
   cout << endl;  
   cout << "You decide to DoorDash a sub from Big Tony's Gigantic Submarine Sandwiches" << endl;  
   cout << "You must decide which sub you would like to order:" << endl;  
   cout << "1. Nosferatu's Garlicious Meatball Sub." << endl;  
   cout << "2. Wolfman's Giant Meatlover's Challenge Sub." << endl;  
   cout << "Choose: ";  
   int choice;  
   cin >> choice;  
   if (1 == choice) {  
      orderNosferatuChoice();  
   } else if (2 == choice) {  
      orderWolfmanChoice();  
   }  
}  
  
void orderNosferatuChoice(){  
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
  
void orderWolfmanChoice(){  
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
  
void arArArarChoice(){  
   cout << endl;  
   cout << "You decide to go to your local pizzeria: 'Freddy Fazbear's Pizzeria.'" << endl;  
   cout << "You decide to walk, since it's only a 10 minute walk from your house, and you need to get some steps in." << endl;  
   cout << "You walk for five minutes, but you're quickly growing bored..." << endl;  
   cout << "You decide to take a shortcut through a sketchy alleyway" << endl;  
   cout << "After exiting the alleyway, you make it to Freddy Fazbear's Pizzeria!" << endl;  
   cout << "You have a fun night filled with delicious pizza and totally not possessed animatronics." << endl;  
   cout << "***Game Over***" << endl;  
}  
  
void enterHouseChoice() {  
   cout << endl;  
   cout << "You are in the 'living room'. The floorboards creak under your weight." << endl;  
   cout << "You notice a dark room to your left." << endl;  
   cout << "Do you:" << endl;  
   cout << "1. Go upstairs" << endl;  
   cout << "2. Look around the room" << endl;  
   cout << "3. Enter the dark room" << endl;
   cout << "4. Enter the kitchen" << endl;
   int choice;  
   cout << "Choose: ";  
   cin >> choice;  
   if (choice == 1) {  
      goUpstairsChoice();  
   } else if (choice == 2) {  
      lookAroundChoice();  
   } else if (choice == 3) {  
      darkRoomChoice();  
   }  
   else {
    kitchenChoice();
   }
}  
  
void darkRoomChoice() {  
   cout << endl;  
   cout << "The room is pitch black, and you can barely see a thing." << endl;  
   if (find(backpack.begin(), backpack.end(), "Flashlight") != backpack.end()) {  
      cout << endl;  
      cout << "You use your flashlight to illuminate the room. You find an old key on the floor!" << endl;  
      addItem("key");  
   } else {  
      cout << endl;  
      cout << "It's too dark to see anything. You hear strange noises and decide to leave before it's too late." << endl;  
      takeScaryDamage(10, 10); // Player takes damage due to a scary encounter in the dark  
      cout << endl;  
   }  
   enterHouseChoice();  
}  
  
void goUpstairsChoice() {  
   cout << endl;  
   cout << "The stairs creak as you ascend. You find a long hallway with a rickety ladder and a locked attic hatch." << endl;  
   cout << endl;  
   if (find(backpack.begin(), backpack.end(), "key") != backpack.end()) {  
      atticChoice();
   } else {  
      cout << "The door is locked. You need to find a key first." << endl;  
      cout << endl;  
      lookAroundChoice();  
   }  
}  
  
void lookAroundChoice() {  
   cout << "You search the room and notice a hidden compartment behind an old painting." << endl;  
   cout << endl;  
   solvePuzzle();  
}  
  
void solvePuzzle() {  
   cout << "Solve this riddle to open the compartment: What comes once in a minute, twice in a moment, but never in a thousand years?" << endl;  
   string answer;  
   cin >> answer;  
   if (answer == "m" || answer == "M") {  
      cout << "Correct! You find a key inside the compartment." << endl;  
      addItem("key");  
      cout << endl;  
   } else {  
      cout << "Wrong answer. You hear footsteps approaching and take 10 damage." << endl;  
      takeScaryDamage(10, 10);  
      cout << endl;  
   }  
   enterHouseChoice();
}
void display_ascii_art() {
    cout << "        .-. " << endl;
    cout << "       (o o) Boo!" << endl;
    cout << "       | O \\ " << endl;
    cout << "        \\   \\ " << endl;
    cout << "         ~~~' " << endl;
    cout << "A ghostly figure appears momentarily, then vanishes..." << endl;
}