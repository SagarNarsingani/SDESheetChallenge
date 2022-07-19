#include <iostream>
#include <vector>
using namespace std;

// Memoization.
// Time Complexity: O(N^3).
// Space Complexity: O(N^2) + O(N) -- DP array + Callstack.
int MCMHelper(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    // base case: When only one matrix is left.
    if(i==j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    // finding minimum steps we can take, by making partition at all possible indices.
    int steps = INT_MAX;
    for(int k=i; k<j; k++){
        int tmp = (arr[i-1]*arr[k]*arr[j]) + MCMHelper(i, k, arr, dp) + MCMHelper(k+1, j, arr, dp);
        steps = min(steps, tmp);
    }

    return dp[i][j] = steps;
}

// Time Complexity: O(N*N*N).
// Space Complexity: O(N*N).
int getMinimumNumofSteps(vector<int> &arr, int N){
    vector<vector<int>> dp(N, vector<int>(N, -1));
    // return MCMHelper(1, N-1, arr, dp);
    for(int i=0; i<N; i++)
        dp[i][i] = 0;

    // as we are using (k+1)th row inside loop, we must first calculate bottom rows.
    for(int i=N-1; i>0; i--){
        // j will be always on right of i.
        for(int j=i+1; j<N; j++){
            int steps = INT_MAX;
            // making partitions.
            for(int k=i; k<j; k++){
                int tmp = (arr[i-1]*arr[k]*arr[j]) + dp[i][k] + dp[k+1][j];
                steps = min(steps, tmp);
            }

            // take minimum from all parts.
            dp[i][j] = steps;
        }
    }
    // note that the 0th row will be all -1, as the matrix will be start from 1st index.
    // also at last of loops we will be at row 1.
    return dp[1][N-1];
}

int main(){
    vector<int> arr = {1, 4, 3, 2};
    cout << getMinimumNumofSteps(arr, arr.size());
    return 0;
}