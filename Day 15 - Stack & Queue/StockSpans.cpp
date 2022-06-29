#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
vector<int> GetSpans(vector<int> prices){
    stack<int> s;
    int n = prices.size();

    vector<int> spans(n, -1);

    // finding previous larger element.
    for(int i=n-1; i>=0; i--){
        while(!s.empty() and (prices[i]>prices[s.top()])){
            spans[s.top()] = s.top() - i;
            s.pop();
        }

        s.push(i);
    }

    while(!s.empty()){
        spans[s.top()] = s.top()+1;
        s.pop();
    }

    return spans;
}

int main(){

    vector<int> spans = GetSpans({4, 2, 3, 3, 7});
    for(int i: spans){
        cout << i << " ";
    }
    return 0;
}