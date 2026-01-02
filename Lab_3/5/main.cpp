#include <iostream>
#include <MyLibrary.h>
#include <conio.h>
using namespace std;

int main()
{
    string menu[3] = {"New", "Display", "Exit"};
    int current = 0;
    char ch;
    int exitFlag = 0;
    while(1){
        textattr(0x09);
        clrscr();
        for(int i = 0; i < 3; i++){
            if(current == i){
                textattr(0x90);
            }else{
                textattr(0x07);
            }
            gotoxy(50, i*3+7);
            cout << menu[i];
        }

        ch = getch();
        switch(ch){


        case 13:
            switch(current){
            case 0:
                textattr(0x07);
                clrscr();
                cout << "This is a new page";
                 _getch();
                break;

            case 1:
                textattr(0x07);
                clrscr();
                cout << "Display Page";
                _getch();
                break;

            case 2:
                textattr(0x07);
                exitFlag = 1;
                clrscr();
                cout << "Program Ended";
                _getch();
                break;
            }
            break;

        case -32:
        case 0:
        case 224:
            ch = _getch();
            switch(ch){

        case 80:  //  Down Arrow
            current++;
            if(current > 2){
                current = 0;
            }
            break;

        case 72:  //  Up Arrow
            current--;
            if(current < 0){
                current = 2;
            }
            break;

        case 71:   // Home
            current = 0;
            break;

        case 79:   // End
            current = 2;
            break;
        }

    }
    if(ch == 27 || exitFlag == 1){
        clrscr();
        break;
    }
}

    return 0;
}
