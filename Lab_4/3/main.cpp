#include <iostream>
using namespace std;

struct Emp{
    int ID;
    char Name[40];
    int Salary;
    int Bonus;
    int Deduction;
};

int main()
{
    Emp employee[5];
    for(int i = 0; i < 5; i++){
        cout << "Enter Data of Employee " << i + 1 << " : \n";
        cout << "ID : ";
        cin >> employee[i].ID;
        cin.ignore();
        cout << "Name : ";
        cin.getline(employee[i].Name, 40);
        cout << "Salary : ";
        cin >> employee[i].Salary;
        cout << "Bonus : ";
        cin >> employee[i].Bonus;
        cout << "Deduction : ";
        cin >> employee[i].Deduction;
        cout << "\n---------------------------------------------------------------\n";
    }
        cout << "\n================================================================\n";
        cout << "Data of Employees : \n";
    for(int i = 0; i < 5; i++){
        cout << "Data of Employee " << i + 1 << " : \n"
        << "ID : " << employee[i].ID
        << "\nName : " << employee[i].Name
        << "\nSalary : " << employee[i].Salary
        << "\nBonus : " << employee[i].Bonus
        << "\nDeduction : " << employee[i].Deduction;
    }
    return 0;
}
