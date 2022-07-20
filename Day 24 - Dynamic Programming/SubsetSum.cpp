#include <iostream>
#include <vector>
using namespace std;

// Memoization.
// Time Complexity: O(N*K).
// Space Complexity: O(N*K) + O(N) -- DP Array + Callstack.
bool isThereK(int i, vector<int> &arr, int k, vector<vector<int>> &dp){
    if(k==0) return true;
    if(i<0)
        return false;

    if(dp[i][k]!=-1)
        return dp[i][k];
    
    bool ans = false;
    // if k is greater than or equal to current element
    // we first select it.
    if(k>=arr[i]){
        // selecting: k will change for next call.
        ans = isThereK(i-1, arr, k-arr[i], dp);
    }

    // and then try by not selecting it.
    if(ans) return dp[i][k] = ans;
    // not selecting: k remains same for next call.
    ans = isThereK(i-1, arr, k, dp);

    return dp[i][k] = ans;
}

// Tabulation.
// Time Complexity: O(N*K).
// Space Complexity: O(K) --- Only one array used.
bool getSubsetSum(vector<int> &arr, int k){
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(k+1, -1));
    vector<vector<int>> dp(n, vector<int>(k+1, false));
    // return isThereK(n-1, arr, k, dp);

    // for(int i=0; i<n; i++)  dp[i][0] = true;
    // if(arr[0]<=k)   dp[0][arr[0]] = true;

    vector<bool> curr(k+1, false);
    curr[0] = true; 
    if(arr[0]<=k)
        curr[arr[0]] = true;

    for(int i=1; i<n; i++){
        for(int j=k; j>=1; j--){
            bool ans = false;
            // if current element is less than current value of k, then we select it.
            if(arr[i] <= j)
                ans = curr[j-arr[i]];
            
            // not selecting current element.
            ans = ans || curr[j];
            curr[j] = ans;
        }
    }

    return curr[k];
}

int main(){
    vector<int> arr = {1,2,3,4};
    cout << getSubsetSum(arr, 4);
    return 0;
}