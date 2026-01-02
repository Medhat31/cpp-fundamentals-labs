/*
3) Stack (LIFO):
================

Class Stack
{
	int[] Stk, Tos, Size;

	int Peak()
	{ ... }

	Stack Reverse() //return new stack "with reversed internal array of original stack"
	{ ... }

	void PrintStack() //print stack content without Poping them out
	{ ... }
}

*/
#include <iostream>
using namespace std;

class Stack{
private:
    int* Stk;
    int TOS, Size;
public:
//  Constructors
    Stack(){
        TOS = 0;
        Size = 5;
        Stk = new int[Size];
    }

    Stack(int s){
        this->Size = s;
        TOS = 0;
        Stk = new int[Size];
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

};
int main()
{
   Stack S1(5);

	S1.push(10);
	S1.push(20);
	S1.push(30);

	cout<< S1.peak() << endl; //30
	cout<< S1.peak() << endl; //30

	cout<< S1.pop() << endl; //30
	cout<< S1.pop() << endl; //20

	Stack S2(5);

	S2.push(3);
	S2.push(4);
	S2.push(5);
	S2.push(6);

	cout<< S2.Reverse().pop();
    return 0;
}
