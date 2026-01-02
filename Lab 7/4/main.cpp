/*
4) Queue (FIFO): (2 methods "Circular & Shifting")
================
	- int* Q, Head, Tail
	- constructors (Parameterless & Parameterized)
	- destructor
	- IsFull()
	- IsEmpty()
	- int DeQueue()
	- void EnQueue(int)

*/

// Shifting
#include <iostream>
using namespace std;

class Queue{
private:
    int* Q;
    int Head, Tail, Size;

public:
    Queue(){
        Head = Tail = 0;
        Size = 5;
        Q = new int[Size];
    }

    Queue(int S){
        Head = Tail = 0;
        Size = S;
        Q = new int[Size];
    }

    int isFull(){
        if(Tail == Size){
            return 1;
        }else{
            return 0;
        }
    }

    int isEmpty(){
        return (Tail == Head);
    }


    void EnQueue(int num){
        if(! isFull()){
        Q[Tail++] = num;
        }else{
            cout << "Queue Is Full\n";
        }
    }

    int DeQueue(){
        if(! isEmpty()){
        return Q[Head++];
        }else{
            return -1;
        }
    }

    ~Queue(){
        delete[] Q;
    }
};

int main()
{
    Queue q1;
    q1.EnQueue(10);
    q1.EnQueue(20);
    q1.EnQueue(30);
    q1.EnQueue(40);
    q1.EnQueue(50);

    cout << q1.DeQueue() << endl;
    cout << q1.DeQueue() << endl;
    cout << q1.DeQueue() << endl;
    cout << q1.DeQueue() << endl;
    cout << q1.DeQueue() << endl;
    cout << q1.DeQueue() << endl;
    return 0;
}
