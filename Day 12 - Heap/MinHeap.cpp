#include <iostream>
#include <vector>
using namespace std;

// inserting new element at its appropriate position.
// O(LogN) Time.
void insert(vector<int> &heap, int x){
    heap.push_back(x);

    int child = heap.size()-1;
    int parent = child/2;

    while(parent>0){
        if(heap[child] < heap[parent]){
            swap(heap[child], heap[parent]);
            child = parent;
            parent = child/2;
        } else {
            break;
        }
    }

    return;
}

// once minimum element is removed from heap, we need to heapify the remaining tree/heap.
void heapify(vector<int> &heap){
    int n = heap.size();

    if(n==1) return;

    int parent = 1;
    int firstChild = 2*parent, secondChild = 2*parent + 1;

    while(secondChild < n){
        if((heap[parent] <= heap[firstChild]) and (heap[parent] <= heap[secondChild])){
            return;
        }

        if((heap[firstChild] < heap[parent]) and (heap[firstChild] < heap[secondChild])){
            swap(heap[firstChild], heap[parent]);
            parent = firstChild;
        } else {
            swap(heap[secondChild], heap[parent]);
            parent = secondChild;
        }

        firstChild = 2*parent, secondChild = 2*parent + 1;
    }

    if(firstChild==n-1 and (heap[firstChild] < heap[parent])){
        swap(heap[firstChild], heap[parent]);
    }

    return;
}

// poping the minimum element from the heap and heapifying the remaining heap.
// O(LogN) Time and O(1) Space.
int pop(vector<int> &heap){
    int top = heap[1];

    int n = heap.size();
    swap(heap[1], heap[n-1]);
    heap.pop_back();

    heapify(heap);

    return top;
}

// Driver Function: Runs given queries on the heap and returns expected output.
// O(N) time and O(N) space -- which are inevitable.
vector<int> MinHeap(int n, vector<vector<int>> q){

    vector<int> heap;
    vector<int> ans;
    heap.push_back(-1);

    for(vector<int> Q: q){
        // cout << " here " ;
        if(Q[0]==0){
            insert(heap, Q[1]);
        } else {
            ans.push_back(pop(heap));
        }
    }

    return ans;
}

int main(){

    vector<int> ans = MinHeap(3, {{0, 2}, {0, 5}, {0, 7}, {0, 1}, {0, 4}, {1}, {1}, {1}});

    for(int i: ans){
        cout << i << " ";
    }

    return 0;
}