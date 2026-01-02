#include <iostream>
using namespace std;

struct Emp {
int ID;
char Name[40];
int Salary;
int Bonus;
int Deduction;
};

void AddNewEmployee(Emp &employee);
void DisplayEmployee(Emp employee);

int main()
{
    Emp employee1, employee2;
    AddNewEmployee(employee1);
    AddNewEmployee(employee2);
    DisplayEmployee(employee1);
    DisplayEmployee(employee2);

    return 0;
}

void AddNewEmployee(Emp &employee){
    cout << "\nEnter Employee Data : \n";
    cout << "ID : ";
    cin >> employee.ID;
    cin.ignore();
    cout << "Name : ";
    cin.getline(employee.Name, 40);
    cout << "Salary : ";
    cin >> employee.Salary;
    cout << "Bonus : ";
    cin >> employee.Bonus;
    cout << "Deduction : ";
    cin >> employee.Deduction;
}

void DisplayEmployee(Emp employee){
 cout << "\nEmployee's Data : \n";
 cout << "ID : " << employee.ID
      << "\nName : " << employee.Name
      << "\nSalary : " << employee.Salary
      << "\nBonus : " << employee.Deduction << "\n";
}
