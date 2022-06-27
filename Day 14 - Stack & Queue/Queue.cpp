#include <iostream>
#include <vector>
using namespace std;

// Queue Implementation Using Dynamic Array.
class Queue{
    public:
        int frnt;
        int back;
        int *queue;

        Queue(){
            frnt=0;
            back=0;
            queue = new int[5000];
        }

        void enqueue(int num){
            queue[back++] = num;
            back = back%5000;
            return;
        }

        int dequeue(){
            if(isEmpty()) return -1;
            int ans = queue[frnt];
            frnt = (frnt+1)%5000;
            return ans;
        }

        int front(){
            if(isEmpty()) return -1;
            return queue[frnt];
        }

        bool isEmpty(){
            return frnt==back;
        }
};

int main(){
    Queue q = Queue();

    q.enqueue(10);
    q.enqueue(7);
    q.enqueue(4);

    cout << q.front() << endl;
    q.dequeue();
    cout << q.dequeue() << endl;
    q.dequeue();
    cout << q.isEmpty() << endl;

    return 0;
}