#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str;
    char str2[100] = {0};
    string counted;
    int ctr;
    int check = 0;
    cout << "Enter a String : ";
    getline(cin, str);

    for(int i = 0; i < str.length(); i++){
            check = 0;
            for(int c = 0; c < 100; c++){
                if(str[i] == str2[c]){
                    check = 1;
                }
            }
            if(check == 0){
        for(int j = 0; j < str.length(); j++){
            if(str[i] == str[j]){
            ctr++;
            }
        }
    str2[i] = str[i];
        cout << "Frequency of " << str[i] << " = " << ctr << "\n";
        ctr = 0;

        }
    }
    return 0;
}
