#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <list>
using namespace std;

class Graph{
    public: 
        int V;
        // array of list of pairs.
        list<pair<int, int>> *adj;

        Graph(int V){
            this->V = V;
            adj = new list<pair<int, int>>[V];
        }

        void addEdge(int src, int dest, int wt, bool isundir=true){
            adj[src].push_back({dest, wt});
            if(isundir){
                adj[dest].push_back({src, wt});
            }
            return;
        }

        // Time Complexity: O((V + E) * LogV) -- Log V is used by set internally to keep nodes sorted.
        // Space Complexity: O(V).
        vector<int> Dijikstra(int src){
            vector<int> dist(V, INT_MAX);
            
            // set is used as heap, we can use min heap also.
            set<pair<int, int>> heap;

            // starting with source, the distance from source to source will be 0.
            dist[src] = 0;
            // adding it to heap/set.
            heap.insert({dist[src], src});

            while(!heap.empty()){
                // take the first element from the heap.
                auto p = heap.begin();

                // d is distance from source to 'node'.
                int d = p->first;
                int node = p->second;

                heap.erase(p);

                // will visit all adjacent nodes.
                for(auto i: adj[node]){
                    // if distance from source to current neighbour can be updated,
                    // we will update it and push it into heap.
                    if(dist[i.first] > d + i.second){
                        // if already node exists in heap, we will first delete existing one.
                        auto tmp = heap.find({dist[i.first], i.first});
                        if(tmp!=heap.end()){
                            heap.erase(tmp);
                        }

                        // then add the same node, with updated distance.
                        dist[i.first] = d + i.second;
                        heap.insert({dist[i.first], i.first});
                    }
                }
            }
            return dist;
        }
};

int main(){
    vector<vector<int>> edges = {
        {0, 1, 7},
        {0, 2, 1},
        {0, 3, 2},
        {1, 2, 3},
        {1, 3, 5}, 
        {1, 4, 1},
        {3, 4, 7}
    };

    int v = 5;

    Graph G = Graph(v);

    for(auto i: edges){
        G.addEdge(i[0], i[1], i[2]);
    }

    vector<int> ans = G.Dijikstra(0);

    for(int i: ans){
        cout << i << " ";
    }

    return 0;
}