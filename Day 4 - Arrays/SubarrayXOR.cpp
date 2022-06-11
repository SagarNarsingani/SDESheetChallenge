#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N).
int subarrayXOR(vector<int> arr, int x){
    unordered_map<int, int> map;
    int n = arr.size(), cnt=0;
    int prefix = 0;
    for(int i=0; i<n; i++){
        // prefix of xor.
        prefix = prefix ^ arr[i];
        // if prefix is same as x then (0, i) will be a subset itself.
        if(prefix==x) cnt++;
        if(map.find(prefix^x)!=map.end()){
            cnt = cnt + map[prefix^x];
        }

        map[prefix]++;
    }

    return cnt;
}

int main(){
    cout << subarrayXOR({4, 3, 1, 2, 4}, 4);
    return 0;
}