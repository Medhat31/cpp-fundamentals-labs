// try to return fixed Array first, see what happened.
#include <iostream>
using namespace std;

int* incrementArray();

int main()
{
    int* arrPtr = incrementArray();
   cout << "Array After Incrementation : ";
   for(int i = 0; i < 3; i++){
    cout << arrPtr[i] << endl;
   }

    return 0;
}

int* incrementArray(){
    int arr[3];
    cout << "Enter Array Elements : \n";
    for(int i = 0; i < 3; i++){
        cout << "Element " << i + 1 << " : ";
        cin >> arr[i];
    }
    for(int i = 0; i < 3; i++){
        arr[i] += 5;
    }
    return arr;
}


