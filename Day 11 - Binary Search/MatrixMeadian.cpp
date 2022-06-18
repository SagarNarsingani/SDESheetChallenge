#include <iostream>
#include <vector>
using namespace std;

int count (vector<int> row, int n){
    int s=0, e=row.size()-1;
    int mid = (s+e)/2;
    while(s<=e){
        // cout << s << " : " << e  << " : " << endl;
        if(row[mid] <= n){
            s = mid+1;
        } else {
            e = mid-1;
        }
        mid = (s+e)/2;
    }

    return s;
}

// Time Complexity: O(N*LogM*Log 10^9).
// Space Complexity: O(1).
int GetMatrixMeadian(vector<vector<int>> mat){
    // Starting with given range of numbers.
    int i = 0, j=100000;
    int n = mat.size(), m=mat[0].size();
    // half numbers should be before meadian and half after it.
    int half = (m*n)/2;
    // Binary Search.
    while(i<=j){
        // find middle of current range.
        int mid = i + (j-i)/2;

        // counting how many numbers (less than and equal to) mid are present in matrix.
        int cnt = 0;
        for(auto row: mat){
            cnt = cnt + count(row, mid);
        }

        // if the count is greater than half, we need to reduce upper bound,
        // else we should increase lowerbound.
        if(cnt > half){
            j = mid-1;
        } else {
            i = mid + 1;
        }
    }

    // lowe bound will point to our meadian.
    return i;
}

int main(){
    vector<vector<int>> mat = {
        {2, 6, 9},
        {1, 5, 11},
        {3, 7, 8}
    };

    cout << GetMatrixMeadian(mat);
    return 0;
}