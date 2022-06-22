#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(NLogN) -- N because of for loop and LogN because of deletion from tree.
// Space Complexity: O(N).
void GetRunningMedian(vector<int> arr, int n){

    // will maintain two heaps - one max and one min.
    priority_queue<int> left;       // max heap
    priority_queue<int, vector<int>, greater<int>> right;   // min heap

    // initialy we are taking 1st element as median and pushing it in max heap.
    int meadian = arr[0];
    left.push(arr[0]);
    for(int i=1; i<=n; i++){
        // printing current median.
        cout << meadian << " ";

        if(i==n) break;

        // the difference between two heaps in size can be at max 1 (when there are odd number of elements).
        // otherwise we keep half of them in left(max) and half in right(min).
        int diff = left.size() - right.size();
        int curr = arr[i];

        // if both heaps have same number of elements.
        if(diff==0){
            // if currenr element is less than top of left heap (max heap), we push it in left heap.
            // otherwise push it in right heap.
            // the median will be top element of heap having more number of elements.
            if(curr<=left.top()){
                left.push(curr);
                meadian = left.top();
            } else{
                right.push(curr);
                meadian = right.top();
            }
        } else if(diff==1){     // if left heap has one more element than right heap.
            // if current element also belongs to left heap(max), we will take top of it and
            // push it in right as we need to maintain difference of 1 between heaps.
            if(curr<=left.top()){
                left.push(curr);
                right.push(left.top());
                left.pop();
            } else{
                // if current belongs to right we will simply push it in right, now diff will be 0.
                right.push(curr);
            }
            // as number of elements are even now.
            meadian = (left.top() + right.top()) / 2;
        } else {
            // same as diff=1, but will do popping in right.
            if(curr<=left.top()){
                left.push(curr);
            } else{
                right.push(curr);
                left.push(right.top());
                right.pop();
            }
            // as number of elements are even now.
            meadian = (left.top() + right.top()) / 2;
        }
    }

    return;
}

int main(){
    GetRunningMedian({41, 18467, 6334, 26500, 19169, 15724, 11478 }, 7);
    return 0;
}