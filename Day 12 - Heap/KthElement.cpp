#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// O((n-k)LogK) Time
int GetKthMinimum(vector<int> arr, priority_queue<int> maxHeap, int k){
    for(int i=k; i<arr.size(); i++){
        if(arr[i] < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    return maxHeap.top();
}

// O((n-k)LogK) Time
int GetKthMaximum(vector<int> arr, priority_queue<int, vector<int>, greater<int>> minHeap, int k){
    for(int i=k; i<arr.size(); i++){
        if(arr[i] > minHeap.top()){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    return minHeap.top();
}

// Time Complexity: O(K + (N-K)LogK).
// Space Complexity: O(2*K). -- for both heaps.
vector<int> GetKthElements(vector<int> arr, int k){
    vector<int> ans;

    // Getting Kth Maximum.
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<k; i++){
        minHeap.push(arr[i]);
    }
    ans.push_back(GetKthMaximum(arr, minHeap, k));
   
    // Getting Kth Minimum.
    priority_queue<int> maxHeap;
    for(int i=0; i<k; i++){
        maxHeap.push(arr[i]);
    }
    ans.push_back(GetKthMinimum(arr, maxHeap, k));

    return ans;
}

int main(){
    vector<int> kthElements = GetKthElements({4, 3, 2, 1, 7, 6, 8}, 3);

    for(int i: kthElements)
        cout << i << " ";
    return 0;
}