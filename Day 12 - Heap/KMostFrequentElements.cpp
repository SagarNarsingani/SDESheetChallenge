#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

// custom comparator for min heap.
struct compare{
    bool operator()(pair<int, int> parent, pair<int, int> child){
        // first contains count of element.
        if(parent.first != child.first){
            return child.first < parent.first;
        }

        // second contains element itself.
        return child.second > parent.second;
    }
};


// Time Complexity: O(N) + O(XLogK) + O(K)
// Space Complexity: O(X) + O(K).
// X is total number of unique elements.
vector<int> GetKMostFreqElements(vector<int> arr, int k){
    int n = arr.size();

    // map will be used to count and store the occurances of all unique elements of arr.
    unordered_map<int, int> map;    // O(X) Space -- X is unique number of elements in arr.
    // creating min heap of (count, element) pairs.
    // O(K) Space
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;
    vector<int> res;

    // counting the occurences.
    // O(N)
    for(int i: arr){
        map[i]++;
    }

    // creating heap.
    int i=0;
    // O(XLogK) Time -- X is number of unique elements in arr.
    for(auto p: map){
        // first k elements are directly pushed into heap.
        if(i<k){
            heap.push(make_pair(p.second, p.first));
            i++;
        } else {    // next (n-k) elements are only pushed if they have appropriate count.
            int top = heap.top().first;
            if(p.second > top){
                // will maintain size of heap as k.
                heap.pop();
                heap.push(make_pair(p.second, p.first));
            }
        }
    }

    // creating vector(output) from heap.
    // O(KLogK)
    while(!heap.empty()){
        cout << heap.top().first << " " << heap.top().second << endl;
        res.push_back(heap.top().second);
        heap.pop();
    }

    // sorting the output res vector as it was asked.
    // O(KLogK)
    sort(res.begin(), res.end());

    return res;
}
int main(){
    GetKMostFreqElements({1, 2, 2, 3}, 2);
    return 0;
}