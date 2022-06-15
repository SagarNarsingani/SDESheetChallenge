#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(NLogN).
// Space Complexity: O(2*N).
int MaximumActivities(vector<int> strt, vector<int> end){
    int n = strt.size();
    
    if(n==0 or n==1) return n;

    vector<vector<int>> acts;
    for(int i=0; i<n; i++){
        acts.push_back({end[i], strt[i]});
    }

    // O (NLogN) : Sorting based on the ending time of the meeting.
    sort(acts.begin(), acts.end());

    int ans=1;
    int j=0;
    // O (N)
    for(int i=1; i<n; i++){
        if(acts[i][1] >= acts[j][0]){
            j=i;
            ans++;
        }
    }

    return ans;
}

int main(){
    cout << MaximumActivities({1, 6, 2, 4}, {2, 7, 5, 8});
    return 0;
}

 
