#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<bool> visited(1001, false);
// Normal Depth First Search Algorithm.
void DepthFirstSearch(int node, vector<set<int>>&adj, vector<int> &dfs){
    dfs.push_back(node);

    for(int i: adj[node]){
        if(!visited[i]){
            visited[i] = true;
            DepthFirstSearch(i, adj, dfs);
        }
    }

    return;
}

// to generate adjacency list.
vector<set<int>> getAdjList(vector<vector<int>> &edges, int V){
    // as we need nodes in list in ordered manner, we will use set here.
    vector<set<int>> adj(V, set<int>());
    for(auto i: edges){
        adj[i[0]].insert(i[1]);
        adj[i[1]].insert(i[0]);
    }

    return adj;
}

// Time Complexity: O(V + E).
// Space Complexity: O(V * E).
vector<vector<int>> getDFS(int V, int E, vector<vector<int>> &edges){

    // generate adjacency list first.
    vector<set<int>> adjList = getAdjList(edges, V);

    // as it is given, that graph can be disconnected.
    vector<vector<int>> dfs;    // -- dfs of each component.
    // this loop will run total V times.
    // In main DFS function we run a loop for total E times. 
    for(int i=0; i<V; i++){
        if(!visited[i]){
            visited[i] = true;
            vector<int> tmp;
            DepthFirstSearch(i, adjList, tmp);
            dfs.push_back(tmp);
        }
    }

    return dfs;
}

int main(){
    vector<vector<int>> edges = {
        {0, 2},
        {0, 1},
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> dfs = getDFS(5, 4, edges);
    for(auto i: dfs){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}