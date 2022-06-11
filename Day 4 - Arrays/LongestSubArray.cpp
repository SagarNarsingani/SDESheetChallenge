#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
int LongestSubArray(vector<int> arr){
    int n = arr.size(), len=0, prefix=0;
    unordered_map<int, int> map;
    map[0] = -1; // we keep -1 index of sum 0 in the map, which will return whole length of subarray.
    for(int i=0; i<n; i++){
        prefix = prefix + arr[i];
        int temp=0;
        // if prefix sum of (i, x) == prefix sum of (x+1, j) it means sum of subarray (i, j) = 0.
        if(map.find(prefix)!=map.end()){
            temp = i - map[prefix];
            len = max(len, temp);
        }
        else map[prefix] = i;
    }
    return len;
}

int main(){
    cout << LongestSubArray({1, 2, -1, -2});
    return 0;
}