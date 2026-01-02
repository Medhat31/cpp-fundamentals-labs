#include <iostream>
#include <graphics.h>
#include <conio.h>
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

class Shape{

protected:
int Color;

public:
    //  Ctors
    Shape(){
        Color = WHITE;
    }

    Shape(int C){
        Color = C;
    }

//  Setters

    void setColor(int C){
        Color = C;
    }

    int getColor(){
        return Color;
    }

//  Pure Virtual Method
    virtual void draw() = 0;


};

class Line : public Shape{
private:
    Point P1;
    Point P2;

public:
//  Constructors & Destructor
    Line() : P1(), P2(){}
    Line(int x1, int y1, int x2, int y2, int Color): P1(x1, y1), P2(x2, y2), Shape(Color) {}
    ~Line(){}

    void draw(){
        setcolor(Color);
        line(P1.getX(), P1.getY(), P2.getX(), P2.getY());
    }

};

class Rect : public Shape{
private:
    Point UL;
    Point LR;

public:
    Rect() : UL(), LR(){}
    Rect(int x1, int y1, int x2, int y2, int C): UL(x1, y1), LR(x2, y2),  Shape(Color) {}

    void draw(){
         setcolor(Color);
        rectangle(UL.getX(), UL.getY(), LR.getX(), LR.getY());
    }
};

class Circle : public Shape{
private:
    Point P;
    int radius;

public:
    Circle() : P(500, 500){
        radius = 20;
    }

    Circle(int X, int Y, int R, int Color) : P(X, Y), Shape(Color){
        radius = R;
    }

    ~Circle(){}

    void draw(){
         setcolor(Color);
        circle(P.getX(), P.getY(), radius);
    }
};

class Picture{
private:
    Shape** shPtr;
    int shNum;

public:
//  Ctors
    Picture(){
        shPtr = NULL;

        shNum = 0;
    }

    Picture(Shape** shP, int shN){
        shPtr = shP;
        shNum = shN;
    }

    void Paint(){
        int i = 0;
//      Loop For Printing Rectangles
        for(i = 0; i < shNum; i++){
            (*shPtr[i]).draw();
        }
    }
};

int main()
{
    initwindow(700, 900);
    Line lineArr[2] = {Line(100, 120, 200, 250, RED), Line(300, 300, 450, 430, WHITE)};
    Rect rectArr[3] = {Rect(300, 300, 400, 400, GREEN), Rect(500, 500, 600, 600, YELLOW), Rect(600, 10, 650, 40, WHITE)};
    Circle cirArr[2] = {Circle(200, 200, 100, YELLOW), Circle(300, 300, 50, RED)};

    Shape *shArr[7];
    shArr[0] = &lineArr[0];
    shArr[1] = &lineArr[1];

    shArr[2] = &rectArr[0];
    shArr[3] = &rectArr[1];
    shArr[4] = &rectArr[2];

    shArr[5] = &cirArr[0];
    shArr[6] = &cirArr[1];

    Picture P(shArr, 7);
    P.Paint();
      getch();
    return 0;
}
