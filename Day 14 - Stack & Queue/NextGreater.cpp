#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
vector<int> nextGreater(vector<int> arr, int n){
    stack<int> s;
    vector<int> ans(n, -1);
    for(int i=0; i<n; i++){
        int curr = arr[i];
        while(!s.empty()){
            int top = arr[s.top()];
            // will pop all elements(indices) that are smaller than current element.
            if(curr>top){
                ans[s.top()] = curr;
                s.pop();
            } else {
                break;
            }
        }

        // pushing index of current element.
        s.push(i);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n, 0);

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    vector<int> greater = nextGreater(arr, n);

    for(int i: greater){
        cout << i << " ";
    }
    return 0;
}