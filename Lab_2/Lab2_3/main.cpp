#include <iostream>
#include "C:\Program Files\CodeBlocks\MinGW\include\MyLibrary.h"
using namespace std;
int main()
{
    int num;

    cout << "Enter an Odd Number : ";
    cin >> num;
    if(num % 2 == 0){
        cout << "This is not an odd number";
    }else{
    int row = 1, col = (num + 1)/2;
    cout << endl;
    for(int i = 1; i <= num * num; i++){
            gotoxy(col * 10, row * 2);
            cout << i;
            if(i % num == 0){
                    row++;
                    if (row > num){
                      row = 1;
                    }
                }else {
                row--;
                if (row == 0) row = num;
                col--;
                if (col == 0) col = num;
                }

        }
    }
        return 0;
}
