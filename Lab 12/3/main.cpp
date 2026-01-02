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

class Line{
private:
    Point P1;
    Point P2;

public:
//  Constructors & Destructor
    Line() : P1(), P2(){}
    Line(int x1, int y1, int x2, int y2): P1(x1, y1), P2(x2, y2){}
    ~Line(){}

    void draw(int Color){
        setcolor(Color);
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

    void draw(int Color){
         setcolor(Color);
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

    void draw(int Color){
         setcolor(Color);
        circle(P.getX(), P.getY(), radius);
    }
};

class Picture{
private:
    Rect* rectsPtr;
    Circle* circlesPtr;
    Line* linesPtr;
    int rNum, cNum, lNum;

public:
//  Ctors
    Picture(){
        rectsPtr = NULL;
        circlesPtr = NULL;
        linesPtr = NULL;
        rNum = cNum = lNum = 0;
    }

    Picture(Rect* rp, Circle* cp, Line* lp, int rn, int cn, int ln){
        rectsPtr = rp;
        circlesPtr = cp;
        linesPtr = lp;
        rNum = rn;
        cNum = cn;
        lNum = ln;
    }

    void Paint(){
        int i = 0;
//      Loop For Printing Rectangles
        for(i = 0; i < rNum; i++){
            rectsPtr[i].draw(RED);
        }

//      Loop For Printing Circles
        for(i = 0; i < cNum; i++){
            circlesPtr[i].draw(YELLOW);
        }

//      Loop For Printing Lines
        for(i = 0; i < lNum; i++){
            linesPtr[i].draw(GREEN);
        }

    }


};

int main()
{
    initwindow(700, 900);
    Line lineArr[2] = {Line(100, 120, 200, 250), Line(300, 300, 450, 430)};
    Rect rectArr[3] = {Rect(300, 300, 400, 400), Rect(500, 500, 600, 600), Rect(600, 10, 650, 40)};
    Circle cirArr[2] = {Circle(200, 200, 100), Circle(300, 300, 50)};

    Picture P(rectArr, cirArr, lineArr, 3, 2, 2);
    P.Paint();
      getch();
    return 0;
}
