#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// O(2^N) Time.
// O(k) Space.
void getSubsets(vector<int> nums, int i, int n, vector<int> subset, vector<vector<int>> &subsets, int k){
    // base case -- when required sum is reached to 0 and no element now remains to include.
    if(k==0 and i==n){
        subsets.push_back(subset);
        return;
    }

    // no element now remains to include but k is still greater than 0.
    if(i==n){
        return;
    }

    // pushing current number in subset.
    subset.push_back(nums[i]);
    getSubsets(nums, i+1, n, subset, subsets, k-nums[i]);   // Note that we are also reducing the k here for next function call.

    // poping current element back once it is considered as an element of all it's subsets.
    subset.pop_back();
    getSubsets(nums, i+1, n, subset, subsets, k);

    return;
}

// Time Complexity: O(2^N).
// Space Complexity: O(2^N) + O(k) -- k is avg subset length.
vector<vector<int>> SubsetsWithSumK(vector<int> nums, int k){
    // O(k) Space -- k is avg subset length.
    vector<int> subset;
    // O(2^N) Space.
    vector<vector<int>> subsets;

    int n = nums.size();

    // Will change the index -- according to problem statement this should not be done.
    // sort(nums.begin(), nums.end());

    getSubsets(nums, 0, n, subset, subsets, k);

    // Printing -- can be ignored -- takes O(2^N) Time.
    for(auto i: subsets){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return subsets;
}

int main(){
    SubsetsWithSumK({5, -1, 8, 2, 7, 0}, 7);
    return 0;
}