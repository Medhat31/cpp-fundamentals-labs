#include <iostream>
using namespace std;

// Function Prototype
void Calculate(int x, int y, int* sumPtr, int* subPtr, int* MulPtr, int* divPtr);

int main()
{
    int a, b;
    int sum, sub, mul, div;
    cout << "Enter a & b : \na : ";
    cin >> a;
    cout << "b : ";
    cin >> b;
    Calculate(a, b, &sum, &sub, &mul, &div);
    cout << "Sum =  " << sum << "\nSub = " << sub << "\nMul = " << mul << "\ndiv = " << div;
    return 0;
}

void Calculate(int x, int y, int* sumPtr, int* subPtr, int* MulPtr, int* divPtr){
    *sumPtr = x + y;
    *subPtr = x - y;
    *MulPtr = x * y;
    *divPtr = x / y;
}
