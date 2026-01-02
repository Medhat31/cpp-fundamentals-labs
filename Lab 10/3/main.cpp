#include <iostream>
using namespace std;

class GeoShape{
private:
    int dim1, dim2;

public:

//  Constructors
    GeoShape(){
        dim1 = dim2 = 1;
    }

    GeoShape(int num){
        dim1 = dim2 = num;
    }

    GeoShape(int X, int Y){
        dim1 = X;
        dim2 = Y;
    }

//  Deconstructor
    ~GeoShape(){}

//  Setters & Getters
    void setDim1(int D1){
        dim1 = D1;
    }

    int getDim1(){
        return dim1;
    }

    void setDim2(int D2){
        dim2 = D2;
    }

    int getDim2(){
        return dim2;
    }

    int CalcArea(){
        return 0;
    }
};

class Rectangle : public GeoShape{

public:
//  Constructors
    Rectangle(int X, int Y) : GeoShape(X, Y){}

    int CalcArea(){
        return getDim1() * getDim2();
    }
};

class Square : public GeoShape{

public:
//  Constructors
    Square(int X) : GeoShape(X){}

    int CalcArea(){
        return getDim1() * getDim1();
    }
};

class Circle : public GeoShape{

public:
//  Constructors
    Circle(int R) : GeoShape(R){}

    int CalcArea(){
        return 3.14 * getDim1() * getDim1();
    }
};

class Triangle : public GeoShape{

public:
//  Constructors
    Triangle(int X, int Y) : GeoShape(X, Y){}

    int CalcArea(){
        return 0.5 * getDim1() * getDim2();
    }
};

int main()
{
    Rectangle R(2, 3);
    Circle C(2);
    Square S(2);
    Triangle T(2, 4);
    cout << R.CalcArea() << endl;
     cout << C.CalcArea() << endl;
      cout << S.CalcArea() << endl;
       cout << T.CalcArea() << endl;
    return 0;
}
