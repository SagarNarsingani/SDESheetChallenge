#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(1).
int GetUniqueNumber(vector<int> arr, int n){
    // XORing 2 same number gives 0 and XORing a number with 0 will give number itself.
    int num = 0;
    // XORing all numbers and atlast we will have the unique number.
    for(int i=0; i<n; i++){
        num = num ^ arr[i];
    }

    return num;
}


int main(){
    cout << GetUniqueNumber({1, 1, 2, 3, 3, 4, 4}, 7);
    return 0;
}