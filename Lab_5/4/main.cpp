#include <iostream>
#include <conio.h>
#include <MyLibrary.h>
#include <string>
using namespace std;

#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define HOME 71
#define END 79

#define ESC 27
#define ENTER 13
#define BACKSPACE 8

int main()
{
    string str = "";
    size_t cur = 0;
    int ch;

    while (true) {

        clrscr();
        cout << str << "\n";
    // Changing Position of Cursor
    for(int i = 0; i < cur; i++){
       cout << " ";
    }
    cout << "^";
        ch = getch();
        if (ch == 224 || ch == 0 || ch == -32) {
            ch = getch();

            switch (ch) {
            case LEFT_ARROW:
                if (cur > 0) cur--;
                break;

            case RIGHT_ARROW:
                if (cur < str.size()) cur++;
                break;

            case HOME:
                cur = 0;
                break;

            case END:
                cur = str.size();
                break;
            }
        }
        else if (ch == ESC) {
            break;
        }
        else if (ch == BACKSPACE) {
            if (cur > 0) {
                str.erase(cur - 1, 1);
                cur--;
            }
        }else if(ch == ENTER){
            cout << "\nThe Text You Entered Is : " << str;
            break;
        } else {
            str.insert(str.begin() + cur, (char)ch);
            cur++;
        }
    }

    return 0;
}
