// then rerun dynamically allocated array.
#include <iostream>
using namespace std;

int* incrementArray();

int main()
{
    int* arrPtr = incrementArray();
    cout << "\nData After Incrementation : \n";
    for(int i = 0; i < 3; i++){
        cout << "Element " << i + 1 << " : " <<  arrPtr[i] << endl;
    }
    delete[] arrPtr;
    return 0;
}

int* incrementArray(){
    int* arr = new int[3];
// Recieving Data From User :
    cout << "Enter Array Elements : \n";
    for(int i = 0; i < 3; i++){
        cout << "Element " << i + 1 << " : ";
        cin >> arr[i];
    }

// Implementation :
    for(int i = 0; i < 3; i++){
        arr[i] += 5;
    }
    return arr;
}
