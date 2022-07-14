#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity: O(NLogN).
// Space Complexity: O(N).
vector<int> getRunningMedian(vector<int> data){
    // will store streaming data in two halves.
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    vector<int> ans;

    // data streaming.
    for(int i: data){
        int l = left.size();
        int r = right.size();

        // if both heaps are empty.
        if(!l && !r){
            left.push(i);
            ans.push_back(i);
            continue;
        }

        // if left heap has more elements and current one also belongs to left.
        if((l-r == 1) && left.top()>=i){
            left.push(i);
            right.push(left.top());
            left.pop();
        } else if(l-r == 1){    // if current belongs to right.
            right.push(i);
        } else if((r-l == 1) && right.top()<=i){
            // if right heap has more elements and current one also belongs to right.
            right.push(i);
            left.push(right.top());
            right.pop();
        } else if(r-l == 1){    // if current belongs to left.
            left.push(i);
        } else {    // both heaps are of same size.
            if(left.top()>=i)
                left.push(i);
            else
                right.push(i);
        }

        l = left.size();
        r = right.size();

        // based on the size of both heaps we will calculate current median.
        if(l>r){
            ans.push_back(left.top());
        } else if(r>l){
            ans.push_back(right.top());
        } else {
            ans.push_back((left.top() + right.top())/2);
        }
    }

    return ans;
}

int main(){
    vector<int> medians = getRunningMedian({2, 3, 4});
    for(int i: medians){
        cout << i << " ";
    }
    return 0;
}