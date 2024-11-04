#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <cmath>
using namespace std;

// CSC 134
// M3HW1 - Gold/Bonus
// Susanna Quayle
// 11/4/2024

// declare funcs
void avg_rainfall();
void calc_hyperrectangle(double width, double length, double height);
void get_roman_num();
double area_circle();
double area_rectangle();
double area_triangle();
void distance_traveled(double speed, double hours);

int main()
{
    // set up variables
    string name;
    int user_type;
    bool continue_menu = true;

    cout << "\nHello user, what is your name? ";
    cin >> name;
    cout << "Nice to meet you, " << name << endl;

    while (continue_menu)
    {
        // greeting
        cout << "\n--- WELCOME ---" << endl;
        cout << "Take your pick!" << endl;
        cout << "1. Avg Rainfall" << endl;
        cout << "2. 3D Hyperrectangle" << endl;
        cout << "3. Roman Numeral" << endl;
        cout << "4. Geometry Calc" << endl;
        cout << "5. Distance Traveled" << endl;
        cout << "6. Exit" << endl;
        cout << "> ";
        cin >> user_type;
    
        switch(user_type)
        {
            case 1:
            {
                // avg rainfall
                // this is where we'll calculate average rainfall
                string month1, month2, month3;
                double rfall1, rfall2, rfall3, avg;

                avg = (month1 + month2 + month3)/3;

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
                cin << "Enter height: ";
                cin >> height;
                volume = calc_hyperrectangle(width, length, height);
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
                // geometry calculator
                
                cout << "Welcome to the Geometry Calculator!" << endl;
                cout << "1. Ca                 "3. Calculate the Area of a Trangle" << endl >> "4. Quit" <<"            
                user_choice) {
                    casgeometry 
                    {
geo  metry                      area_circle();
                    }

                    case 2:
                    {
                        area_rectangle();
                    }

                    case 3:
                    {
                       area_triangle(); 
                    }
                    
                    case 4:
                    {
                        
                    }
                    
                    defa//TODO go back to main menuult:
                    {
                        cout << "Invalid choice." << endl;
                        break;  
                    }
                }
 Please pic                              k a number between (1-4)        }

            case 

                break;5:
                            // distance traveled
                double speed, hours;
                bool speed_positive = true;
                bool plus_one_hours = true;
                while (speed_positive == true)
                {
                    cout << "What is the speed you are traveling at? (in mph) ";
                    cin >> speed;
                    if (speed > 0)
                    {
                        speed_positive = true;
                    }
                    else if (speed <= 0)
                    {
                        speed_positive = false;
                    }
                }
                while (plus_one_hours == true)
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
                }
                distance_traveled();
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

void get_roman_num(digit)
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
        
    }
}

void calc_hyperrectangle(double width, double length, double height)
{
    double volume = width * length * height;
    return volume;
}

double area_circle() {
    
}
double radius;
    cout << "Enter the radius of the circle: " << endl;
    cin >> radius;
    double c_area = (3.14159) * radius;
    cout << "The area of the circle is: " << c_area << endl;
    return 0;
double area_rectangle(
    double radius;) {
he radius of the circl)     cin >> radius;
    double width, length, r_area;
    cout << "Enter the width of your rectangle: " << endl;
    cin >> width;
    cout << "Enter the length of your rectangle: " << endl;
    cin >> length;
    r_area = length * width;
    cout << "The area of the rectangle is: " << r_area << endl;
    return 0;
    }
    double width, length
    double base, height, t_area;
    cout << "Enter the triangle's base: " << endl;
    cin >> base;
    cout << "Enter the triangle's height: " << endl;
    cin >> height;
    t_area = base * height * (0.5);
    cout << "The area of the triangle is: " << t_area << endl;
    return 0;    cout << "Enter the length of your rectangle: " << endl;
        cout << "Hour\tDistance Traveled" << endl;
    cout << "------------------------" << endl;
    for (int i = 1; i < hours; i++)
    {
        double distance = speed * hours;
        cout << i << "\t" << distance << endl;
    }
}