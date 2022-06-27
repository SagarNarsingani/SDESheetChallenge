#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Stack{
    public:
        queue<int> q1, q2;

        bool isEmpty(){
            return (q1.empty() and q2.empty());
        }

        int getSize(){
            return max(q1.size(), q2.size());
        }

        void push(int num){
            if(q1.empty()){
                q2.push(num);
            } else {
                q1.push(num);
            }
            return;
        }

        // O(N) time.
        int top(){
            if(isEmpty()) return -1;
            int top = pop();
            if(q1.empty()){
                q2.push(top);
            } else {
                q1.push(top);
            }

            return top;
        }

        // O(N) time.
        int pop(){
            if(isEmpty()) return -1;
            if(q1.empty()){
                int n = q2.size();
                while(n > 1){
                    q1.push(q2.front());
                    q2.pop();
                    n--;
                }
                int top = q2.front();
                q2.pop();
                return top;
            }else {
                int n = q1.size();
                while(n>1){
                    q2.push(q1.front());
                    q1.pop();
                    n--;
                }
                int top = q1.front();
                q1.pop();
                return top;
            }
        }
};

int main(){
    Stack s = Stack();

    s.push(10);
    s.push(4);
    s.push(7);

    cout << s.getSize() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.pop() << endl;
    s.pop();

    cout << s.isEmpty() << endl;
    return 0;
}