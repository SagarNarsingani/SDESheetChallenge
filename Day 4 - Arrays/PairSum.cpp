#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Time Complexity: O(NLogN).
// Space Complexity: O(N).
vector<pair<int, int>> PairSum(vector<int> arr, int sum){
    sort(arr.begin(), arr.end());
    unordered_map<int, int> map;
    vector<pair<int, int>> pairs;
    for(int i: arr){
        int temp = sum-i;
        if(map.find(temp)!=map.end()){
            int cnt = map[temp];
            while(cnt--)
                pairs.push_back({temp, i});
        }
        map[i]++;
    }

    sort(pairs.begin(), pairs.end());

    return pairs;
}

int main(){
    vector<pair<int, int>> pairs = PairSum({2, -3, 3, 3, -2 }, 0);
    for(auto i: pairs){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}