#include <iostream>
using namespace std;
// Function Prototypes
void swapByValue(int, int);
void swapByAddress(int*, int*);
void swapByReference(int&, int&);

int main()
{
    int a, b;
    cout << "Enter 2 Values to Swap : \na : ";
    cin >> a;
    cout << "b : ";
    cin >> b;

//    // By Value :
//    cout << "Before Swapping : \na = " << a << "\nb = " << b;
//    swapByValue(a, b);
//    cout << "\nAfter Swapping : \na = " << a << "\nb = " << b;

     // By Address :
//      cout << "Before Swapping : \na = " << a << "\nb = " << b;
//      swapByAddress(&a, &b);
//      cout << "\nAfter Swapping : \na = " << a << "\nb = " << b;

//      // By Reference :
    cout << "Before Swapping : \na = " << a << "\nb = " << b;
    swapByReference(a, b);
    cout << "\nAfter Swapping : \na = " << a << "\nb = " << b;


    return 0;
}

void swapByValue(int a, int b){
int temp = a;
a = b;
b = temp;
}

void swapByAddress(int* a, int* b){
int temp = *a;
*a = *b;
*b = temp;
}

void swapByReference(int& a, int& b){
int temp = a;
a = b;
b = temp;
}
