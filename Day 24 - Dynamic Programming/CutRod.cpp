#include <iostream>
#include <vector>
using namespace std;

// Memoization.
// Time Complexity: O(N*N).
// Space Complexity: O(N*N) + O(N) -- DP array + Callstack.
int getMaxProfitHelper(int i, int N, vector<int> &price, vector<vector<int>> &dp){
    if(i==0)
        return N * price[0];
    
    if(N==0)
        return 0;
    
    if(dp[i][N]!=-1)
        return dp[i][N];
    
    int not_take = getMaxProfitHelper(i-1, N, price, dp);
    int take = INT_MIN;
    int rodLen = i+1;
    if(rodLen<=N)
        take = price[i] + getMaxProfitHelper(i, N-rodLen, price, dp);

    return dp[i][N] = max(take, not_take); 
}

// Tabulation.
// Time Complexity: O(N*N).
// Space Complexity: O(N) -- Only Single Row.
// Same logic as 01KnapSack.
int getMaxProfit(vector<int> &price, int n){
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    // return getMaxProfitHelper(n-1, n, price, dp);

    vector<int> curr(n+1, -1);
    // base case: when there is only one item.
    for(int i=0; i<=n; i++)
       curr[i] = i * price[0];
    
    // when allowed size is 0.
    // for(int i=0; i<n; i++)
    //     dp[i][0] = 0;
    
    for(int i=1; i<n; i++){
        for(int j=1; j<=n; j++){
            // not_take : cost same as previous row(with i-1 items) and same col(with j as size limit).
            // int not_take = dp[i-1][j];
            int not_take = curr[j]; // take jth item from previous row.
            int take = INT_MIN;
            int rodLen = i+1;
            // if rodLen is less than current allowed size.
            if(rodLen<=j){
                // take = price[i] + dp[i][j-rodLen];
                take = price[i] + curr[j-rodLen];   // will only take item from left of j from current row.
                // hence we can use only one array.
            }

            // dp[i][j] = max(take, not_take);
            curr[j] = max(take, not_take); 
        }
    }

    return curr[n];
}

int main(){
    vector<int> price ={2, 5, 7, 8, 10};
    cout << getMaxProfit(price, price.size());
    return 0;
}