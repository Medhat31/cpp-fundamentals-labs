#include <iostream>
#include <MyLibrary.h>
#include <conio.h>


using namespace std;

struct Emp{
    int ID;
    char Name[40];
    int Salary;
    int Bonus;
    int Deduction;
};

// Function Prototypes
void insertNewEmployee(int emp_no, Emp emp[]);
 int arrSize;


int main()
{
    int cur = 0;
    bool exitFlag = 0;
    int ch;
    char menu[6][15] = {"New", "Display", "Display All", "Delete", "Delete All", "Exit"};
    cout << "Enter Employees Array Size : ";
    cin >> arrSize;
    Emp* emp = new Emp[arrSize];
    int* insertedEmployees = new int[arrSize];
    for(int i = 0; i < arrSize; i++){
        insertedEmployees[i] = 0;
        emp[i].ID = 0;
    }
    do {
         textattr(0x07);
         clrscr();
        for(int i = 0; i <= 5; i++){
            if(cur == i){
                textattr(0x70);
            }else{
                textattr(0x07);
            }
            gotoxy(50, i * 2 + 7);
            cout << menu[i];
        }
        ch = getch();

        switch(ch){
// Normal Characters
    case 27:
    clrscr();
    cout << "Goodbye";
    exitFlag = 1;
    break;

    case 13:
    {
        int emp_no;
        int flag = 0;
        switch(cur){
        case 0:  // New
        {
        clrscr();
        cout << "Enter Employee Number : ";
        cin >> emp_no;
        if(emp_no > arrSize || emp_no < 1){
            cout << "Invalid Input";
            break;
        }
            for(int i = 0; i < arrSize; i++){
                if(emp_no == insertedEmployees[i]){
                    flag = 1;
                }
            }

            if(flag == 1){
                cout << "Employee Already Exists";
                flag = 0;
                break;
            }
        insertedEmployees[emp_no] = emp_no;
        insertNewEmployee(emp_no, emp);
        flag = 0;
        break;
        }
        case 1:  // Display
            {
            clrscr();
            int exists = 0;
            cout << "Enter Employee Number : ";
            cin >> emp_no;
            if(emp_no > (arrSize + 1)){
            cout << "Invalid Input";
            break;
            }
            for(int i = 0; i < arrSize; i++){
                if(emp_no == insertedEmployees[i]){
                    flag = 1;
                }
            }

            if(flag == 0 || emp[emp_no - 1].ID == 0){
                cout << "Employee Doesn't Exist";
                break;
            }
            cout << "ID : " << emp[emp_no - 1].ID
                 << "\nName : " << emp[emp_no - 1].Name
                 << "\nSalary : " << emp[emp_no - 1].Salary
                 << "\nBonus : " << emp[emp_no - 1].Bonus
                 << "\nDeduction : " << emp[emp_no - 1].Deduction;
            flag = 0;
        break;
            }

        case 2:  // Display All
            clrscr();
            for(int i = 0; i < arrSize; i++){
                    if(emp[i].ID == 0){
                        continue;
                    }
                cout << "\nEmployee " << i + 1 << " : \n"
                     << "ID : " << emp[i].ID
                     << "\nName : " << emp[i].Name
                     << "\nSalary : " << emp[i].Salary
                     << "\nBonus : " << emp[i].Bonus
                     << "\nDeduction : " << emp[i].Deduction << "\n------------------------------------------";
            }

        break;

        case 3:  // Delete
            clrscr();
            cout << "Enter Employee Number";
            cin >> emp_no;
            if(emp_no > (arrSize + 1) || emp_no < 1){
            cout << "Invalid Input";
            break;
            }
            emp[emp_no - 1].ID = 0;
            insertedEmployees[emp_no - 1] = 0;
            cout << "Employee Deleted Successfully";
        break;

        case 4:  // Delete All
            clrscr();
            for(int i = 0; i < arrSize; i++){
                emp[i].ID = 0;
                insertedEmployees[i] = 0;
            }
            cout << "All Employees Are Deleted";

        break;

        case 5:  // Exit
            textattr(0x07);
            clrscr();
            cout << "Goodbye";
            exitFlag = 1;
        break;
        }

    }
// Extended Characters
    case -32:
    case 0:
    case 224:
            int ch = _getch();
            switch(ch){
        case 72:   // Up
            cur--;
            if(cur < 0) cur = 5;
            break;

        case 80: // Down
            cur++;
            if(cur > 5) cur = 0;
            break;

        case 71: // Home
            cur = 0;
            break;

        case 79: // End
            cur = 5;
            break;
            }
        }
    } while(exitFlag == 0);
    delete[] emp;
    return 0;
}

void insertNewEmployee(int emp_no, Emp emp[]){
        cout << "ID : ";
        cin >> emp[emp_no - 1].ID;
        if(emp[emp_no - 1].ID == 0) {
                cout << "ID Must be Larger than 0 , Enter Another ID : ";
                cin >> emp[emp_no - 1].ID;
        }
        cin.ignore();
        cout << "Name : ";
        cin.getline(emp[emp_no - 1].Name, 40);
        cout << "Salary : ";
        cin >> emp[emp_no - 1].Salary;
        cout << "Bonus : ";
        cin >> emp[emp_no - 1].Bonus;
        cout << "Deduction : ";
        cin >> emp[emp_no - 1].Deduction;
        cout << "Employee Added Successfully !";
}

