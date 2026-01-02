#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string sen;
    cout << "Enter a Sentence : ";
    getline(cin, sen);
    int count = 0, wordCount = 1;
    for(int i = 0; i <= sen.length(); i++){
        if(sen[i] == ' '){
            wordCount++;
        }else{
            count++;
        }
    }
    cout << "Number of Letters = " << count << "\nNumber of Words = " << wordCount;
    return 0;
}
