#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000

// Time Complexity: O(N^3).
// Space Complexity: O(N^2).
// Floyd - Warshall Algorithm.
int getMaxDist(int src, int dest, int n, int m, vector<vector<int>> &edges){
    // make a matrix in which mat[i][j] shows weight to go from i to j.
    vector<vector<int>> mat(n+1, vector<int>(n+1, INF));
    for(auto i: edges){
        mat[i[0]][i[1]] = i[2];
    }
    for(int i=0; i<=n; i++){
        mat[i][i] = 0;
    }

    // take each vertex as intermidiate one-by-one.
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=0; j<=n; j++){
                // if we can take k as intermidiate vertex for i and j,
                // and mat[i][k] + mat[k][j] is less than mat[i][j],
                // then we update current value of mat[i][j].
                if((mat[i][k]!=INF && mat[k][j]!=INF) && (mat[i][k]+mat[k][j] < mat[i][j])){
                    mat[i][j] = mat[i][k]+mat[k][j];
                }
            }
        }
    }

    return mat[src][dest];
}

int main(){
    vector<vector<int>> edges = {
        {2, 1, 3}
    };

    cout << getMaxDist(1, 2, 2, 1, edges);
    return 0;
}