#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N * M).
// Space Complexity: O(N).
// Bellman-Ford Algorithm.
int getMinDist(vector<vector<int>> &edges, int src, int dest, int n, int m){
    int inf = 1000000000;
    vector<int> dist(n+1, inf);

    // distance of 1 node is fixed.
    dist[src] = 0;

    // remaining n-1 will be fixed here.
    // in worst case source of each edge will be different.
    // and in that case in each iteration we will update the distance of any one(at least) node.
    for(int j=0; j<n-1; j++){
        for(auto i: edges){
            // only take source of current edge if it is not having infinite distance.
            if( dist[i[0]]!=inf && (dist[i[1]] > dist[i[0]]+i[2]) ){
                dist[i[1]] = dist[i[0]] + i[2];
            }
        }
    }

    // optional.
    for(auto i: edges){
        if( dist[i[0]]!=inf && (dist[i[1]] > dist[i[0]]+i[2]) ){
            // if we come here we can say that there exists a negative cycle in graph
            // and this algorithm doesn't work in this case.
            cout << "Algorithm Failed: Negative Cycle Found";
            return -1;
        }
    }

    return  dist[dest];
}

int main(){
    vector<vector<int>> edges = {
        {3, 8, 31565},
        {2, 8, 47804},
        {3, 7, -75494},
        {5, 4, 8701},
        {5, 3, -25732},
        {2, 7, -19460},
        {3, 1, -32618},
        {1, 8, 8159},
        {3, 2, -16280},
        {5, 8, 33369},
        {4, 6, 51704}
    };

    cout << getMinDist(edges, 1, 7, 8, 11);
    return 0;
}

// 1000000000
// 2147483647