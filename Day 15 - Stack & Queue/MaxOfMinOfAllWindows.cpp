#include <iostream>
#include <deque>
#include <vector>
#include <stack>
using namespace std;

// Time Complexity: O(4*N).
// Space Complexity: O(N).
vector<int> GetMaxOfAllWindows(vector<int> arr, int n){
    // first find previous and next smaller element for each element of arr.
    vector<int> right(n, n);
    vector<int> left(n, -1);

    stack<int> s;

    for(int i=0; i<n; i++){
        while(!s.empty() and arr[i]<arr[s.top()]){
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty())
        s.pop();
    
    for(int i=n-1; i>=0; i--){
        while(!s.empty() and arr[i]<arr[s.top()]){
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    // then for each element see for which length, it is minimum and store ans if that element is maximum of all.
    // it may happen that two elements are minimum for same range / same size of window, in that case we need to choose the maximum one.
    vector<int> ans(n, INT_MIN);
    for(int i=0; i<n; i++){
        int len = right[i] - left[i] - 1;
        ans[len-1] = max(ans[len-1], arr[i]);
    }

    // few ranges will be still not correct, as they might be not directly smallest in any range.
    // how ever note that ans[i] will be greater than or equal to ans[i+1].
    // using this fact we are filling remaining ans.
    for(int i=n-2; i>=0; i--){
        ans[i] = max(ans[i], ans[i+1]);
    }

    return ans;

}

int GetMinOfWindows(vector<int> arr, int k){
    int maxi = INT_MIN;
    int n = arr.size();
    deque<int> dq;

    for(int i=0; i<n; i++){
        if(!dq.empty() and (dq.front()==i-k))
            dq.pop_front();
        
        while(!dq.empty() and (arr[i]<arr[dq.back()]))
            dq.pop_back();
        
        dq.push_back(i);

        if(i>=k-1)
            maxi = max(maxi, arr[dq.front()]);
    }

    return maxi;
}

// Time Complexity: O(N^2).
// Space Complexity: O(N).
vector<int> getMax(vector<int> arr, int n){
    vector<int> ans;

    for(int i=1; i<=n; i++){
        ans.push_back(GetMinOfWindows(arr, i));
    }
    return ans;
}

int main(){
    vector<int> ans = GetMaxOfAllWindows({1, 2, 3, 4}, 4);

    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}