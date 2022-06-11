// Pending...

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<pair<int, int>> PairSum(vector<int> arr, int sum){
    unordered_set<int> set;
    sort(arr.begin(), arr.end());
    vector<pair<int, int>> pairs;
    for(int i: arr){
        int temp = sum-i;
        if(set.find(temp)!=set.end()){
            pairs.push_back({temp, i});
        }
        set.insert(i);
    }

    sort(pairs.begin(), pairs.end());

    return pairs;
}

int main(){
    vector<pair<int, int>> pairs = PairSum({2, -3, 3, 3, -3, -2}, 0);
    for(auto i: pairs){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}