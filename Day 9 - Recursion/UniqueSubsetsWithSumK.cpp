#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getSubsets(vector<int> nums, int i, int n, int k, vector<int> subset, vector<vector<int>> &subsets){
    if(k==0){
        subsets.push_back(subset);
        return;
    }

    for(int j=i; j<n; j++){
        // skipping the same numbers as we have to take unique elements.
        if(j>i and (nums[j]==nums[j-1])) continue;
        // as nums is sorted, once we encounter greater number than target we will break the loop.
        if(nums[j] > k) break;
        subset.push_back(nums[j]);
        getSubsets(nums, j+1, n, k-nums[j], subset, subsets);
        subset.pop_back();  // backtracked.
    }

    return;
}

// Time Complexity: O(NLogN) + O(2^N)
// Space Complexity: O(2^N) + O(k) -- k is avg length of subset.
vector<vector<int>> UniqueSubsetsWithSumK(vector<int> nums, int target){
    // O(2^N) Space.
    vector<vector<int>> subsets;
    // O(k) Space.
    vector<int> subset;

    // O(NLogN) Time.
    sort(nums.begin(), nums.end());

    int n = nums.size();

    getSubsets(nums, 0, n, target, subset, subsets);

    // O(2^N) Time -- can be ignored, just printing the ans.
    for(auto i: subsets){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return subsets;
}

int main(){
    UniqueSubsetsWithSumK({10, 1, 2, 7, 6, 1, 5}, 8);
    return 0;
}