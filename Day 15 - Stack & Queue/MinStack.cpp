#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MinStack{
    public:
        stack<long long> s;
        long long min;  // to track minimum element.
        int n;  // size of stack.
        MinStack(){
            while(!s.empty())
                s.pop();
            min = INT_MAX;
            n=0;
        }

        void push(int num){
            // if stack is empty.
            if(n==0){
                min = num;
            } else if(num < min){       // if current number is less than current minimum.
                long long tmp = 2*num*1LL-min;  // we will push modified num instead of it's actual value.
                // as num < min, num + num - min will be always less than num.
                min = num;  // set current num as min.
                num = tmp;  // to push modified num.
            }
            s.push(num);
            n++;
            return;
        }

        int top(){
            // if the top element is less than min, it means min element is at top it self..
            if(n>0 && s.top()<min){
                return min;
            } else if(n>0) {    // else normally return top element.
                return s.top();
            } else {    // if n<0
                return -1;
            }
        }

        int pop(){
            int ans=-1;
            // if top is less than curr min, we first retrive previous min and actual value of top.
            if(n>0 && s.top()<min){
                ans = min;
                min = (2 * min - s.top());
                s.pop();
                n--;
            } else if(n>0) {
                ans = s.top();
                s.pop();
                n--;
                // if stack is empty, set min to initial value.
                if(n==0) min=INT_MAX;
            } 
            return ans;
        }

        int getMin(){
            if(n==0) return -1;
            return min;
        }
};


int main(){
    MinStack ms = MinStack();

    ms.push(13);
    cout << ms.pop() << " ";
    cout << ms.getMin() << " ";
    cout << ms.top() << " ";
    
    return 0;
}