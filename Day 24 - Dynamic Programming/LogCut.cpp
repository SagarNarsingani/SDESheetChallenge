#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Memoization.
// Space Complexity: O(N*K) + O(N+K) -- DP array + Callstack.
// Time Complexity: O(N*N*K)
int getMinMoves(int k, int n, vector<vector<int>> &dp){
    if(n<=1 || k<=1) return n;

    if(dp[k][n]!=-1) return dp[k][n];

    int ans = n;
    int curr = INT_MIN;
    for(int i=1; i<=n; i++){
        int suc = getMinMoves(k-1, i-1, dp);
        int fail = getMinMoves(k, n-i, dp);
        curr = max(suc, fail);
        ans = min(curr, ans);
    }

    return dp[k][n] = ans + 1;
}


int CutLogs(int k, int n){
    // vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
    // return getMinMoves(k, n, dp);

    // Base Case: When N is less than / equal to 1.
    vector<int> dp(n+1, 0);
    for(int i=0; i<=n; i++)
        dp[i] = i;
    
    // Base Case: When K is less than / equal to 1.
    // for(int i=0; i<=k; i++){
    //     dp[i][0] = 0;
    //     dp[i][1] = 1;            
    // }

    for(int i=2; i<=k; i++){
        vector<int> dp2(n+1, 0);
        int t = 1;
        for(int j=1; j<=n; j++){
            while(t < j && max(dp[t-1], dp2[j-t]) > max(dp[t], dp2[j-t-1]))
                t++;
            dp2[j] = 1 + max(dp[t-1], dp2[j-t]);
        }
        dp = dp2;
    }

    return dp[n];
}

int main(){
    cout << CutLogs(2, 6);
    return 0;
}