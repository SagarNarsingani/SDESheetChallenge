#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(1).
int kadane_algo(vector<int> arr){
    int sum = 0, maxSum = 0;
    for(int i: arr){
        sum = sum + i;
        // if sum becomes less than zero.
        if(sum < 0)
            sum = 0;
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main(){
    vector<int> arr = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    cout << kadane_algo(arr);
    return 0;
}