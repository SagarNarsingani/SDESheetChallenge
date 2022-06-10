#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(m+n).
// Space Complexity: O(1)
// Staircase Search
bool isPresent(vector<vector<int>> mat, int target){
    int m = mat.size(), n = mat[0].size();
    int i = 0, j = n-1;
    while((i<m) and (j>=0)){
        if(mat[i][j]==target) return true;

        if(mat[i][j]>target) j--;
        else i++;
    }

    return false;
}

int main(){
    vector<vector<int>> mat = {
        {1, 2, 4},
        {6, 7, 8},
        {9, 10, 34}
    };

    cout << isPresent(mat, 14);
    return 0;
}