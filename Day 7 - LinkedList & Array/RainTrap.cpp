#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N).
int RainTrappedWater(vector<int> arr){
    int n = arr.size();
    vector<int> pre(n, 0);
    vector<int> post(n, 0);

    // finding max from right and max from right.
    pre[0] = arr[0];
    post[n-1] = arr[n-1];
    for(int i=1; i<n; i++){
        pre[i] = max(pre[i-1], arr[i]);
        post[n-i-1] = max(post[n-i], arr[n-i-1]);
    }

    // finding total trapped water.
    int trapped = 0;
    for(int i=0; i<n; i++){
        // cout << i << " : " << abs(min(pre[i], post[i]) - arr[i]) << endl;
        trapped = trapped + abs(min(pre[i], post[i]) - arr[i]);
    }

    return trapped;
}

int main(){
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << RainTrappedWater(arr); 
    return 0;
}