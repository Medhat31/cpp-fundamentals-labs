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

    virtual float CalcArea() = 0;
};

class Rectangle : public GeoShape{

public:
//  Constructors
    Rectangle(int X, int Y) : GeoShape(X, Y){}

    float CalcArea(){
        return getDim1() * getDim2();
    }
};

class Square : public GeoShape{

public:
//  Constructors
    Square(int X) : GeoShape(X){}

    void setDim(int D){
        dim1 = dim2 = D;
    }

    int getDim(){
        return dim1;
    }

    float CalcArea(){
        return getDim() * getDim();
    }
};

class Circle : public GeoShape{

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

    float CalcArea(){
        return 3.14 * getRadius() * getRadius();
    }
};

class Triangle : public GeoShape{

public:
//  Constructors
    Triangle(int X, int Y) : GeoShape(X, Y){}

    float CalcArea(){
        return 0.5 * getDim1() * getDim2();
    }
};

float sumOfAllAreas(GeoShape* S1, GeoShape* S2, GeoShape* S3, GeoShape* S4){
    return (*S1).CalcArea() + (*S2).CalcArea()
         + (*S3).CalcArea() + (*S4).CalcArea();
}

int main()
{
    Rectangle R(2,4);
    Square S(2);
    Circle C(3);
    Triangle T(3, 2);

    cout << "Sum of All Areas = " << sumOfAllAreas(&S, &R, &C, &T) << endl;


    return 0;
}
