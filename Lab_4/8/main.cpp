#include <iostream>
using namespace std;

struct Dept{
    int ID;
    char Name[30];
    struct Emp{
        int ID;
        char Name[50];
        int Salary;
        int Bonus;
    }emp1;
};

int main()
{
   Dept dept1;
    cout << "Enter Department Data : \n";
    cout << "Department ID : ";
    cin >> dept1.ID;
    cin.ignore();
    cout << "Department Name : ";
    cin.getline(dept1.Name, 30);
    cout << "Enter Employee Data : \n";
    cout << "Emp ID : ";
    cin >> dept1.emp1.ID;
    cout << "Name : ";
    cin.ignore();
    cin.getline(dept1.emp1.Name, 50);
    cout << "Salary : ";
    cin >> dept1.emp1.Salary;
    cout << "Bonus : ";
    cin >> dept1.emp1.Bonus;

    cout << "=======================================\n";
    cout << "Department Data : \nDepartment ID : " << dept1.ID
         << "\nDepartment Name : " << dept1.Name
         << "\n---------------------------------\nEmployee Data : \n"
         << "Employee ID : " << dept1.emp1.ID
         << "\nName : " << dept1.emp1.Name
         << "\nSalary : " << dept1.emp1.Salary
         << "\nBonus : " << dept1.emp1.Bonus;

    return 0;
}
