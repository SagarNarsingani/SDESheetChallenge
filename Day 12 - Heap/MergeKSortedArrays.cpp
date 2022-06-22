#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

// class of each node that is stored in heap.
// data represents value, i-array, j-element no in array i.
class Node{
    public: 
        int data, i, j;

        Node(int d, int i, int j){
            data = d;
            this->i = i;
            this->j = j;
        }

        // operator overloading.
        friend bool operator<(const Node &parent, const Node &child){
            return child.data < parent.data;

        }
};

// Time Complexity: O(N*kLogk) + O(kLogk).
// Space Complexity: O(k).
vector<int> MergeKSortedArrays(vector<vector<int>> arrs, int k){
    // at a time heap will only store K elements.
    // O(k) Space.
    priority_queue<Node> heap;
    vector<int> ans;

    // pushing first element of each array(with their coordinates), as a Node object in heap.
    // O(KLogK) time.
    // Remaining elements to be sorted are: (N-k)*k
    for(int i=0; i<k; i++){
        heap.push(Node(arrs[i][0], i, 0));
    }

    // removing minimum element from heap.
    // storing it in results.
    // pushing next element from same array (if available) in heap.
    // O((N-k)*kLogK) ~ Log(N*kLogk).
    while(!heap.empty()){
        Node top = heap.top();
        ans.push_back(top.data);
        heap.pop();
        if((top.j+1) < arrs[top.i].size())
            heap.push(Node(arrs[top.i][top.j+1], top.i, top.j+1));
    }

    return ans;
}

int main(){
    vector<vector<int>> arrs = {
        {1, 3, 5, 7, 9},
        {2, 4, 6, 8, 10}
    };

    vector<int> ans = MergeKSortedArrays(arrs, 2);

    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}