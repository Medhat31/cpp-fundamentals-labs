#include <iostream>
using namespace std;

class Complex{
private:
    int real, img;

public:
//  Copy Constructor
    Complex(){
        this->real = this->img = 0;
        cout << "Parameterless Constructor" << endl;
    }

    Complex(int num){
        this->real = this->img = num;
        cout << "Parameterized Constructor (1 Parameter)" << endl;
    }

    Complex(int R, int I){
        this->real = R;
        this->img = I;
        cout << "Parameterized Constructor (2 Parameters)" << endl;
    }

    Complex(const Complex& Comp){
        this->real = Comp.real;
        this->img = Comp.img;
        cout << "Copy Constructor" << endl;
    }

    Complex Add(Complex C);

    ~Complex(){
        cout << "Destructor\n";
    }
};

Complex Complex::Add(Complex C){
    Complex Result;
    Result.real = this->real + C.real;
    Result.img = this->img + C.img;
    return Result;
}

int main()
{
    Complex C1(3,4), C2(5), C3;
    C3 = C1.Add(C2);
    return 0;
}
