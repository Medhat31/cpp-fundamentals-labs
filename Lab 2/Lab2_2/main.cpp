#include <iostream>

using namespace std;

int main()
{
    int choice;
    cout << "Choose Your Meal : \n 1) Rice \n 2) Chicken \n 3) Meat \n";
    cin >> choice;
    if(choice == 1){
        cout << "Rice";
    }else if(choice == 2){
         cout << "Chicken";
    }else if(choice == 3){
         cout << "Meat";
    }
    return 0;
}
