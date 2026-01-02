/*
Try to implement --jagged array-- on Assignment No.4 Using Pointers:
 each student may have number of subjects different than the others.
*/

#include <iostream>
using namespace std;

int main()
{
    int studNum, sum = 0;
    cout << "Enter Number of Students : ";
    cin >> studNum;
    int subjNums[studNum];
    cout << "Enter Number of Subjects for Each Student : \n";
    for(int i = 0; i < studNum; i++){
        cout << "Student " << i + 1 << " : ";
        cin >> subjNums[i];
    }
    int** ptr2ptr = new int*[studNum];

    for(int i = 0; i < studNum; i++){
        ptr2ptr[i] = new int[subjNums[i]];
    }

    cout << "\nEnter Degrees for Each Student : \n";
      for(int i = 0; i < studNum; i++){
            cout << "=======================\nStudent " << i + 1 << " : \n";
        for(int j = 0; j < subjNums[i]; j++){
            cout << "Subject " << j + 1 << " : ";
            cin >> ptr2ptr[i][j];
        }
      }

    for(int i = 0; i < studNum; i++){
        for(int j = 0; j < subjNums[i]; j++){
            sum += ptr2ptr[i][j];
        }
        cout << "Sum of Degrees for Student" << i + 1 << " = " << sum << endl;
        sum = 0;
    }

    cout << "=====================================\n";
    int i;
    for(int j = 0; j < subjNums[i]; j++){
        for(int i = 0; i < studNum; i++){
            sum += ptr2ptr[i][j];
        }
        cout << "Average of Degrees for Subject" << j + 1 << " = " << sum / studNum << endl;
        sum = 0;
    }
    delete[] ptr2ptr;
    return 0;
}
