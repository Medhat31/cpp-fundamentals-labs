/*
2) Function Overloading:
========================
class myTestClass
{
	// Function Add: Add 2 integer numbers:  int Add(int, int)
	// Function Add: Add 3 integer numbers:  int Add(int, int, int)
        // Function Add: Add 3 characters  // concatenate them: void Add(char c1, char c2, char ch)
	// Function Add: Add 2 Strings  // concatenate them: void Add(char* str1, char* str2)
}
*/

#include <iostream>
#include <string.h>
using namespace std;

class myTestClass{
public:
    int Add(int a, int b){
        return a + b;
    }

    int Add(int a, int b, int c){
        return a + b + c;
    }

    void Add(char c1, char c2, char ch){
        string str = "";
        str += c1;
        str += c2;
        str += ch;
        cout<< "Characters after Concatenation : " << str;
    }

//  Here We Can use strcat() function as well
    void Add(char* str1, char* str2){
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        for(int i = 0; i < len2; i++){
            str1[len1 + i] = str2[i];
        }
        str1[len1 + len2] = '\0';
        cout << "Strings After Concatenation : " << str1;
    }
};

int main()
{

    myTestClass O1;
    char str1[50] = "Medhat";
    char str2[30] = "Osama";

    cout << O1.Add(1, 2) << endl;
    cout << O1.Add(1, 2, 3)<< endl;
   O1.Add('a', 'b', 'c');
    O1.Add(str1, str2);

    return 0;
}
