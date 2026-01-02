#include <iostream>
using namespace std;

// Function Prototypes
template <typename T>
void Swap(T& a, T& b);

// Classes
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
};

template <class T>
class Stack{
private:
    T* Stk;
    int TOS, Size;
public:

//  Constructors
    Stack(){
        TOS = 0;
        Size = 5;
        Stk = new T[Size];
    }

    Stack(int s){
        this->Size = s;
        TOS = 0;
        Stk = new T[Size];
    }

    Stack(const Stack& St){
        this->Size = St.Size;
        this->TOS = St.TOS;
        this->Stk = new T[this->Size];
        for(int i = 0; i < this->TOS; i++){
            this->Stk[i] = St.Stk[i];
        }
    }

    ~Stack(){
        for(int i = 0; i < this->TOS; i++){
            this->Stk[i] = -1;
        }
        delete[] Stk;
    }

    int getSize(){
        return this->Size;
    }

    void setSize(int S){
        this->Size = S;
    }


    bool isEmpty(){
        if(TOS == 0)return 1;
        else return 0;
    }

    bool isFull(){
        if(TOS == Size) return 1;
        else return 0;
    }

    void push(T num){
        if(! isFull()) Stk[TOS++] = num;
        else cout << "Stack is Full\n";
    }

    T pop(){
        if(! isEmpty()){
            return Stk[--TOS];
        }else{
            return -1;
        }
    }

    T peak(){
        if(! isEmpty()) return Stk[TOS - 1];
        else return -1;

    }

    Stack Reverse(){
    Stack S;
    for(int i = TOS - 1; i >= 0; i--){
        S.push(Stk[i]);
    }
    return S;
    }

    void printStack(){
        for(int i = 0; i < TOS; i++){
            cout << "Element " << i + 1 << " : " << Stk[i] << endl;
        }
    }
};

template <typename T>
void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}



int main()
{
     int a=3, b = 5;
    Swap<int>(a,b);
    cout<<"\nAfter Swap: "<<a<<", "<<b<<endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout<<"\nAfter Swap: "<<Ch1<<", "<<Ch2<<endl;
//
    Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);

    cout<<"\nComplex1 After Swap: "<<endl;
    C1.printComplex();
    cout<<"\nComplex2 After Swap: "<<endl;
    C2.printComplex();

    Stack<int> S;
    S.push(10);
    S.push(20);
    cout<< S.pop() << endl;

    Stack<char> S2(3);
    S2.push('A');
    S2.push('B');
    S2.push('C');
    cout<< S2.pop() << endl;

    Stack<Complex> S3(4);
    S3.push(C1);
    S3.push(C2);
    Complex C = S3.pop();
    C.printComplex();

    return 0;
}
