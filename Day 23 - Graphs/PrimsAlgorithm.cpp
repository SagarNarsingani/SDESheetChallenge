#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

// To generate adjancency list from given edges.
vector<vector<pair<int, int>>> getAdjList(int v, vector<pair<pair<int, int>, int>> &edges){
    vector<vector<pair<int, int>>> adj(v+1, vector<pair<int, int>>());

    for(auto i: edges){
        adj[i.first.first].push_back({i.first.second, i.second});
        adj[i.first.second].push_back({i.first.first, i.second});
    }

    return adj;
}

// Prim's Algorithm.
// Time Complexity: O(V * Log V) + O(E * Log V) -- Log V is because of set operations.
// Space Complexity: O(V * E) + O(3 * V)
vector<pair<pair<int, int>, int>> getMinimalSpanningTree(int v, int e, vector<pair<pair<int, int>, int>> &edges){
    
    vector<vector<pair<int, int>>> adj = getAdjList(v, edges);
    
    // will show minimum path weight for each node.
    vector<int> keys(v+1, INT_MAX);

    // will show whether node is already taken in MST or not, so that we can stay away from forming cycle.
    vector<bool> mst(v+1, false);

    // will show parent from which node is having path with minimum weight.
    vector<int> parent(v+1, -1);

    // to get node with minimum edge weight at given time.
    set<pair<int, int>> s;
    
    // source will always have minimum weight as 0.
    keys[1] = 0;
    // initially we select the source node.
    s.insert({0, 1});

    for(int cnt=1; cnt<v; cnt++){
        auto f = s.begin();
        s.erase(f);

        int k = f->second;

        // front node selected.
        mst[k] = true;

        // traverse all adjancent nodes...
        for(auto i: adj[k]){
            // if it is not part of MST yet,
            // and the weight is less than it's previous weight.
            if(!mst[i.first] && keys[i.first]>i.second){
                // if node exists in heap/set, we first delete it.
                auto tmp = s.find({keys[i.first], i.first});
                if(tmp!=s.end()){
                    s.erase(tmp);
                }
                
                // then insert it again with updated weight.
                keys[i.first] = i.second;
                parent[i.first] = k;
                s.insert({i.second, i.first});
            }
        }
    }

    // Gathering all edges.
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=v; i++){
        ans.push_back({{parent[i], i}, keys[i]});
    }

    return ans;
}

int main(){
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 2},
        {{1, 4}, 6},
        {{2, 1}, 2},
        {{2, 3}, 3},
        {{2, 4}, 8},
        {{2, 5}, 5},
        {{3, 2}, 3},
        {{3, 5}, 7},
        {{4, 1}, 6},
        {{4, 2}, 8},
        {{4, 5}, 9},
        {{5, 2}, 5},
        {{5, 3}, 7},
        {{5, 4}, 9}
    };

    vector<pair<pair<int, int>, int>> mst = getMinimalSpanningTree(5, 14, edges);

    for(auto i: mst){
        cout << i.first.first << " " << i.first.second << " : " << i.second << endl;
    }

    return 0;
}