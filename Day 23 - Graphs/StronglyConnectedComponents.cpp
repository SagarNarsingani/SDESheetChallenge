#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

// To generate adjancency list from given edges.
vector<set<int>> getAdjList(vector<vector<int>> &edges, int n){
    vector<set<int>> adj(n, set<int>());
    for(auto i: edges){
        adj[i[0]].insert(i[1]);
    }
    return adj;
}

// to generate transpose of graph. i.e., A->B will become B->A.
vector<set<int>> transposeGraph(vector<set<int>> &adj){
    vector<set<int>> transpose(adj.size(), set<int>());

    int l=0;
    for(set<int> i: adj){
        for(int j: i){
            transpose[j].insert(l); 
        }
        l++;
    }

    return transpose;
}

// dfs to generate topological kind of order (not exactly topological, but kind of).
void dfs(int node, stack<int> &tmp, vector<bool> &vis, vector<set<int>> &adj){
    for(int i: adj[node]){
        if(!vis[i]){
            vis[i]=true;
            dfs(i, tmp, vis, adj);
        }
    }

    tmp.push(node);
    return;
}

// driver function for generating topological kind of order.
vector<int> getTopologicalOrder(int v, vector<set<int>> &adj){
    stack<int> tmp;
    vector<bool> visited(v, false);
    for(int i=0; i<v; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i, tmp, visited, adj);
        }
    }

    vector<int> order;
    while(!tmp.empty()){
        order.push_back(tmp.top());
        tmp.pop();
    }

    return order;
}

// normal dfs.
void dfs1(int node, vector<bool> &vis, vector<int> &tmp, vector<set<int>> &adj){
    tmp.push_back(node);
    for(int i: adj[node]){
        if(!vis[i]){
            vis[i] = true;
            dfs1(i, vis, tmp, adj);
        }
    }
    return;
}

// kosa-raju's Algorithm to get all strongly connected components.
// Time Complexity: O(V * E) -- finding transpose will take maximum time.
vector<vector<int>> kosarajuAlgo(int n, vector<vector<int>> &edges){
    // generate adjancency list.
    vector<set<int>> adj = getAdjList(edges, n);

    // find topological type of order.
    vector<int> order = getTopologicalOrder(n, adj);

    // transpose a graph.
    // after this we will be only able to traverse scc parts.
    vector<set<int>> t = transposeGraph(adj);   // O(V * E) Time.

    // traversing all scc's 
    vector<vector<int>> scc;
    vector<bool> vis(n, false);
    for(int i: order){
        if(!vis[i]){
            vis[i] = true;
            vector<int> tmp;
            dfs1(i, vis, tmp, t);
            scc.push_back(tmp);
        }
    }

    return scc;
}

int main(){
    vector<vector<int>> edges = {
        {7, 3},
        {6, 7},
        {7, 13},
        {0, 5},
        {5, 4},
        {9, 11},
        {11, 10},
        {3, 14},
        {14, 12},
        {0, 13},
        {11, 5},
        {2, 12},
        {5, 6},
        {2, 7}
    };

    vector<vector<int>> scc = kosarajuAlgo(15, edges);

    for(auto i: scc){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

// 15 14
// 1 7
// 5 6
// 0 2
// 4 5
// 10 6
// 0 5
// 2 9
// 2 0
// 0 1
// 9 6
// 1 5
// 12 9
// 14 3
// 0 8

// 15 14
// 4 0
// 6 4
// 14 4
// 6 11
// 0 10
// 9 2
// 10 0
// 4 1
// 3 4
// 14 7
// 1 12
// 3 6
// 2 5
// 0 12

// 15 14
// 8 4
// 13 8
// 13 6
// 11 3
// 3 11
// 1 0
// 13 9
// 6 12
// 5 6
// 1 12
// 3 13
// 8 6
// 12 11
// 8 2

// 15 14
// 5 14
// 12 13
// 3 8
// 10 2
// 0 9
// 4 9
// 0 1
// 1 13
// 4 10
// 6 1
// 10 12
// 10 4
// 8 14
// 10 11
