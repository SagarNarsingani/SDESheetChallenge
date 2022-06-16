#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(2^N) Time
void getSums(vector<int> arr, vector<int> &sums, int i, int n, int sum){
    if(i==n){
        sums.push_back(sum);
        return;
    }

    // Select Element.
    getSums(arr, sums, i+1, n, sum + arr[i]);
    // Don't Select Element.
    getSums(arr, sums, i+1, n, sum);

    return;

}

// Time Complexity: O(2^N Log (2^N)) + O(2^N)
// Space Complexity: O(2^N) -- to store sums, which is the requirement.
vector<int> SubsetSum(vector<int> arr){
    vector<int> sums;
    int n = arr.size();

    getSums(arr, sums, 0, n, 0);

    // O(2^N Log (2^N)) Time -- sums array will have 2^N elements.
    sort(sums.begin(), sums.end());
    for(int i: sums){
        cout << i << " ";
    }

    return sums;
}

int main(){
    SubsetSum({4, 5});
    return 0;
}