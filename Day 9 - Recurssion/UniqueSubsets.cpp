#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Time Complexity: O(2^N * KLogK) -- K is avg length of each subset.
void GetUniqueSubsets(vector<int> nums, int i, int n, vector<int> subset, set<vector<int>> &subsets){
    if(i==n){
        // O(K log K)
        sort(subset.begin(), subset.end());
        subsets.insert(subset);
        return;
    }

    // select current element for subset.
    subset.push_back(nums[i]);
    GetUniqueSubsets(nums, i+1, n, subset, subsets);

    // don't select current element for subset.
    subset.pop_back();  // backtracking
    GetUniqueSubsets(nums, i+1, n, subset, subsets);

    return;
}

// Time Complexity: O(2^N * KlogK) + O(2^N).
// Space Complexity: O(2^(N+1)) + O(k * 2^N) -- k is avg length of subset. 
// (in each recursive call we will use subset vector of different size).
vector<vector<int>> GetSubsets(vector<int> nums){
    // O(k) Space.
    vector<int> subset;

    // O(2^N) Space.
    vector<vector<int>> ans;
    // O(2^N) Space.
    set<vector<int>> subsets;

    int n= nums.size();

    GetUniqueSubsets(nums, 0, n, subset, subsets);

    // O(2^N) Time -- at max 2^N subsets are possible
    for(auto ss: subsets){
        ans.push_back(ss);
    }

    return ans;
}

int main(){
    vector<vector<int>> subsets = GetSubsets({1, 1, 3});

    for(auto i: subsets){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}