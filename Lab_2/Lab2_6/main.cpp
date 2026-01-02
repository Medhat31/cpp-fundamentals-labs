#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "Enter a Character : ";
    cin >> ch;
    if((ch >= 'a' || ch >= 'A') && (ch <= 'z' || ch <= 'Z')){
        cout << ch << " is an alphabet";
    }else{
        cout << ch << " is not an alphabet";
    }

    return 0;
}
