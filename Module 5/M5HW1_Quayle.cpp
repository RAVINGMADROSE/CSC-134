#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <cmath>
using namespace std;

// CSC 134
// M3HW1 - Gold/Bonus
// Susanna Quayle, Leeanna Coleman, Madison Moon
// 11/4/2024

// declare funcs
void avg_rainfall();
double calc_hyperrectangle(double width, double length, double height);
void get_roman_num(int digit);
double area_circle();
double area_rectangle();
double area_triangle();
bool distance_traveled(double speed, double hours);

int main()
{
    // set up variables
    string name;
    int user_type;
    bool continue_menu = true;

    cout << "\nHello user, what is your name? ";
    cin >> name;
    cout << "\nNice to meet you, " << name << endl;

    while (continue_menu)
    {
        // greeting
        cout << "\n--- WELCOME ---" << endl;
        cout << "Take your pick!" << endl;
        cout << "1. Avg Rainfall" << endl;
        cout << "2. 3D Hyperrectangle" << endl;
        cout << "3. Roman Numeral" << endl;
        cout << "4. Geometry Calculator" << endl;
        cout << "5. Distance Traveled" << endl;
        cout << "6. Exit" << endl;
        cout << "> ";
        cin >> user_type;
    
        switch(user_type)
        {
            case 1:
            {
                string month1, month2, month3;
                double rfall1, rfall2, rfall3, avg;

                cout << "Enter month: ";
                cin >> month1;
                cout << "Enter rainfall for " << month1 << ": ";
                cin >> rfall1;
                cout << "Enter month: ";
                cin >> month2;
                cout << "Enter rainfall for " << month2 << ": ";
                cin >> rfall2;
                cout << "Enter month: ";
                cin >> month3;
                cout << "Enter rainfall for " << month3 << ": ";
                cin >> rfall3;

                avg = (rfall1 + rfall2 + rfall3)/3;

                cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is " << avg << endl;

                break;
            }
            
            case 2:
            {
                // 3d hyperrectangle
                cout << "Calculate a 3D Hyperrectangle (i.e. just a cube)" << endl;
                double width, length, height, volume;
                cout << "Enter width: ";
                cin >> width;
                cout << "Enter length: ";
                cin >> length;
                cout << "Enter height: ";
                cin >> height;
                volume = calc_hyperrectangle(width, length, height);
                cout << "The volume of your hyperrectangle is: " << volume << endl;
                break;
            }

            case 3:
            {
                // roman numeral
                int digit;
                cout << "Get a roman numeral" << endl;
                cout << "Enter a number (1-10): ";
                cin >> digit;
                get_roman_num(digit);
                break;
            }

            case 4:
            {
                // Geometry Calculator
                bool geometry_menu = true;
                int geometry_choice;
                while (geometry_menu) {
                cout << "Welcome to the Geometry Calculator!" << endl;
                cout << "1. Calculate the Area of a Circle" << endl;
                cout << "2. Calculate the Area of a Rectangle" << endl;
                cout << "3. Calculate the Area of a Triangle" << endl;
                cout << "4. Quit" << endl;
                cout << "Enter your choice (1-4): ";
                cin >> geometry_choice;
                
                switch(geometry_choice) {
                    case 1: {
                        area_circle();
                        break;
                    }
                    
                    case 2: {
                        area_rectangle();
                        break;
                    }

                    case 3: {
                        area_triangle();
                        break;
                    }

                    case 4: {
                        cout << "Thank you for using Geometry Calculator. Goodbye!" << endl;
                        geometry_menu = false;
                        break;
                    }

                    default: {
                        cout << "Invalid choice. Please choose a number between 1-4." << endl;
                        break;
                    }

                }

                }
                break;
            }

            case 5:
            {
                // distance traveled
                double speed, hours;
                bool speed_positive = true;
                bool plus_one_hours = true;
                cout << "\nWhat is the speed you are traveling at? (in mph) ";
                cin >> speed;
                if (speed > 0)
                {
                    speed_positive = true;
                }
                else if (speed <= 0)
                {
                    speed_positive = false;
                }
                while (speed_positive == true)
                {
                    cout << "How many hours are you traveling? ";
                    cin >> hours;
                    if (speed > 1)
                    {
                        plus_one_hours = true;
                    }
                    else if (speed <= 1)
                    {
                        plus_one_hours = false;
                    }
                    distance_traveled(speed, hours);
                    speed_positive = false;
                }
                break;
            }

            case 6:
            {
                continue_menu = false;
                cout << "Have a good day, bye!" << endl;
                break;
            }

            default:
            {
                cout << "Invalid choice." << endl;
                break;
            }
        }
    }
}

