#include <iostream>
#include <vector>
using namespace std;

// Memoization
// Time Complexity: O(N*M).
// Space Complexity: O(M*N) + O(M+N).
int minPathSumHelper(int i, int j, int N, int M, vector<vector<int>> &grid, vector<vector<int>> &dp){
    // base case if we cross any boundary
    if(i>=N || j>=M){
        return 0;
    }

    // if solution for current state already exists.
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // base case: If we reached to the destination.
    if(i==N-1 && j==M-1){
        return grid[i][j];
    }

    // going down.
    int down = minPathSumHelper(i+1, j, N, M, grid, dp);
    // going right.
    int right = minPathSumHelper(i, j+1, N, M, grid, dp);

    // if right or down is zero it means we have crossed the boundaries, 
    // and we don't want to add that in our answer.
    if(down && right)
        return dp[i][j] = min(right, down) + grid[i][j];
    else if(right)
        return dp[i][j] = right + grid[i][j];
    else if(down)
        return dp[i][j] = down + grid[i][j];
    else
        return dp[i][j] = 0;
}

// Tabulation.
// Time Complexity: O(N*M).
// Space Complexity: O(N) -- only single array(curr).
int getMinPathSum(vector<vector<int>> &grid){
    int N = grid.size();
    int M = grid[0].size();
    // vector<vector<int>> dp(N, vector<int>(M, -1));
    // dp[N-1][M-1] = grid[N-1][M-1];

    // return minPathSumHelper(0, 0, N, M, grid, dp);

    vector<int> curr(M, -1);
    curr[M-1] = grid[N-1][M-1];
    
    // base case(last row will be computed).
    for(int i=M-2; i>=0; i--)
        curr[i] = grid[N-1][i] + curr[i+1];
    
    for(int i=N-2; i>=0; i--){
        // last column should be calculated initially.
        curr[M-1] = curr[M-1] + grid[i][M-1];
        for(int j=M-2; j>=0; j--){
            int down = curr[j];
            int right = curr[j+1];
            curr[j] = min(down, right) + grid[i][j];
        }
    }

    return curr[0];
}

int main(){

    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };

    cout << getMinPathSum(grid);
    return 0;
}