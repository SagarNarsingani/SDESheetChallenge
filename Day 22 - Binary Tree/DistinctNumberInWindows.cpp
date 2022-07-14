#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
vector<int> getDistincts(vector<int> arr, int k){
    // if the stream it self have numbers less than k.
    if(arr.size() < k) return {};

    vector<int> ans;
    unordered_map<int, int> dist;

    // will traverse through first k elements and increase the number of occurence of each number.
    // by default each number's occurence is set to 0.
    for(int i=0; i<k; i++){
        dist[arr[i]]++;
    }

    // push back current size of map (number or unique elements).
    ans.push_back(dist.size());

    // will apply sliding window approach here.
    int j=0;
    for(int i=k; i<arr.size(); i++){
        // remove one occurence of element at start.
        dist[arr[j]]--;
        // if occurence of element at start becomes zero, we will delete it from the map.
        if(dist[arr[j]]==0)
            dist.erase(arr[j]);
        j++;
        // increase the occurence of current element.
        dist[arr[i]]++;
        // size of map will again give us number of distinct elements.
        ans.push_back(dist.size());
    }

    return ans;
}

int main(){
    vector<int> ans = getDistincts({1, 2, 3, 4, 3}, 3);
    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}