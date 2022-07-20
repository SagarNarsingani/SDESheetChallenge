#include <iostream>
#include <vector>
using namespace std;


// memoization.
// Time Complexity: O(Val * N).
// Space Complexity: O(N * Val).
int getAllWays(int val, int coin, vector<int> &coins, vector<vector<int>> &dp){
    if(val==0){
        return 1;
    }

    if(coin<0){
        return 0;
    }

    if(dp[coin][val]!=-1)
        return dp[coin][val];
    
    int ways = 0;
    if(val>=coins[coin]){
        ways = ways + getAllWays(val-coins[coin], coin, coins, dp);
    }

    ways = ways + getAllWays(val, coin-1, coins, dp);

    return dp[coin][val] = ways;
}

// Tabulation
// Time Complexity: O(Val * N).
// Space Complexity: O(2*Val).
int getCoinChangeWays(vector<int> &coins, int val){
    int n = coins.size();
    // vector<vector<int>> dp(n, vector<int>(val+1, -1));
    // return getAllWays(val, n-1, coins, dp);

    vector<int> prev(val+1, 0);
    vector<int> curr(val+1, 0);

    // for(int i=0; i<n; i++){
    //     dp[i][0] = 1;
    // }

    // base cases: as we are using i-1 row inside loops, we need to start from i=1.
    // similarly we need to start from j=1.
    // when val=0, there is always 1 way to make 0 change (don't take any coin).
    // when we have only one coin(at 0th index), we can give change in 1 way, 
    // if j is divisible by first coin.
    prev[0] = 1, curr[0] = 1;
    for(int i=1; i<=val; i++){
        prev[i] = (i%coins[0] ? 0 : 1);
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<=val; j++){
            int ways = 0;
            // if current coin is less than current value, we will take the coin.
            if(coins[i]<=j){
                ways = ways + curr[j-coins[i]];
            }
            // we don't take the coin.
            ways = ways + prev[j];

            curr[j] = ways;
        }
        prev = curr;
    }

    return curr[val];
}

int main(){
    vector<int> coins = {1, 2, 3};
    cout << getCoinChangeWays(coins, 4);
    return 0;
}