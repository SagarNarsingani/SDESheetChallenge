#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(1).
int getMaxProduct(vector<int> &arr, int n){
    int product = 1;
    int opt1 = arr[0], opt2 = arr[n-1];
    bool zeros=false;

    // will neglet elements from end.
    for(int i: arr){
        // if at any time a product becomes zero, we reset our cummulative product to 1.
        if(i==0) {
            zeros = true;
            product = 1;
            continue;
        }
        product = product * i;
        opt1 = max(i, max(product, opt1));
    }

    // will neglect elements from start.
    product = 1;
    for(int i=n-1; i>=0; i--){
        // if at any time a product becomes zero, we reset our cummulative product to 1.
        if(arr[i]==0) {
            zeros = true;
            product=1;
            continue;
        }
        product = product * arr[i];
        opt2 = max(arr[i], max(product, opt2));
    }
    
    // if zero is present in array, and opt1 and opt 2 are negative.
    // e.g., -1 0 -2 -- in this case answer will be 0.
    if(zeros)
        return max(max(opt1, opt2), 0);
    else
        return max(opt1, opt2);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << getMaxProduct(arr, n);

    return 0;
}