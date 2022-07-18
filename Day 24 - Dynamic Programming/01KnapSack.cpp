#include <iostream>
#include <vector>
using namespace std;

// Using Memoization.
// Time Complexity: O(N*W).
// Space Complexity: O(N + N*W) -- matrix + callstack.
int knapSackHelper(int i, vector<int> &weights, vector<int> &costs, int W, vector<vector<int>> &dp){
    // base case: if no items are left OR weight limit is zero.
    // if(i<0 || W==0) return 0;

    // another valid and effecient base case: only one item is left.
    // this will reduce the number of recurssions.
    if(i==0){
        // if bag has space left for last item.
        if(weights[0] <= W){
            return weights[0];
        }
        return 0;
    }

    if(dp[i][W]!=-1){
        return dp[i][W];
    }

    int take = INT_MIN;
    // Don't take element.
    int not_take = knapSackHelper(i-1, weights, costs, W, dp);
    // if weight limit allows, then take the element.
    if(W-weights[i]>=0){
        take = costs[i] + knapSackHelper(i-1, weights, costs, W-weights[i], dp);
    }

    // return maximum we can get, either by taking or not taking.
    return dp[i][W] = max(take, not_take);
}


// Using tabulation.
// Time Complexity: O(N*W).
// Space Complexity: O(W).
int getMaxProfit(vector<int> &weights, vector<int> &costs, int W){
    int n = weights.size();

    // vector<vector<int>> dp (n, vector<int>(W+1, -1));
    // for(int i=0; i<n; i++){
    //     dp[i][0] = 0;
    // }

    // return knapSackHelper(n-1, weights, costs, W, dp);

    vector<int> prev(W+1, 0);

    // for 0th item, all the columns having value greater than weight of 0th element, we will take the item.
    // Base Case.
    for(int i=weights[0]; i<=W; i++)
        prev[i] = costs[0];
    
    // Not that we require only one row each time.
    // Also here it is possible to calculate values from right to left, hence we can do things in one row only.
    for(int i=1; i<n; i++){
        for(int w=W; w>=0; w--){
            // don't take item, profit remains same as previous row with weight = w.
            int not_take = prev[w];
            int take = INT_MIN;
            // if weight limit allows, take the item.
            // by taking item we need to take profit we got from previous row with weight = w - weights[i].
            if(weights[i] <= w)
                take = costs[i] + prev[w-weights[i]];
            // take maximum that we can get, either by taking or not taking ith item for weight_limit=w.
            prev[w] = max(take, not_take);
        }
    }

    return prev[W];
}


int main(){
    vector<int> wts = {5, 4, 8, 6};
    vector<int> vals = {1, 2, 4, 5};

    cout << getMaxProfit(vals, wts, 5);
    return 0;
}