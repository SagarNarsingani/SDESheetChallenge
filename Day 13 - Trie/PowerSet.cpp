#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(2^N).
// Space Complexity: O(N) -- CallStack + Set vector.
void GetPowerSet(vector<int> arr, int i, int n, vector<vector<int>> &res, vector<int> set){
    if(i==n){
        res.push_back(set);
        return;
    }

    // take ith element.
    set.push_back(arr[i]);
    GetPowerSet(arr, i+1, n, res, set);

    // don't take ith element.
    set.pop_back();
    GetPowerSet(arr, i+1, n, res, set);

    return;
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> res;
    int n = arr.size();
    GetPowerSet(arr, 0, n, res, {});

    for(auto i: res){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}