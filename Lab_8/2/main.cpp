#include <iostream>
using namespace std;

class Stack{
private:
    int Tos, Size;
    int* Stk;

public:
    Stack(){
        cout << "Parameterless Constructor" << endl;
        this->Tos = 0;
        this->Size = 5;
        this->Stk = new int[Size];
    }

    Stack(int S){
        cout << "Parameterized Constructor" << endl;
        this->Tos = 0;
        this->Size = S;
        this->Stk = new int[Size];
    }

    Stack(const Stack& st){
        cout << "Copy Constructor" << endl;
        this->Tos = st.Tos;
        this->Size = st.Size;
        this->Stk = new int[this->Size];

        for(int i = 0; i < this->Tos; i++){
                this->Stk[i] = st.Stk[i];
        }
    }

    ~Stack(){
        cout << "Destructor" << endl;
        for(int i = 0; i < this->Tos; i++){
            this->Stk[i] = -1;
        }
        delete[] this->Stk;

    }

    int IsEmpty(){
        return (this->Tos == 0);
    }

    int IsFull(){
        return (this->Tos == this->Size);
    }

    void push(int num){
          if(IsFull()){
            cout << "Stack Is Full!" << endl;
            return;
    }
        this->Stk[(this->Tos)++] = num;
    }

    int pop(){
         if(IsEmpty()){
        cout << "Stack Is Empty" << endl;
        return -1;
    }
        return this->Stk[--(this->Tos)];
    }

    friend void viewContent(Stack S);

    Stack Reverse(){
        Stack St;
        for(int i = Tos - 1; i >= 0; i--){
            St.push(this->Stk[i]);
        }
        return St;
    }

};

void viewContent(Stack S){
    for(int i = 0; i < S.Tos; i++){
        cout << "S[" << i << "] = " << S.Stk[i] << endl;
    }
}

main()
{
///************* Copy Ctor Case(1): Pass by value to function ********************

//    Stack S1;
//
//    S1.push(10);
//    S1.push(20);
//    S1.push(30);
//    S1.push(40);
//
//    viewContent(S1);
//
//    cout<<"Num = "<<S1.pop()<<endl;
//    cout<<"Num = "<<S1.pop()<<endl;


///************* Copy Ctor Case(2): Return by value from function ********************

//    Stack S1;
//
//    S1.push(10);
//    S1.push(20);
//    S1.push(30);
//    S1.push(40);
//
//    Stack SS = S1.Reverse();
//    cout << SS.pop() << endl;


///************* Copy Ctor Case(3): Create obj in terms of another obj "Explicitly" ********************

    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    Stack S3 ( S1 );

    for(int i=0; i<10; i++)
    S3.pop();


    for(int i=0; i<10; i++)
        S3.push(-1);

    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;



    return 0;
}

