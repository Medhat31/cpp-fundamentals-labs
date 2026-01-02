/*
Complex Class:

	- member data: real , img
	- member functions: setters & getters
	- Standalone functions:
		Complex Add(Complex C1, Complex C2);
		Complex Subtract(Complex C1, Complex C2);
		void print(Complex C);   // C = 5+3i

	- try to re-write Add function to be member function:
		Complex Add(Complex C);


	- Check different cases of print:

		real = 5, img = 3  // C1 = 5+3i

		real = 5, img = -3  // C1 = 5 + -3i   ==> C1 = 5-3i

		real = 5, img = 0  // C1 = 5 + 0i   ==> C1 = 5

		real = 0, img = 3  // C1 = 0 + 3i   ==> C1 = 3i

		real = 0, img = 0  // C1 = 0 + 0i   ==> C1 = 0

*/

#include <iostream>
using namespace std;

class Complex{
private:
    int real;
    int img;

public:
//  Setters
    void setReal(int R){
    real = R;
    }
    void setImg(int I){
    img = I;
    }
// Getters
    int getReal(){
        return real;
    }
    int getImg(){
        return img;
    }

// Other Methods :
Complex Add(Complex C){
    Complex Result;
    Result.real = real + C.real;
    Result.img = img + C.img;
    return Result;
}

};

Complex Add(Complex C1, Complex C2){
    Complex C;
    C.setReal(C1.getReal() + C2.getReal());
    C.setImg(C1.getImg() + C2.getImg());
    return C;
}

Complex Subtract(Complex C1, Complex C2){
    Complex C;
    C.setReal(C1.getReal() - C2.getReal());
    C.setImg(C1.getImg() - C2.getImg());
    return C;
}

Complex Print(Complex C){
    if(C.getImg() < 0 && C.getReal() != 0){
        cout << "\nComplex Number = " << C.getReal() << " - " << abs(C.getImg()) << "i \n";
    }else if(C.getImg() == 0){
        cout << "\nComplex Number = " << C.getReal();
    }else if (C.getReal() == 0){
         cout << "\nComplex Number = " << C.getImg() << "i \n";
    }else{
         cout << "\nComplex Number = " << C.getReal() << " + " << C.getImg() << "i \n";
    }
}

int main()
{
    Complex c1, c2, Result;
    int Real1, Img1, Real2, Img2;
    cout << "Enter the First Complex Number : \nReal : ";
    cin >> Real1;
    cout << "Imaginary : ";
    cin >> Img1;
//    cout << "Enter the Second Complex Number : \nReal : ";
//    cin >> Real2;
//    cout << "Imaginary : ";
//    cin >> Img2;
    c1.setReal(Real1);
    c1.setImg(Img1);
//    c2.setReal(Real2);
//    c2.setImg(Img2);

//   Testing the Print Function :
    cout << "C1 : ";
    Print(c1);

//   Testing the Add member Function :
//    Result = c1.Add(c2);
//    Print(Result);

// Testing Standalone Functions :
//    cout << "======================================\nAddition : ";
//    Complex addResult = Add(c1, c2);
//    Print(addResult);
//
//    cout << "\nSubtraction : ";
//    Complex subResult = Subtract(c1, c2);
//    Print(subResult);


    return 0;
}
