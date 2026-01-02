#include <iostream>
#include <MyLibrary.h>
#include <conio.h>
using namespace std;

int main()
{
    int cur = 0;
    bool exitFlag = 0;
    int ch;
    char menu[6][15] = {"New", "Display", "Display All", "Delete", "Delete All", "Exit"};
    clrscr();
    textattr(0x07);

    while(exitFlag == 0){

        for(int i = 0; i < 5; i++){
            if(cur == i){
                textattr(0x70);
            }else{
                textattr(0x07);
            }
            gotoxy(50, i * 2 + 10);
            cout << menu[i];
        }
        ch = getch();
        switch(ch){
            // Extended Characters
    case -32 :
            int ch = _getch();
            switch(ch){
        case 72:   // Up
            cur--;
            if(cur < 0) cur = 5;
            break;

        case 80: // Down
            cur++;
            if(cur > 5) cur = 0;
            break;

        case 71: // Home
            cur = 0;
            break;

        case 79: // End
            cur = 5;
            break;
            }



        }
    }

    return 0;
}