void get_roman_num(int digit)
{
    switch(digit)
    {
            case 1:
            {
                cout << "The Roman numeral version of " << digit << " is I" << endl;
                break;
            }
            
            case 2:
            {
                cout << "The Roman numeral version of " << digit << " is II" << endl;
                break;
            }

            case 3:
            {
                cout << "The Roman numeral version of " << digit << " is III" << endl;
                break;
            }

            case 4:
            {
                cout << "The Roman numeral version of " << digit << " is IV" << endl;
                break;
            }

            case 5:
            {
                cout << "The Roman numeral version of " << digit << " is V" << endl;
                break;
            }

            case 6:
            {
                cout << "The Roman numeral version of " << digit << " is VI" << endl;
                break;
            }

            case 7:
            {
                cout << "The Roman numeral version of " << digit << " is VII" << endl;
                break;
            }
            
            case 8:
            {
                cout << "The Roman numeral version of " << digit << " is VIII" << endl;
                break;
            }

            case 9:
            {
                cout << "The Roman numeral version of " << digit << " is IX" << endl;
                break;
            }

            case 10:
            {
                cout << "The Roman numeral version of " << digit << " is X" << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Please choose a number between 1-10." << endl;
                break;
            }
    }
}

double calc_hyperrectangle(double width, double length, double height)
{
    if (length > 0 && width > 0 && height > 0) {
        double volume = width * length * height;
        return volume;
    }
    else {
        cout << "Input is invalid. Only enter positive values for length and width." << endl;
    }
}

double area_circle() 
{
    double radius;
    double c_area;
    cout << "Enter the radius of your circle: " << endl;
    cin >> radius;
    if (radius >= 0) {
        c_area = radius * radius * (3.14159);
        cout << "The area of your circle is " << c_area << "." << endl;
    }
    else {
        cout << "Input is invalid. The radius cannot be less than zero." << endl;
    }
    return 0;
}

double area_rectangle() 
{
    double length;
    double width;
    double r_area;
    cout << "Enter the length of your rectangle: " << endl;
    cin >> length;
    cout << "Enter the width of your rectangle: " << endl;
    cin >> width;
    if (length > 0 && width > 0) {
        r_area = length * width;
        cout << "The area of your rectangle is " << r_area << "." << endl;
    }
    else {
        cout << "Input is invalid. Only enter positive values for length and width." << endl;
    }
    return 0;
}

double area_triangle() 
{
    double base;
    double height;
    double t_area;
    cout << "Enter the base of your triangle: " << endl;
    cin >> base;
    cout << "Enter the height of your triangle: " << endl;
    cin >> height;
    if (base > 0 && height > 0) {
        t_area = base * height * (0.5);
        cout << "The area of your triangle is " << t_area << "." << endl;
    }
    else {
        cout << "Input is invalid. Only enter positive values for base and height." << endl;
    }
    return 0;
}

bool distance_traveled(double speed, double hours)
{
    bool speed_positive = true;
    cout << "Hour\tDistance Traveled" << endl;
    cout << "------------------------" << endl;
    for (int i = 1; i <= hours; i++)
    {
        double distance = speed * i;
        cout << i << "\t" << distance << endl;
    }
    return speed_positive = false;
}