#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

bool PairSum(vector<int> arr, int sum, int i, int n){
    int s=i, e=n-1;
    while (s<e){
        if(arr[s]+arr[e]>sum){
            e--;
        } else if(arr[s]+arr[e]<sum){
            s++;
        } else {
            return true;
        }
    }
    
    return false;
}

bool TripletSum(vector<int> arr, int sum, int i, int n){
    for(int j=i; j<n-2; j++){
        if(PairSum(arr, sum-arr[j], j+1, n)) return true;
    }

    return false;
}

// Time Complexity: O(N^2 * Log N)
// Space Complexity: O(1)
string FourSum(vector<int> arr, int sum){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if (n < 4) return "No";
    for(int i=0; i<n-3; i++){
        if(TripletSum(arr, sum-arr[i], i+1, n)) return "Yes";
    }
    return "No";
}

// Time Complexity: O(N^2)
// Space Complexity: O(N^2) -- storing all pairs in hash table.
string FourSumHash(vector<int> arr, int sum){
    int n = arr.size();
    unordered_map<int, pair<int, int>> map;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            map[arr[i]+arr[j]] = {i, j};
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int temp = arr[i]+arr[j];
            if(map.find(sum-temp)!=map.end()){
                pair<int, int> p = map[sum-temp];
                if((p.first!=i and p.second!=j) and (p.second!=i and p.first!=j)){
                    return "Yes";
                }
            } 
        }
    }

    return "No";
}

int main(){
    cout << FourSumHash({2, 4, 6, 3, 1, 1}, 20);
    return 0;
}