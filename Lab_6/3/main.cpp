/*
Re-Write day3_Program that calculate sum of student degrees, and average of each subject,
but ask the user for students and subject numbers. (Dynamic Allocation of 2D Array - Pointer to Pointer)
*/
#include <iostream>
using namespace std;

int main()
{
    int studNum, subjNum, sum = 0;
    cout << "Enter Number of Students : ";
    cin >> studNum;
    cout << "Enter Number of Subjects : ";
    cin >> subjNum;

    int** Ptr2Ptr = new int*[studNum];

// Allocating dynamic memory in heap for the ptr2ptr (making the 2D array)
    for(int i = 0; i < studNum; i++){
        Ptr2Ptr[i] = new int[subjNum];
    }



    for(int i = 0; i < studNum; i++){
             cout << "Enter Degrees of Student " << i+1 << " : \n";
        for(int j = 0; j < subjNum; j++){
           cout << "Subject "<< j + 1 << " : ";
//            cin >> Ptr2Ptr[i][j];
              cin >> *(*(Ptr2Ptr + i) + j);
        }
    }

    for(int i = 0; i < studNum; i++){
        for(int j = 0; j < subjNum; j++){
            sum += Ptr2Ptr[i][j];
        }
        cout << "Sum of Degrees of Student " << i + 1 << " = " << sum << endl;
        sum = 0;
    }

    cout << "--------------------------------------------------\n";

    for(int j = 0; j < subjNum; j++){
        for(int i = 0; i < studNum; i++){
                sum += Ptr2Ptr[i][j];
        }
        cout << "Average of Subject " << j + 1 << " = " << sum / studNum << endl;
        sum = 0;
    }

    delete[] Ptr2Ptr;

    return 0;
}
