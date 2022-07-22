#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string str, int s, int e){
    while(s<=e){
        if(str[s]!=str[e])
            return false;
        s++, e--;
    }

    return true;
}

// Memoization.
// Time Complexity: O(N*N) - N for loop and N for Checking Palindrome.
// Recursively function will only run for N times.
// Space Complexity: O(N) + O(N) -- DP Array + Callstack.
int getMinPartsHelp(string str, int pos, vector<int> &dp){
    int n = str.length();
    // if we reached at the end.
    if(pos==n)
        return 0;

    // if solution for current position already exists...
    if(dp[pos]!=-1)
        return dp[pos];
    
    // if string is palindrome we will return 0 -- This step is optional.
    if(isPalindrome(str, pos, n-1))
        return dp[pos] = 0;
    
    int cnt = (n-1)-pos;
    for(int i=pos; i<n; i++){
        if(isPalindrome(str, pos, i)){
            cnt = min(cnt, 1 + getMinPartsHelp(str, i+1, dp));
        }
    }

    return dp[pos] = cnt;
}

int getMinParts(string str){
    /* ------------------------------- Memoization ------------------------------ */
    // vector<int> dp(str.length(), -1);
    // return getMinPartsHelp(str, 0, dp);

    /* ------------------------------- Tabulation ------------------------------- */
    // Time Complexity: O(N*N).
    // Space Complexity: O(N).
    int n = str.length();
    vector<int> dp(n+1, -1);

    dp[n] = 0;
    dp[n-1] = 0;

    // Will iterate over position on which we can make cuts.
    for(int i=n-2; i>=0; i--){
        int cnt = n-i;

        // optional -- if not taken then take initial value of cnt = INT_MAX.
        // and return dp[0]-1 instead of dp[0]. Also dp[n-1] will be 1.
        if(isPalindrome(str, i, n-1)){
            dp[i] = 0;
            continue;
        }
        // making cuts whereever possible and will take minimum from all of them.
        for(int j=i; j<n; j++){
            if(isPalindrome(str, i, j)){
                cnt = min(cnt, 1 + dp[j+1]);
            }
        }
        dp[i] = cnt;
    }

    return dp[0];
}

int main(){
    string s;
    cin >> s;
    cout << getMinParts(s);
    return 0;
}