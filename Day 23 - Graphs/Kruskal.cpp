#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPar(int u, vector<int> &parent){
    if(u==parent[u]){
        return u;
    }

    return parent[u] = findPar(parent[u], parent);
}

void unioun(int u, int v, vector<int> &rank, vector<int> &parent){
    int up = findPar(u, parent);
    int vp = findPar(v, parent);

    if(rank[up]>rank[vp]){
        parent[vp] = up;
    } else if(rank[up] < rank[vp]){
        parent[up] = vp;
    } else {
        parent[vp] = up;
        rank[up]++;
    }

    return;
}

struct edge{
    int u, v, wt;

    edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

bool comparator(edge a, edge b){
    return (a.wt < b.wt);
}

// Time Complexity: O(M Log M).
// Space Complexity: O( M + N ).
int kruskal(int n, int m, vector<vector<int>> &graph){

    // creating disjoint set: to know if two elements are from same component or not.
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    vector<edge> edges;
    for(auto e: graph){
        edges.push_back(edge(e[0], e[1], e[2]));
    }

    // sort the edges based on their weights.
    sort(edges.begin(), edges.end(), comparator);

    int wt = 0;
    for(edge i: edges){
        int u = i.u;
        int v = i.v;
        // check if current edge, joins elements from two different components or not.
        if(findPar(u, parent)!=findPar(v, parent)){
            // if yes include the edge else move to next edge.
            wt = wt + i.wt;
            unioun(u, v, rank, parent);
        }
    }

    return wt;
}

int main(){
    vector<vector<int>> edges = {
        {1, 2, 4}
    };

    cout << kruskal(2, 1, edges);
    return 0;
}