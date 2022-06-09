#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N^2)
vector<vector<int>> PascalTriangle(int n){
    vector<vector<int>> triangle;
    triangle.push_back({1});
    for(int i=1; i<n; i++){
        vector<int> prev(triangle[i-1].begin(), triangle[i-1].end());
        vector<int> curr = {1};
        for(int j=1; j<prev.size(); j++){
            // using previous row to build current row.
            curr.push_back(prev[j] + prev[j-1]);
        }
        curr.push_back(1);
        triangle.push_back(curr);
    }

    return triangle;
}

int main(){
    int n = 4;
    vector<vector<int>> triangle = PascalTriangle(n);
    for(auto i: triangle){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}