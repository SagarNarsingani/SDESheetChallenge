#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Space Complexity: O(N).
class KthLargest{
    public:
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // in min heap of size k, k-1 large elements will be below the top and kth will be on top.
        // Time Complexity: O(NLogK)
        KthLargest(int k, vector<int> &arr){
            for(int i=0; i<k; i++){
                minHeap.push(arr[i]);
            }

            for(int i=k; i<arr.size(); i++){
                if(arr[i]>minHeap.top()){
                    minHeap.pop();
                    minHeap.push(arr[i]);
                }
            }
        }

        // time complexity: O(LogN).
        void add(int num){
            // if new num is greater than top of min heap, we will replace the top with next greater element.
            if(num>minHeap.top()){   
                minHeap.pop();
                minHeap.push(num);
            }
        }
        
        // Just return top element from heap.
        // Time Complexity: O(1).
        int getKthLargest(){
            if(!minHeap.empty()){
                return minHeap.top();
            }

            return -1;
        }
};