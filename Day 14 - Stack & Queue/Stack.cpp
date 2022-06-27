#include <iostream>
#include <vector>
using namespace std;

// Implementing Stack Using Dynamic Array.
class Stack{
    public:
        int capacity;
        int cs; // current size
        int *stack;

        Stack(int cap){
            stack = new int[cap];
            capacity = cap;
            cs = 0;
        }

        bool isEmpty(){
            return (cs==0);
        }

        bool isFull(){
            return (cs==capacity);
        }

        void push(int num){
            if(!isFull())
                stack[cs++] = num;
            return;
        }

        int pop(){
            if(isEmpty())
                return -1;
            cs--;
            return stack[cs];
        }

        int top(){
            if(isEmpty())
                return -1;
            return stack[cs-1];
        }
};

int main(){
    Stack s = Stack(5);
    s.push(10);
    s.push(4);
    s.push(7);

    cout << s.top() << endl;

    s.pop();

    cout << s.pop() << endl;
    s.pop();
    cout << s.isEmpty() << endl;

    cout << s.isFull() << endl;

    return 0;
}