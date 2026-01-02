#include <iostream>
using namespace std;
int returnLargest(int, int, int);

int main()
{
    int x, y, z;
    cout << "Enter 3 Numbers : ";
    cin >> x >> y >> z;
    int largest = returnLargest(x, z, y);
    cout << "Largest = " << largest;
    return 0;
}

int returnLargest(int x, int y, int z){
    if(x > y && x > z){
        return x;
    }else if (y > x && y > z){
        return y;
    }else if (z > x && z > y){
        return z;
    }
}
