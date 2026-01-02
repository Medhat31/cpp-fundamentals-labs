#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string inStr;
    cout << "Enter a String : ";
    getline(cin, inStr);
    string newStr;
    for(int i = 0; i <= inStr.length(); i++){
        if(((inStr[i] >= 'a' || inStr[i] >= 'A') && (inStr[i] <= 'z' || inStr[i] <= 'Z') || inStr[i] == ' ')){
            newStr += inStr[i];
        }
    }
    cout << newStr;
    return 0;
}
