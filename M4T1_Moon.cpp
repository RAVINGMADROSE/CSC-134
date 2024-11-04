// CSC 134
// M4T1 - basic loops
// Madison Moon
// 9/30/24
#include <iostream>

using namespace std;

// updated to use multiple functions

void q1 ();
void q2 ();
int main()
{
    q1();
    q2();
    return 0;
}

    //QUESTION 1
void q1 (){
    cout << "M4T1" << endl;
    // part 1 - simple loop
    cout << "Simple loop" << endl;
    int num = 1;
    while (num <= 5) {
        cout << "num = " << num << endl;
        num++;
    }
    cout << "Finished" << endl;
   return;
}
//QUESTION 2
   void q2() {

    // part 2 - numbers and squares
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 10;
    //header
    cout << endl;
    cout << "Number\t\tNumber Squared" << endl;
    cout << "-------------------------------------" << endl;
    int num = MIN_NUMBER;
    while (num <= MAX_NUMBER) {
        cout << num << "\t\t" << num*num << endl;
        num++;
    }
        return;
}
