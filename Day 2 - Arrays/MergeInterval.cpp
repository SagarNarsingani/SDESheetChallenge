#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Time Complexity: O(N)
// Space Complexity: O(N) -- for storing answers.
vector<vector<int>> MergeIntervals(vector<vector<int>> intervals){
    // sorting according to first element of intervals
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    vector<int> strt (intervals[0].begin(), intervals[0].end());

    // vector<int> temp(2, 0);
    for(int i=1; i<intervals.size();i++){
        // if interval overlaps, we will merge them
        if(intervals[i][0]<=strt[1]){
            strt[1] = max(intervals[i][1], strt[1]);
        } else {    
            ans.push_back(strt);
            strt[0] = intervals[i][0];
            strt[1] = intervals[i][1];
        }
    }
    // pushing the last interval.
    ans.push_back(strt);

    return ans;
}

int main(){
    vector<vector<int>> intervals = MergeIntervals({{1, 4}, {3, 5}, {6, 8}, {10, 12}, {8, 9}});
    for(auto i: intervals){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}