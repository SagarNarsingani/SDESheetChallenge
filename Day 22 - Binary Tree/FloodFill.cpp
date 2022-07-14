#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Time Complexity: O(M*N)
// Space Complexity: O(M*N)
void dfs(vector<vector<int>> &image, int x, int y, int newColor, int oldColor, int m, int n){
    if(x>=m || y>=n || x<0 || y<0){
        return;
    }

    if(image[x][y]!=oldColor) return;

    image[x][y] = newColor;

    dfs(image, x+1, y, newColor, oldColor, m, n);
    dfs(image, x-1, y, newColor, oldColor, m, n);
    dfs(image, x, y+1, newColor, oldColor, m, n);
    dfs(image, x, y-1, newColor, oldColor, m, n);

    return;
}

bool checkPair(pair<int, int> newCoords, int m, int n){
    return (newCoords.first < m && newCoords.first>=0) 
                            && 
           (newCoords.second<n && newCoords.second>=0);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor){
    int oldColor = image[x][y];
    int m = image.size();
    int n = image[0].size();

    if(oldColor==newColor) return image;

    // bfs -- slow
    // queue<pair<int, int>> q;
    // q.push({x, y});

    // vector<int> dx = {0, 0, 1, -1};
    // vector<int> dy = {1, -1, 0, 0};
    // while(!q.empty()){
    //     auto coords = q.front();
    //     int x1 = coords.first;
    //     int y1 = coords.second;
    //     image[x1][y1] = newColor;
    //     q.pop();

    //     for(int i=0; i<4; i++){
    //         pair<int, int> newCoords = {x1+dx[i], y1+dy[i]};
    //         if(checkPair(newCoords, m, n) && image[newCoords.first][newCoords.second]==oldColor){
    //             q.push(newCoords);
    //         }
    //     }

    // }

    dfs(image, x, y, newColor, oldColor, m, n);

    return image;
}

int main(){
    vector<vector<int>> image = {
        {1, 1, 7, 5},
        {1, 3, 3, 3}, 
        {6, 5, 5, 3},
        {2, 2, 3, 3}
    };

    image = floodFill(image, 1, 2, 8);

    for(auto i: image){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}