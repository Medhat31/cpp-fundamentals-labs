#include <iostream>
using namespace std;


class Base{
private:
    int x;

protected:
    int y;

public:
    Base(){
        this->x = this->y =0;
    }

    Base(int num){
        this->x = this->y = num;
    }

    Base(int X, int Y){
        this->x = X;
        this->y = Y;
    }

    ~Base(){}

    void setX(int X){
        this->x = X;
    }

    int getX(){
        return this->x;
    }

    void setY(int Y){
        this->y = Y;
    }

    int getY(){
        return this->y;
    }

    virtual int sum(){
        return (this->x + this->y);
    }
};

class Derived : public Base {
private:
    int z;

public:
    Derived() : Base(0, 0){
        this->z = 0;
    }

    Derived(int X, int Y, int Z) : Base(X, Y){
       this->z = Z;
    }

    ~Derived(){}

    void setZ(int Z){
        this->z = Z;
    }

    int getZ(){
        return this->z;
    }

    int sum(){
        return (getX() + this->y + this->z);
    }
};

class Derived_Junior : public Derived{
private:
    int m;

public:
    Derived_Junior() : Derived(0, 0, 0){
        this->m = 0;
    }

    Derived_Junior(int X, int Y, int Z, int M) : Derived(X, Y, Z){
        this->m = M;
    }

    void setM(int M){
        this->m = M;
    }

    int getM(){
        return this->m;
    }

    int sum(){
        return (getX() + y + getZ() + m);
    }
};


int main()
{
    Derived D(1, 2, 3);
    Base* ptr = &D;
    cout << ptr->sum() << endl;

    return 0;
}
