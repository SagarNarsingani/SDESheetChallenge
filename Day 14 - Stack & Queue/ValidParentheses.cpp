#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
bool isValidParentheses(string exp){
    stack<char> s;
    for(char ch: exp){
        bool emp = !s.empty();  // before accessing top we should check this.
        // if for particular closing parentheses we don't have corresponding opening parentheses on top of stack,
        // we can return false.
        if(ch==')'){
            if(emp and s.top()=='(')
                s.pop();
            else return false;
        } else if(ch=='}'){
            if(emp and s.top()=='{')
                s.pop();
            else return false;
        } else if(ch==']'){
            if(emp and s.top()=='[')
                s.pop();
            else return false;
        } else s.push(ch);
    }

    return s.empty();
}

int main(){
    cout << isValidParentheses("[(])");
    return 0;
}