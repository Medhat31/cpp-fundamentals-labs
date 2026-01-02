#include <iostream>
using namespace std;

struct Emp_Struct {
int ID;
char Name[40];
int Salary;
int Bonus;
int Deduction;
};

int main()
{
 Emp_Struct emp1;
 cout << "Enter Employee Information : \nID : ";
 cin >> emp1.ID;
 cin.ignore();
 cout << "Name : ";
 cin.getline(emp1.Name, 40);
 cout << "Salary : ";
 cin >> emp1.Salary;
 cout << "Bonus : ";
 cin >> emp1.Bonus;
 cout << "Deduction : ";
 cin >> emp1.Deduction;

 cout << "Employee Code : " << emp1.ID << "\nName : " << emp1.Name << "\nSalary : " << emp1.Salary;

    return 0;
}
