#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity: O(NLogK)
// Space Complexity: O(K)
int getKthLargest(vector<int> &arr, int k){
    if(arr.size() < k) return -1;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<k; i++){
        minHeap.push(arr[i]);
    }

    for(int i=k; i<arr.size(); i++){
        if(arr[i]>minHeap.top()){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    return minHeap.top();
}