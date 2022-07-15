#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<bool> visited(10001, false);
void BreadthFirstSearch(int node, vector<set<int>> &edges, vector<int> &bfs){
    queue<int>q;
    q.push(node);

    // normal level order traversal.
    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        bfs.push_back(tmp);

        for(auto i: edges[tmp]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// Time Complexity: O(V + E).
// Space Complexity: O(V * E).
vector<int> getBFS(int vertex, vector<vector<int>> edges){
    // create adjancency list.
    // as we need to keep nodes in list in ordered manner, we will use set here.
    vector<set<int>> orderedEdges(vertex, set<int>());
    for(int i=0; i<edges.size(); i++){
        orderedEdges[edges[i][0]].insert(edges[i][1]);
        orderedEdges[edges[i][1]].insert(edges[i][0]);
    }

    vector<int> bfs;
    // as graph can be disconnected.
    for(int i=0; i<vertex; i++){
        // only do bfs for nodes that are not yet visited.
        if(!visited[i]){
            visited[i] = true;
            BreadthFirstSearch(i, orderedEdges, bfs);
        }
    }

    return bfs;
}

int main(){
    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {2, 3}
    };

    vector<int> bfs = getBFS(4, edges);
    for(int i: bfs){
        cout << i << " ";
    }
    return 0;
}