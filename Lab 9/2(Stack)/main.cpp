#include <iostream>
using namespace std;

class Stack{
private:
    int* Stk;
    int TOS, Size;
public:

    static int counter;

//  Constructors
    Stack(){
        TOS = 0;
        Size = 5;
        Stk = new int[Size];
        counter++;
    }

    Stack(int s){
        this->Size = s;
        TOS = 0;
        Stk = new int[Size];
        counter++;
    }

    Stack(const Stack& St){
        this->Size = St.Size;
        this->TOS = St.TOS;
        this->Stk = new int[this->Size];
        for(int i = 0; i < this->TOS; i++){
            this->Stk[i] = St.Stk[i];
        }
    }

    ~Stack(){
        for(int i = 0; i < this->TOS; i++){
            this->Stk[i] = -1;
        }
        delete[] Stk;

        counter--;
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

    void push(int num){
        if(! isFull()) Stk[TOS++] = num;
        else cout << "Stack is Full\n";
    }

    int pop(){
        if(! isEmpty()){
            return Stk[--TOS];
        }else{
            return -1;
        }
    }

    int peak(){
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

    Stack operator=(const Stack& St){
        this->Size = St.Size;
        this->TOS = St.TOS;
        this->Stk = new int[this->Size];
        for(int i = 0; i < this->TOS; i++){
            this->Stk[i] = St.Stk[i];
        }
        return *this;
    }

    Stack operator+(const Stack& St){
        Stack Result;
        Result.Size = this->Size + St.Size;
        Result.TOS = this->TOS + St.TOS;
        Result.Stk = new int[Result.Size];
    // Appending first stack content into Result
        for(int i = 0; i < this->TOS; i++){
            Result.Stk[i] = this->Stk[i];
        }
    // Appending second stack content into Result
        for(int i = this->TOS; i < (this->TOS + St.TOS); i++){
            Result.Stk[i] = St.Stk[i - (this->TOS)];
        }
        return Result;
    }

    int& operator[](int i){
        if(i >= 0 && i < this->TOS)
            return this->Stk[i];
        else{
        throw out_of_range("Index out of bounds");
        }
    }

};
    int Stack::counter = 0;


int main()
{
    Stack S1(5), S2(7), S3(3);
// **************  Counter Testing  *****************
    // cout << Stack::counter << endl;
    S2.push(10);
    S2.push(20);
    S2.push(30);

//    S2.printStack();

// ************** S1 = S2 Testing *****************

    cout << "S1 Size = "<< S1.getSize() << endl;
    cout << "S2 Size = "<< S2.getSize() << endl;
    S1 = S2;
    S1.printStack();
    cout << "S1 Size = "<< S1.getSize() << endl;
    cout << "S2 Size = "<< S2.getSize() << endl;


// ************** S3 = S1 + S2 Testing *****************
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
//    S3 = (S1 + S2);
//    S3.printStack();

// ************** S1[i] Testing *****************
S1.printStack();
    cout << S1[2] << endl;
    S1[2] = 10;
    S1.printStack();
    cout << S1[2];
    return 0;
}
