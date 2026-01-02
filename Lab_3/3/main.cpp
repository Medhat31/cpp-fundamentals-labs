#include <iostream>
#define ROW 3
#define COL 3
using namespace std;

int main()
{
    int mat1[ROW][COL] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int mat2[ROW][COL] = {{10,11,12}, {13,14,15}, {16,17,18}};
    int mat3[ROW][COL];

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cout << mat3[i][j] << "\t";
        }
        cout << "\n\n";
    }

    return 0;
}
