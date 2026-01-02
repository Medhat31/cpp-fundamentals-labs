/*
1) Class Complex:
=================
	- member variables(real, img)
	- constructors(default, parameterized)
	- setters & getters
	- member functions: "Addcomplex, subComplex, PrintComplex"  (use scope operator "::")
	- destructor
	- use "this" as much as you can


try this main, count No of constructors vs No of destructors:

void main()
{
	Complex C1(3,4), C2(5), C3;
	C3 = C1.Addcopmlex(C2);
}

*/
#include <iostream>
using namespace std;

class Complex{
private:
    int real;
    int img;

public:
// Constructors :
    Complex(){
        this->real = this->img = 0;
        cout << "\nConstructor\n";
    }

    Complex(int R, int I){
        this->real = R;
        this->img = I;
        cout << "\nConstructor\n";
    }

    Complex(int num){
        this->real = this->img = num;
        cout << "\nConstructor\n";
    }

//  Setters & Getters
    void setReal(int r){
        this->real = r;
    }


    void setImg(int i){
        this->img = i;
    }

    int getReal(){
        return this->real;
    }


    int getImg(){
        return this->img;
    }
    Complex addComplex(Complex C);
    Complex subComplex(Complex C);
    void printComplex();

//  Destructor
    ~Complex(){
        cout << "\nDestructor\n";
    }

};

// Member Functions :

Complex Complex :: addComplex(Complex C){
    Complex Result;
    Result.real = this->real + C.real;
    Result.img = this->img + C.img;
    return Result;
}

Complex Complex :: subComplex(Complex C){
    Complex Result;
    Result.real = this->real - C.real;
    Result.img = this->img - C.img;
    return Result;
}

 void Complex :: printComplex(){
    if(this->real == 0 ){
        cout << this->img << "i\n";
    }else if(this->img == 0){
        cout << this->real << endl;
    }else if(this->img < 0){
        cout << this->real << " - " << this->img << "i\n";
    }else{
        cout << this->real << " + " << this->img << "i\n";
    }
 }

int main()
{
    Complex C1(3,4), C2(5), C3;
	C3 = C1.addComplex(C2);

	// 5 Constructors, 5 Destructors
    return 0;
}
