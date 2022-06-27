#include <iostream>
#include <stack>
using namespace std;


class Queue{
    public:
        stack<int> s;

        bool isEmpty(){
            return s.empty();
        }

        void enQueue(int num){
            s.push(num);
        }

        // O(N) time.
        int peek(){
            if(isEmpty()) return -1;
            stack<int> tmp;
            while(!s.empty()){
                tmp.push(s.top());
                s.pop();
            }

            int peek = tmp.top();

            while(!tmp.empty()){
                s.push(tmp.top());
                tmp.pop();
            }

            return peek;
        }

        // O(N) time.
        int deQueue(){
            if(isEmpty()) return -1;
            stack<int> tmp;
            while(!s.empty()){
                tmp.push(s.top());
                s.pop();
            }

            int peek = tmp.top();
            tmp.pop();

            while(!tmp.empty()){
                s.push(tmp.top());
                tmp.pop();
            }

            return peek;
        }

        
};

int main(){
    Queue q = Queue();

    q.enQueue(10);
    q.enQueue(4);
    q.enQueue(7);

    cout << q.peek() << endl;
    q.deQueue();
    cout << q.deQueue() << endl;
    q.deQueue();

    cout << q.isEmpty() << endl;
    return 0;
}