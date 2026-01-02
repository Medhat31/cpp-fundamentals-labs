#include <iostream>
using namespace std;
int SUM(int x = 0, int y = 0, int z = 0);

int main()
{
    cout << SUM(1) << endl;
    cout << SUM(1, 2) << endl;
    cout << SUM(1, 2, 3);
    return 0;
}

int SUM(int x, int y, int z){
    return x + y + z;
}

