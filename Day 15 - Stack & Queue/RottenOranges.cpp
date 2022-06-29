#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

// Time Complexity: O(N*N*4).
// Space Complexity: O(N*N).
int TimeTakenToRot(vector<vector<int>> grid, int n, int m){
    if(n==0) return 0;
    int total=0;

    // will first find out co-ordinates of each rotten orange and store it in queue.
    // we will also find total no. of oranges (rotten+fresh).
    queue<pair<int, int>> rotten;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]!=0)
                total++;
            
            if(grid[i][j]==2)
                rotten.push({i, j});
        }
    }

    // if there are no oranges at all.
    if(total==0) return 0;

    // valid moves (four directional here).
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    // will count time taken to rot cnt no of oranges.
    int cnt = 0, time = 0;
    while(!rotten.empty()){
        int r = rotten.size();
        cnt = cnt + r;
        
        // r is current available rotten oranges.
        // each of which will rot adjacent fresh oranges in one second.
        while(r--){
            int x = rotten.front().first;
            int y = rotten.front().second;

            rotten.pop();

            // move in all four directions.
            for(int i=0; i<4; i++){
                int tx = x + dx[i];
                int ty = y + dy[i];

                // if new coordinates are out of bound or current cell doesn't have fresh orange, we will skip this coordinates. 
                if(tx<0 || ty<0 || tx>=n || ty>=m || grid[tx][ty]!=1) continue;

                grid[tx][ty] = 2;
                rotten.push({tx, ty});
            }
        }

        // if rotten is not empty, it means few oranges were rotten in previous loop/second.
        if(!rotten.empty())
            time++;
    }

    // if all oranges are rotten then we will return time else we will return -1.
    return (cnt==total) ? time : -1;
}