#include <iostream>
#include <vector>
using namespace std;

// adding a current successful path in main array that we need to return at last.
void addPath(vector<vector<int>> path, vector<vector<int>> &paths, int n){
    vector<int> tmp;
    for(auto i: path){
        for(auto j: i){
            // cout << j << " ";
            tmp.push_back(j);
        }
    }

    paths.push_back(tmp);

    return;
}

void Solve(int row, int col, int n, vector<vector<int>> &paths, vector<vector<int>> graph, vector<vector<int>> visited){
    // If we reached the goal.
    if(row==n-1 and col==n-1){
        visited[n-1][n-1] = 1;
        addPath(visited, paths, n);
        visited[n-1][n-1] = 1;
        return;
    }

    // if a boundary of a maze is crossed.
    if((row>=n or row<0) or (col>=n or col<0)) return;
    // if the cell is blocked.
    if(graph[row][col]==0) return;
    // if cell is already visited.
    if(visited[row][col]==1) return;

    // marking current cell visited.
    visited[row][col]=1;

    // Moving Down.
    Solve(row+1, col, n, paths, graph, visited);
    // Moving Up.
    Solve(row-1, col, n, paths, graph, visited);
    // Moving Right.
    Solve(row, col+1, n, paths, graph, visited);
    // Moving Left.
    Solve(row, col-1, n, paths, graph, visited);

    // marking current cell unvisited.
    visited[row][col] = 0;

    return;
}

// Time Complexity: O(4^(M*N)) -- as for each cell we will go in four directions.
// Space Complexity: O(N*M) -- for visited array.
vector<vector<int>> GetAllPaths(vector<vector<int>> maze, int n){
    vector<vector<int>> paths;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    Solve(0, 0, n, paths, maze, visited);

    for(auto i: paths){
        for(int j: i){
            cout << j << " ";
        }

        cout << endl;
    }

    return paths;
}

int main(){
    vector<vector<int>> maze = {
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    GetAllPaths(maze, maze.size());
    return 0;
}