#include <iostream>
#include <graphics.h>
using namespace std;

class Point{
private:
    int x, y;

public:

//  Constructors & Deconstructor
    Point(){
        x = y = 0;
    }

    Point(int X, int Y){
        x = X;
        y = Y;
    }
    ~Point(){}

//  Setters & Getters

    void setX(int num){
        x = num;
    }

    void setY(int num){
        y = num;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }
};

class Line{
private:
    Point P1;
    Point P2;

public:
//  Constructors & Destructor
    Line() : P1(), P2(){}
    Line(int x1, int y1, int x2, int y2): P1(x1, y1), P2(x2, y2){}
    ~Line(){}

    void draw(){
        line(P1.getX(), P1.getY(), P2.getX(), P2.getY());
    }

};

class Rect{
private:
    Point UL;
    Point LR;

public:
    Rect() : UL(), LR(){}
    Rect(int x1, int y1, int x2, int y2): UL(x1, y1), LR(x2, y2){}

    void draw(){
        rectangle(UL.getX(), UL.getY(), LR.getX(), LR.getY());
    }
};

class Circle{
private:
    Point P;
    int radius;

public:
    Circle() : P(500, 500){
        radius = 20;
    }

    Circle(int X, int Y, int R) : P(X, Y){
        radius = R;
    }

    ~Circle(){}

    void draw(){
        circle(P.getX(), P.getY(), radius);
    }


};

int main()
{
    initwindow(1000, 800);

//    setbkcolor(BLACK);
//    cleardevice();

    setcolor(RED);
    Line L(10, 20, 100, 150);
    L.draw();

    Rect R(200, 250, 500, 550);
    R.draw();

    Circle C(250, 300, 30);
    C.draw();

    getch();
    return 0;
}
