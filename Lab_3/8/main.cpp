#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string str;
    int len = 0;
    cout << "Enter a String : ";
    getline(cin, str);
    while(str[len] != '\0'){
        len++;
    }
    cout << len;
    return 0;
}
