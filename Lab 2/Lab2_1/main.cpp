#include <iostream>

using namespace std;

int main()
{
    int sum = 0, num;
    while(sum <= 100){
        cout << "Enter a Number : ";
        cin >> num;
        sum += num;
    }
    cout << "Program Finished";
    return 0;
}
