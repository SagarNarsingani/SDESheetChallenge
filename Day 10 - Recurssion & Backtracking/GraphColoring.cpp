#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool isSafe(int node, int clr, int n, vector<int> colors, vector<vector<int>> graph){
    for(int i=0; i<n; i++){
        if(graph[node][i]==1){
            if(colors[i]==clr){
                return false;
            }
        }
    }

    return true;
}

bool Solve(int node, vector<int> colors, vector<vector<int>> graph, int n, int m){
    if(node==n) return true;

    for(int i=1; i<=m; i++){
        if(isSafe(node, i, n, colors, graph)){
            colors[node] = i;
            if(Solve(node+1, colors, graph, n, m)){
                return true;
            }
            colors[node] = 0;
        }
    }

    return false;
}

// Time Complexity: O(N*N*M). -- for N node we are running the for loop of above method, in which isSafe person will run M times.
// isSafe function takes O(N) time and hence for one for loop (O(M) time), total time will be O(M*N).
// and hence for N nodes it will be O(N*N*M).
// Space Complexity: O(M).
string ColorGraph(vector<vector<int>> graph, int m){
    int n = graph.size();
    vector<int> colors(n, 0);
    if(Solve(0, colors, graph, n, m)) return "YES";
    return "NO";
}

int main(){
    vector<vector<int>> graph = {
        {0, 1},
        {1, 0}
    };

    cout << ColorGraph(graph, 1);
    return 0;
}