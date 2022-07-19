#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// memoization.
// Space Complexity: O(N^2) + O(N) -- dp array + callstack.
// Time Complexity: O(N^2).
int getMaxSum(int i, int prev, vector<int> &wts, vector<vector<int>> &dp){
    if(i==wts.size())
        return 0;
    
    // if solution already exists.
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }

    // Either don't take current item.
    int take = INT_MIN;
    // or if current one is greater than previous we will take current.
    int not_take = getMaxSum(i+1, prev, wts, dp);
    if(prev==-1 || wts[i]>wts[prev]){
        take = wts[i] + getMaxSum(i+1, i, wts, dp);
    }

    // find maximum sum.
    return dp[i][prev+1] = max(take, not_take);
}

// Time Complexity: O(N*N).
// Space Complexity: O(N).
int getMaxSumOfIncSubSeq(vector<int> &rack, int n){
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return getMaxSum(0, -1, rack, dp);

    // Tabulation.
    vector<int> dp(n, -1);
    dp[0] = rack[0];

    int ans, maxSum=dp[0];
    for(int i=1; i<n; i++){
        // initially current element is the answer for current index.
        ans = rack[i];
        for(int j=0; j<i; j++){
            // we will find maximum sum that we can make from index (0...i).
            if(rack[j]<rack[i])
                ans = max(ans, rack[i]+dp[j]);
        }
        // store answer for current index, which will be used in next iterations.
        dp[i] = ans;
        maxSum = max(maxSum, ans);
    }
    return maxSum;
}

int main(){
    vector<int> rack = {5, 1,  2, 8};
    cout << getMaxSumOfIncSubSeq(rack, rack.size());
    return 0;
}