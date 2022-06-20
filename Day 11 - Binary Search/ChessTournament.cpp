#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// will check can C roommates can be kept in n rooms with difference of atleast mid in their positions!!!
// O(N) Time
bool isPossible(int n, int c, vector<int> pos, int mid){
    // Placing the first player.
    int i=pos[0]; 
    c--;
    // will start loop from second player.
    for(int j=1; j<n; j++){
        // if difference is greater than or equal to mid then we will place player in jth room.
        if(pos[j]-i >= mid){
            i = pos[j];
            c--;
            // if no player remains.
            if(!c) return true;
        }
    }
    return false;
}

// Time Complexity: O(NLogN) + O(NLog(MaxDiff)).
// Space Complexity: O(1).
int maxMinDifference(vector<int> pos, int n, int c){
    // Sorting -- O(NLogN) Time
    sort(pos.begin(), pos.end());

    // Binary search to find maximum possible difference.
    int low=1, high=pos[n-1] - pos[0];
    while(low <= high){
        int mid = (low+high) >> 1;
        if(isPossible(n, c ,pos, mid)){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }

    return high;
}

int main(){
    cout << maxMinDifference({1, 2, 3, 4, 6}, 5, 3);
    return 0;
}