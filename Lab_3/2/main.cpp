#include <iostream>
#define ROW 3
#define COL 4
using namespace std;

int main()
{
    float arr[ROW][COL] = {{1,2,3,4},
                         {4,6,7,8},
                         {9,10,11,12}}, sum;

    cout << "Sum of each row : \n";
    for(int i = 0; i < ROW; i++){
        sum = 0;
        for(int j = 0; j < COL; j++){
        sum += arr[i][j];
        }
        cout << "Sum of Row " << i + 1 << " = " << sum << "\n";
    }
        cout << "\n\nAverage of Each Column : \n";

        for(int j = 0; j < COL; j++){
            sum = 0;
            for(int i = 0; i < ROW; i++){
            sum += arr[i][j];
            }
            cout << "Average of Column " << j + 1 << " = " << sum / ROW << "\n";
        }
    return 0;
}
