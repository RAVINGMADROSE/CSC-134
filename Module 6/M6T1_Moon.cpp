// CSC134
// M6T1 - Basic Arrays
// Madison Moon
// 12/01/24

#include <iostream>
using namespace std;

void part1() {
    int total = 0;
    int cars;
    
    cout << "Part 1:\n";
    
    cout << "Enter cars for Monday: ";
    cin >> cars;
    total = total + cars;
    
    cout << "Enter cars for Tuesday: ";
    cin >> cars;
    total = total + cars;
    
    cout << "Enter cars for Wednesday: ";
    cin >> cars;
    total = total + cars;
    
    cout << "Enter cars for Thursday: ";
    cin >> cars;
    total = total + cars;
    
    cout << "Enter cars for Friday: ";
    cin >> cars;
    total = total + cars;
    
    cout << "Total cars: " << total << endl;
    cout << "Average cars per day: " << total / 5.0 << endl;
}

void part2() {
    int cars[5];
    int total = 0;
    
    cout << "\nPart 2:\n";
    
    cout << "Enter cars for Monday: ";
    cin >> cars[0];
    
    cout << "Enter cars for Tuesday: ";
    cin >> cars[1];
    
    cout << "Enter cars for Wednesday: ";
    cin >> cars[2];
    
    cout << "Enter cars for Thursday: ";
    cin >> cars[3];
    
    cout << "Enter cars for Friday: ";
    cin >> cars[4];
    
    total = cars[0] + cars[1] + cars[2] + cars[3] + cars[4];
    
    cout << "Total cars: " << total << endl;
    cout << "Average cars per day: " << total / 5.0 << endl;
    
    cout << "\nTraffic each day:\n";
    cout << "Monday: " << cars[0] << " ";
    for(int i = 0; i < cars[0]/10; i++) {
        cout << "*";
    }
    cout << endl;
    
    cout << "Tuesday: " << cars[1] << " ";
    for(int i = 0; i < cars[1]/10; i++) {
        cout << "*";
    }
    cout << endl;
    
    cout << "Wednesday: " << cars[2] << " ";
    for(int i = 0; i < cars[2]/10; i++) {
        cout << "*";
    }
    cout << endl;
    
    cout << "Thursday: " << cars[3] << " ";
    for(int i = 0; i < cars[3]/10; i++) {
        cout << "*";
    }
    cout << endl;
    
    cout << "Friday: " << cars[4] << " ";
    for(int i = 0; i < cars[4]/10; i++) {
        cout << "*";
    }
    cout << endl;
}

int main() {
    part1();
    part2();
    return 0;
}