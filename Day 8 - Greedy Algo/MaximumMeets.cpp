#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(NLogN).
// Space Complexity: O(2*N).
vector<int> MaximumMeets(vector<int> strt, vector<int> end){
    int n = strt.size();
    
    if(n==0) return {};
    if(n==1) return {1};

    vector<vector<int>> meets;
    for(int i=0; i<n; i++){
        meets.push_back({end[i], i+1});
    }

    // O (NLogN) : Sorting based on the ending time of the meeting.
    sort(meets.begin(), meets.end());

    vector<int> ans;
    int j=0;
    ans.push_back(meets[j][1]);
    // O (N)
    for(int i=1; i<n; i++){
        int curr = strt[meets[i][1]-1];
        if(curr > meets[j][0]){
            j=i;
            ans.push_back(meets[j][1]);
        }
    }

    return ans;
}

int main(){
    vector<int> ans = MaximumMeets({4, 1, 5, 7, 9, 6, 7, 2, 1, 8}, {14, 11, 18, 10, 19, 19, 14, 18, 7, 16});
    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}

 
