/*
Multiline Editor "delete, backspace, upArrow, downArrow,
pgUp (first char in the page), pgDown (last char in the page),
Enter (for new line), Esc (to print the whole lines)"...
*/

#include <iostream>
#include <conio.h>
#include <MyLibrary.h>

using namespace std;

// Definitions
// Extended Keys
#define RIGHT_ARROW 77
#define LEFT_ARROW 75
#define HOME 71
#define END 79
#define DELETE 83

// Normal Keys
#define ESC 27
#define ENTER 13
#define BACKSPACE 8


// Function Prototypes
void insertCharacter(char* arr, int Size, int cursor, char character);
void deleteCharacter(char* arr, int Size, int cursor, char character);

int main()
{
    int curX = 0,curY = 0 , flag = 1, ch, Size;
    cout << "Enter Line Width : ";
    cin >> Size;
    char* str = (char*)malloc(Size * sizeof(char));
    str[0] = '\0';
    while(flag == 1){
            clrscr();
            cout << str << endl;
            for(int i = 0; i < cur; i++){
                cout << " ";
            }
            cout << "^";
        ch = getch();
        if(ch == -32 || ch == 0 || ch == 224){
            ch = _getch();
            switch(ch){
            case RIGHT_ARROW:
                if(cur < strlen(str)){
                    curX++;
                }
                break;

            case LEFT_ARROW:
                if(cur > 0){
                    curX--;
                }
                break;

            case HOME:
                curX = 0;
                curY = 0
                break;

            case END:
                cur = strlen(str);
                break;
            case DELETE:
                deleteCharacter(str, Size, cur, char(ch));
                cur--;
                break;
            }
        }else{
            switch(ch){
        case ESC:
            flag = 0;
            break;

        case ENTER:
            cout << "\nString is : " << str;
            flag = 0;
            break;


        case BACKSPACE:
            deleteCharacter(str, Size, cur, char(ch));
            cur--;
            break;

        default:
            insertCharacter(str, Size, cur, (char)ch);
            cur++;
            }
        }
    }
     free(str);
    return 0;
}

void insertCharacter(char* arr, int Size, int cursor, char character){

    if(strlen(arr) > Size - 1) return;
    for(int i = strlen(arr); i >= cursor; i--){
        arr[i+1] = arr[i];
        if(cursor == Size + 1){
            break;
        }
    }
    arr[cursor] = character;
  ;
}

void deleteCharacter(char* arr, int Size, int cursor, char character){
    arr[cursor] = ' ';
    for(int i = cursor; i < strlen(arr); i++){
        arr[i] = arr[i + 1];
    }
}

