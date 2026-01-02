#include <iostream>
using namespace std;
int power(int num, int pow);

int main()
{
    int num, pow;
    cout << "Enter the Number Then Power";
    cin >> num >> pow;
    int result = power(num, pow);
   cout << num << " ^ " << pow << " = " << result;

    return 0;
}

int power(int num, int pow){
if(pow == 0) return 1;
return num * power(num, pow - 1);
}
