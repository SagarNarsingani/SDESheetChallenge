#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <utility>
using namespace std;

// Time Complexity: O(NLogN).
// Space Complexity: O(N).
vector<int> GetKSumComb(vector<int> a, vector<int> b, int k){    
    // O(LogN) Time -- Sorting
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int n = a.size();
    vector<int> ans;

    // will store pairs of (sum, indices).
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    // to store pairs that are visited.
    set<pair<int, int>> visited;

    // pushing the pair with max sum (a[n-1], b[n-1]).
    maxHeap.push({a[n-1]+b[n-1], {n-1, n-1}});
    // making (n-1, n-1) visited.
    visited.insert({n-1, n-1});

    // This will run for K times, each time it will give sum from the top of heap.
    // O(KLogN) Time and O(N) space (as K's worst value is N).
    for(int cnt=0; cnt<k; cnt++){
        pair<int, pair<int, int>> top = maxHeap.top();
        maxHeap.pop();

        // storing current sum inside answer.
        ans.push_back(top.first);
        
        // here we are given that k<=n, hence we are not putting boundaries like
        // (i-1)>=0 and (j-1)>=0, as till we reach there we already would have made N pairs.
        // which are enough.

        // One time i->j and one time j->i, hence pairs can repeats
        // because of this only we are using set here.

        // storing pair (i-1, j) in heap and set.
        int i = top.second.first , j = top.second.second;
        if(visited.find({i-1, j})==visited.end()){
            maxHeap.push({a[i-1]+b[j], {i-1, j}});
            visited.insert({i-1, j});
        }

        // storing pair (i, j-1) in heap and set.
        if(visited.find({i, j-1})==visited.end()){
            maxHeap.push({a[i]+b[j-1], {i, j-1}});
            visited.insert({i, j-1});
        }
    }

    return ans;
}

int main(){
    vector<int> ans = GetKSumComb({1, 3, 10}, {6, 4, 2}, 3);

    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}