#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<bool> visited(101, false);
vector<bool> dfs(101, false);

// generate adjancency list here.
vector<set<int>> getAdjList(int v, vector<vector<int>> &edges){
    vector<set<int>> adj(v+1, set<int>());
    for(auto i: edges){
        adj[i[0]].insert(i[1]);
    }

    return adj;
}

// DFS method to find the cycle.
bool detectCycDfs(int node, vector<set<int>> &adj){
    // adding node in dfs path.
    dfs[node] = true;

    for(int i: adj[node]){
        if(!visited[i]){
            visited[i] = true;
            if(detectCycDfs(i, adj))
                return true;
        } else if(dfs[i]){  
            // if neighbour is already visited and it is also marked true in dfs path.
            return true;
        }
    }

    // removing node from dfs path, before returning.
    dfs[node] = false;

    return false;
}

// Time Complexity: O(V + E).
// Space Complexity: (V * E)
bool isThereCycle(vector<vector<int>> &edges, int n){
    vector<set<int>> adj = getAdjList(n, edges);

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            if(detectCycDfs(i, adj)){
                return true;
            }
        }
    }

    return false;
}

int main(){

    vector<vector<int>> edges = {
        {1, 2}
    };

    cout << isThereCycle(edges, 2);
    return 0;
}