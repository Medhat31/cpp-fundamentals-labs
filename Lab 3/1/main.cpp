#include <iostream>
#define SIZE 5
using namespace std;
int main()
{
    int arr[SIZE];
    for(int i = 0; i<SIZE; i++){
        cout << "Enter Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int min = arr[0], max = arr[0];
    for(int i = 0; i < SIZE; i++){
        if(arr[i] > max){
            max = arr[i];
        }

        if(arr[i] < min){
            min = arr[i];
        }
    }

    cout << "Max = " << max << "\nMin = " << min;
    return 0;
}
