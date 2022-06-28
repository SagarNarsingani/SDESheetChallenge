#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
vector<int> getNextSmaller(vector<int> arr, int n){
    vector<int> res(n, -1);
    stack<int> s;

    for(int i=0; i<n; i++){
        // will remove all elements that are greater than current element.
        // and store current element as their corresponding answer.
        while(!s.empty()){
            int top = arr[s.top()];
            if(top > arr[i]){
                res[s.top()] = arr[i];
                s.pop();
            } else break;
        }
        // pushing current element (index).
        s.push(i);
    }

    return res;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        arr[i] = t;
    }

    vector<int> res = getNextSmaller(arr, n);
    for(int i: res){
        cout << i << " ";
    }

    return 0;
}