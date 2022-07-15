#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<set<int>> getAdjList(int v, vector<vector<int>> &edges){
    vector<set<int>> adj(v, set<int>());
    for(auto i: edges){
        adj[i[0]].insert(i[1]);
    }

    return adj;
} 

// Kahn's Algorithm.
// Time Complexity: O(V + E)
// Space Complexity: O(V * E).
vector<int> TopologicalSort(vector<vector<int>> &edges, int v, int e){
    vector<set<int>> adj = getAdjList(v, edges);

    // count indegree
    vector<int> in(v, 0);
    for(auto i: adj){
        for(int j: i){
            in[j]++;
        }
    }

    queue<int> q;
    for(int i=0; i<v; i++){
        if(in[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int f = q.front();
        q.pop();

        for(int i: adj[f]){
            in[i]--;
            if(in[i]==0){
                q.push(i);
            }
        }

        ans.push_back(f);
    }

    return ans;
}

int main(){
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {2, 1}
    };

    TopologicalSort(edges, 3, 3);
    return 0;
}