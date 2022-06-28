#include <iostream>
#include <stack>
using namespace std;

void place(stack<int> &s, int top){
    // if stack is empty or the top of stack is less than or equal to current element.
    if(s.empty() or s.top() <= top){
        s.push(top);
        return;
    }

    // go till we reach the base case.
    int temp = s.top();
    s.pop();
    place(s, top);
    s.push(temp);

    return;
}

// Time Complexity: O(N^2) -- sortStack will run for N times in which place will run for (N+N-1+N-2+...+1) in worst case.
// Space Complexity: O(N) -- max size of callstack used at a time.
void sortStack(stack<int> &s){
    if(s.empty()) return;

    // basically empty the stack.
    int top = s.top();
    s.pop();
    sortStack(s);

    // place current element at it's right position.
    place(s, top);

    return;
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop(); 
    }

    return 0;
}