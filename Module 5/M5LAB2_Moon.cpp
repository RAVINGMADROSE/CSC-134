// CSC134
// M5LAB2 - Complete a Program
// Madison Moon
// 11/03/24

#include <iostream>
using namespace std;

// Declare (Write the prototypes for)
// the getLength,
// getWidth, getArea, and displayData
// functions here.
double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double length, double width, double area);

int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
    double length;    // The rectangle's length
    double width;     // The rectangle's width
    double area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}

//***************************************************
// TODO: write the getLength, getWidth, getArea,    *
// and displayData functions below.                 *
//***************************************************

double getLength() {
double length;
cout << "What is the length? ";
cin >> length;
return length;
}

double getWidth() {
double width;
cout << "What is the width? ";
cin >> width;
return width;
}

double getArea(double length, double width) {
return length * width;
}

void displayData(double length, double width, double area) {
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Area: " << area << endl;
}