#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(K).
vector<int> GetMaxInAllWindows(vector<int> arr, int k){
    vector<int> ans;
    deque<int> dq;
    int n = arr.size();

    for(int i=0; i<n; i++){
        // while moving the window, removing the first element.
        if(!dq.empty() and (dq.front()==(i-k))){
            dq.pop_front();
        }
        
        // elements that are less than current element should be removed as they are of no use.
        while(!dq.empty() and (arr[i]>arr[dq.back()])){
            dq.pop_back();
        }

        // push current element in the window.
        dq.push_back(i);

        // once we crossed k index of given array, in each iteration the first element of window will be the largest. 
        if(i>=(k-1)) {
            ans.push_back(arr[dq.front()]);
        }
    }

    return ans;
}

int main(){
    vector<int> ans = GetMaxInAllWindows({4, 2, 1, 4, 4}, 2);

    for(int i: ans){
        cout << i << " ";
    }

    return 0;
}