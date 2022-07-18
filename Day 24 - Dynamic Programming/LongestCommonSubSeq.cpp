#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Using Memoization.
// Time Complexity: O(M*N) -- we call recursion till the dp array is filled.
// Space Complexity: O(M*N + M+N) -- dp array + callstack.
int LCShelper(string s1, string s2, int i, int j, vector<vector<int>> &dp){
    int l1 = s1.length();
    int l2 = s2.length();

    if(i>=l1 || j>=l2){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s1[i]==s2[j]){
        return 1 + LCShelper(s1, s2, i+1, j+1, dp);
    }

    return dp[i][j] = max(LCShelper(s1, s2, i, j+1, dp), LCShelper(s1, s2, i+1, j, dp));

}

// driver function for recurssion.
int getLongestCommonSubSeq(string s1, string s2){
    vector<vector<int>>dp(s1.length(), vector<int>(s2.length(), -1));
    return LCShelper(s1, s2, 0, 0, dp);
}

// Time Complexity: O(N*M).
// Space Complexity: O(2*M) OR O(N*M) -- based on dimensions of dp array.
int getLCS(string s1, string s2){
    int n = s1.length(), m = s2.length();
    // we can either use O(N*M) space.
    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    // Or we can do same work in O(2*M) space.
    vector<int> curr(m+1, 0);
    vector<int> next(m+1, 0);

    // for(int i=0; i<=n; i++){
    //     dp[i][0] = 0;
    // }

    // for(int j=0; j<=m; j++){
    //     dp[0][j] = 0;
    // }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // if character matches.
            if(s1[i-1]==s2[j-1]){
                // dp[i][j] = 1 + dp[i-1][j-1];
                next[j] = 1 + curr[j-1];
            } else {
                // if characters doesn't match.
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                next[j] = max(curr[j], next[j-1]);
            }
        }
        curr = next;
    }

    // dp[n][m] -- the last element will be the answer.
    return next[m];
}

int main(){
    string s1 = "adebc";
    string s2 = "dcadb";
    // cout << getLongestCommonSubSeq(s1, s2);
    cout << getLCS(s1, s2);

    return 0;
}