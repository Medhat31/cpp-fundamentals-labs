#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a Character : \n";
    ch = getch();
    cout << (int)ch <<"\n";
    if(ch == -32 || ch == 0 || ch == 224){
        cout << "Extended Key \n";
        cout << "ASCII Value = " << _getch();
    }else{
        cout << "Normal Key \n";
        cout << "ASCII Value = " << (int)ch;

    }
    return 0;
}
