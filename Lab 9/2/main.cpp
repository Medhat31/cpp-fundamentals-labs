#include <iostream>
#include <math.h>

using namespace std;

int magnitude(int R, int I);

class Complex{
private:
    int real, img;

public:
//  Copy Constructor
    Complex(){
        this->real = this->img = 0;
//        cout << "Parameterless Constructor" << endl;
    }

    Complex(int num){
        this->real = this->img = num;
//        cout << "Parameterized Constructor (1 Parameter)" << endl;
    }

    Complex(int R, int I){
        this->real = R;
        this->img = I;
//        cout << "Parameterized Constructor (2 Parameters)" << endl;
    }

    Complex(const Complex& Comp){
        this->real = Comp.real;
        this->img = Comp.img;
//        cout << "Copy Constructor" << endl;
    }

    int getReal(){
        return this->real;
    }

    int getImg(){
        return this->img;
    }

    void setReal(int R){
        this->real = R;
    }

    void setImg(int I){
        this->img = I;
    }

    Complex Add(Complex C);

    ~Complex(){
//        cout << "Destructor\n";
    }

    void printComplex(){
        if(this->img == 0){
            cout << this->real << endl;
        }else if(this->real == 0){
            cout << this->img << "i" << endl;
        }else if(this->img < 0){
            cout << this->real << " - " << abs(this->img) << "i\n";
        }else{
            cout << this->real << " + " << this->img << "i\n";
        }
    }

//  Operators Overloading

// C3 = C1 - C2;
Complex operator-(const Complex& C){
    Complex Result;
    Result.real = this->real - C.real;
    Result.img = this->img - C.img;
    return Result;
}

// C1 -= C2
Complex operator-=(const Complex& C){
    this->real = this->real - C.real;
    this->img = this->img - C.img;
    return *this;
}

// C1 = --C2
Complex operator--(){
    this->real = this->real - 1;
    this->img = this->img - 1;
    return *this;
}

// C1 = C2--
Complex operator--(int){
    Complex Container = *this;
    this->real = this->real - 1;
    this->img = this->img - 1;
    return Container;
}

// C1 == C2
int operator==(const Complex& C){
    return ((this->real == C.real) && (this->img == C.img));
}

// C1 != C2
int operator!=(const Complex& C){
    return ((this->real != C.real) || (this->img != C.img));
}

// C1 > C2
int operator>(const Complex& C){
    int mag1, mag2;
    mag1 = magnitude(this->real, this->img);
    mag2 = magnitude(C.real, C.img);
    return (mag1 > mag2);
}

// C1 >= C2
int operator>=(const Complex& C){
    int mag1, mag2;
    mag1 = magnitude(this->real, this->img);
    mag2 = magnitude(C.real, C.img);
    return (mag1 >= mag2);
}

// C1 < C2
int operator<(const Complex& C){
    int mag1, mag2;
    mag1 = magnitude(this->real, this->img);
    mag2 = magnitude(C.real, C.img);
    return (mag1 < mag2);
}

// C1 <= C2
int operator<=(const Complex& C){
    int mag1, mag2;
    mag1 = magnitude(this->real, this->img);
    mag2 = magnitude(C.real, C.img);
    return (mag1 <= mag2);
}

operator int() {
    return this->real;
}

int operator[](char ch){
    if(ch == 'R') return this->real;
    else if(ch == 'I') return this->img;
    else return -1;
}

};

// C3 = 7 - C2;
Complex operator-(int num, Complex& C){
    Complex Result;
    Result.setReal(num - C.getReal());
    Result.setImg(-C.getImg());
    return Result;
}

// C3 = C1 - 7;
Complex operator-(Complex& C, int num){
    Complex Result;
    Result.setReal(C.getReal() - num);
    Result.setImg(C.getImg());
    return Result;
}

int magnitude(int R, int I){
    return sqrt(R*R + I*I);
}

int main()
{
    Complex C3, C2(2), C1(4, 5);
    C3 = C1 - C2;
    C3 = 7 - C2;
    C3 = C2 - 7;
    C3.printComplex();

    C1-=C2;
    C1.printComplex();

    C2=--C1;
    C2.printComplex();


    C2 = C1--;
    C2.printComplex();

    cout << (C1 == C2);
    cout << (C1 != C2);
    cout << (C1 > C2);
    cout << (C1 >= C2);
    cout << (C1 < C2);
    cout << (C1 <= C2);
    cout << (int)C1;
    cout << C1['I'];

    return 0;
}
