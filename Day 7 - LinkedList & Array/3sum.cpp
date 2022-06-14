#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(N)
vector<vector<int>> GetPairs(vector<int> arr, int i, int n, int k){
    int s=i, e=n-1;
    vector<vector<int>> pairs;
    while(s<e){
        if(s>i and arr[s]==arr[s-1]) {
            s++;
            continue;
        }
        if(e<n-1 and arr[e]==arr[e+1]) {
            e--;
            continue;
        }
        if(arr[s]+arr[e]>k){
            e--;
        } else if(arr[s]+arr[e]<k){
            s++;
        } else {
            pairs.push_back({arr[s], arr[e]});
            s++, e--;
        }
    }

    return pairs;
}

// Time Complexity: O(N).
// Space Complexity: O(N).
vector<vector<int>> GetTriplets(vector<int> arr, int k){
    vector<vector<int>> triplets;

    // O(NLogN)
    sort(arr.begin(), arr.end());

    int n = arr.size();
    // O(N * N)
    for(int i=0; i<n-2; i++){
        if(i>0 and arr[i]==arr[i-1]) continue;
        vector<vector<int>> pairs = GetPairs(arr, i+1, n, k-arr[i]);
        for(auto pair: pairs){
            triplets.push_back({arr[i], pair[0], pair[1]});
        }
    }

    return triplets;
}

int main(){
    vector<int> arr = {1, 1, 2, 2, 1, 1};
    vector<vector<int>> triplets = GetTriplets(arr, 4);

    for(auto triplet: triplets){
        for(int i: triplet){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}