#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
using namespace std;

vector<bool> visited(5000, false);

vector<set<int>> getAdjList(int n, vector<vector<int>> &edges){
    vector<set<int>> adj(n+1, set<int>());
    for(auto i: edges){
        adj[i[0]].insert(i[1]);
        adj[i[1]].insert(i[0]);
    }
    return adj;
}

// detecting a cycle in current component using BFS algorithm.
bool detectCycBfs(int node, vector<set<int>> &edges){
    queue<pair<int, int>> q;
    q.push({node, -1});

    while(!q.empty()){
        auto f = q.front();
        q.pop();

        for(int i: edges[f.first]){
            if(!visited[i]){
                q.push({i, f.first});
                visited[i] = true;
            } else if(visited[i] && i!=f.second){
                // if neighbour is already visited and that neighbour is not the parent node.
                return true;
            }
        }
    }

    return false;
}

// detecting a cycle in current component using DFS algorithm.
bool detectCycDfs(int node, int prev, vector<set<int>> &edges){
    visited[node] = true;

    for(int i: edges[node]){
        if(!visited[i]){
            if(detectCycDfs(i, node, edges)){
                return true;
            }
        } else if(i!=prev){
            // if neighbour is already visited and that neighbour is not the parent node.
            return true;
        }
    }

    return false;
}

// Time Complexity: O(V + E).
// Space Complexity: O(V * E).
bool isThereCycle(int n, int m, vector<vector<int>> &edges){
    vector<set<int>> adjList = getAdjList(n , edges);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            // can use dfs or bfs here.
            if(detectCycBfs(i, adjList))
                return true;
        }
    }

    return false;
}

int main(){
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {4, 3},
        {5, 4},
        {6, 5}
    };

    cout << isThereCycle(6, 5, edges);

    return 0;
}