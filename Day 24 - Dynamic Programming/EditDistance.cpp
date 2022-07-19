#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Using Memoization.
// Time Complexity: O(M*N).
// Space Complexity: O((M*N) + (M+N)) -- dp array + callstack.
int getMinEditDist(int i, int j, string s1, string s2, vector<vector<int>> &dp){
    // if first string is complete, we need to insert remaining characters of second string.
    if(i<0) return j+1;

    // if second string is complete, we need to delete remaining characters of first string.
    if(j<0) return i+1;
    
    // if answer for current indices already exists.
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // if characters match, we don't need to perform any operation.
    if(s1[i]==s2[j])
        return dp[i][j] = getMinEditDist(i-1, j-1, s1, s2, dp);
    
    // if character doesn't match...
    
    // Delete from first string.
    int del = 1 + getMinEditDist(i-1, j, s1, s2, dp);

    // replace character in first string.
    int rep = 1 + getMinEditDist(i-1, j-1, s1, s2, dp);

    // insert character in first string.
    int ins = 1 + getMinEditDist(i, j-1, s1, s2, dp);

    // return the minimum.
    return dp[i][j] = min(del, min(rep, ins));

}

// Time Complexity: O(N*M).
// Space Complexity: O(2*M).
int getEditDistance(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return getMinEditDist(2, 1, "abc", "dc", dp);

    // Tabulation.
    // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    // base cases.
    // for(int i=0; i<=n; i++)
    //     dp[i][0] = i;
    // for(int i=0; i<=m; i++)
    //     dp[0][i] = i;

    vector<int> curr(m+1, 0), prev(m+1, 0);
    // base case
    for(int i=0; i<=m; i++)
        prev[i] = i;

    for(int i=1; i<=n; i++){
        curr[0] = i;    // base case.
        for(int j=1; j<=m; j++){
            
            // if characters match.
            if(s1[i-1]==s2[j-1]){
                // dp[i][j] = dp[i-1][j-1];
                curr[j] = prev[j-1];
                continue;
            }
            
            // else perform three possible operations.
            int del = 1 + prev[j];
            int rep = 1 + prev[j-1];
            int ins = 1 + curr[j-1];

            // and take the minimum one.
            curr[j] = min(min(del, ins), rep);
        }
        prev = curr;
    }

    return curr[m];
}

int main(){
    cout << getEditDistance("abc", "dc");
    return 0;
}