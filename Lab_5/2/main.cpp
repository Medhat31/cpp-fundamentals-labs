#include <iostream>

#define SIZE 5
using namespace std;

// Function Prototype
int arrSum(int arr[], int Size);

int main()
{
    int arr[SIZE];
    int* ptr = NULL;
    ptr = arr;
    cout << "Enter Array Elements : \n";
    for(int i = 0; i < SIZE; i++){
        cout << "Element " << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << "==============================\nArray Elements are : \n";
    for (int i = 0; i < SIZE; i++){
        cout << "Element " << i + 1 << " : " << *(ptr + i) <<  "\n";
    }
    int sum = arrSum(arr, SIZE);
    cout << "Sum of Array Elements = " << sum;

    return 0;
}

int arrSum(int arr[], int Size){
    int sum;
    for(int i = 0; i < Size; i++){
        sum += arr[i];
    }
    return sum;
}
