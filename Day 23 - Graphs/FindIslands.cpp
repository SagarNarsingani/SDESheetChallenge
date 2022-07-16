#include <iostream>
#include <vector>
using namespace std;

bool vis[1001][1001] = {false};

bool checkBoundaries(int **arr, int x, int y, int n, int m){
    if(x>=n || y>=m || x<0 || y<0 || arr[x][y]==0 || vis[x][y])
        return false;
    return true;
}

void dfs(int **arr, int x, int y, int n, int m){
    vis[x][y] = true;

    vector<int> dx = {1, -1, -1, 1, 1, -1, 0, 0};
    vector<int> dy = {1, -1, 1, -1, 0, 0, -1, 1};

    for(int i=0; i<=7; i++){
        int xn = x + dx[i];
        int yn = y + dy[i];
        if(checkBoundaries(arr, xn, yn, n, m)){
            dfs(arr, xn, yn, n, m);
        }
    }

    return;
}

// Time Complexity: O(N*M) + O(X*8) -- X is number of 1's in given array.
// Space Complexity: O(N*M) + O(X*8) -- Visited array + Callstack.
int getNumberOfIslands(int **arr, int n, int m){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] && !vis[i][j]){
                dfs(arr, i, j, n, m);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){

    // create array.
    int n, m;
    cin >> n >> m;
    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
    }

    // get values for array from user.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int islands = getNumberOfIslands(arr, n, m);
    cout << islands;

    // delete the array at the end.
    for(int i=0; i<n; i++){
        delete [] arr[i];
    }
    delete [] arr;
    return 0;
}