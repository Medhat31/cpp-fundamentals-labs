#include <iostream>
using namespace std;

class GeoShape{
protected:
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

class Square : protected GeoShape{

public:
//  Constructors
    Square(int X) : GeoShape(X){}

    void setDim(int D){
        dim1 = dim2 = D;
    }

    int getDim(){
        return dim1;
    }

    int CalcArea(){
        return getDim() * getDim();
    }
};

class Circle : protected GeoShape{

public:
//  Constructors
    Circle(int R) : GeoShape(R){}

//  Member Methods

    void setRadius(int R){
        dim1 = dim2 = R;
    }

    int getRadius(){
        return dim1;
    }

    int CalcArea(){
        return 3.14 * getRadius() * getRadius();
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
    Circle C(2);
//    C.setDim2(5);   // Error
    cout << C.CalcArea() << endl;

    Square S(7);
    S.setDim(5);
//    S.setDim2(3);   // Error
    cout << S.CalcArea();
    return 0;
}
