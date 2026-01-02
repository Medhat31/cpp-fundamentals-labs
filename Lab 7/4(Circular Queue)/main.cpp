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
        Size = 6;
        Q = new int[Size];
    }

    Queue(int S){
        Head = Tail = 0;
        Size = S;
        Q = new int[Size];
    }

    int isFull(){
         return (Tail + 1) % Size == Head;
    }

    int isEmpty(){
        return (Tail == Head);
    }


    void EnQueue(int num){
        if(isFull()){
            cout << "Queue Is Full\n";
            return;
        }else{
            Q[Tail] = num;
            Tail = (Tail + 1) % Size;


        }
    }


    int DeQueue(){
        if(! isEmpty()){
        int val = Q[Head];
        Head = (Head + 1) % Size;
        return val;
        }else{
            return -1;
        }
    }

    void printQueue(){
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        int i = Head;
        while (i != Tail) {
        cout << Q[i] << "\t";
        i = (i + 1) % Size;
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
//    q1.printQueue();

    cout << q1.DeQueue() << endl;
    cout << q1.DeQueue() << endl;
    cout << q1.DeQueue() << endl;

//    q1.printQueue();

    q1.EnQueue(1);

    q1.printQueue();

    return 0;
}
