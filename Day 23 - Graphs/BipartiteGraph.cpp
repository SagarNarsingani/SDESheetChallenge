#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// using Breadth First Search Algorithm.
// Time Complexity: O(V*V).
// Space Complexity: O(V).
bool isBipartite(vector<vector<int>> &edges){
    int n = edges.size();
    vector<int> cols(n, -1);

    queue<int> q;
    q.push(0);
    
    // first node stored in group 0.
    cols[0] = 0;
    bool color = false;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        // color/group of current node.
        color = !cols[f];

        // traversing all nodes.
        for(int i=0; i<n; i++){
            // if edge exists, we check color/group of adjacent node.
            if(edges[f][i] && cols[i]==-1){
                // if adjancent node is not colored, 
                // we will color/group it with opposite color/group than current node's.
                cols[i] = color;
                q.push(i);
            } else if(edges[f][i] && cols[i]!=-1){
                // else if node is colored/grouped, 
                // we check if it's color is same as current node.
                // if yes we return false.
                if(cols[i]==cols[f]){
                    return false;
                }
            }
        }
    }

    // else we return false.
    return true;
}

// using Depth First Search Algorithm.
// Time Complexity: O(V*V).
// Space Complexity: O(V).
bool dfs(int node, vector<vector<int>> &edges, vector<int> &cols){
    bool color = cols[node];
    for(int i=0; i<edges.size(); i++){
        if(edges[node][i] && cols[i]==-1){
            cols[i] = !color;
            if(!dfs(i, edges, cols)){
                return false;
            }
        } else if(edges[node][i] && cols[i]!=-1){
            if(cols[i]==color)
                return false;
        }
    }

    return true;
}

bool isTreeBiparitate(vector<vector<int>> &edges){
    int n = edges.size();
    vector<int> cols(n, -1);

    cols[0] = false;
    return dfs(0, edges, cols);
}
int main(){
    vector<vector<int>> edges = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    cout << isTreeBiparitate(edges);
    return 0;
}