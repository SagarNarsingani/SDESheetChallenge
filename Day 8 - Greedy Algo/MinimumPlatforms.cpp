#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// Time Complexity: O(NLogN).
// Space Complexity: O(1).
int MinimumPlatforms(vector<int> at, vector<int> dt){
    int n = at.size();

    // O(NLogN)
    // We basically want to find maximum ranges intersections hence both arrays can be sorted saperately.
    sort(at.begin(), at.end());
    sort(dt.begin(), dt.end());

    // O(N)
    int plt=1, intersections=1;
    int i=1, j=0;
    while(i<n and j<n){
        if(at[i]<=dt[j]){
            intersections++;
            i++;
        } else {
            intersections--;
            j++;
        }

        plt = max(plt, intersections);
    }

    return plt;
}

int main(){

    vector<int> at = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dt = {910, 1200, 1120,1130, 1900, 2000};

    cout << MinimumPlatforms(at, dt);
    return 0;
}