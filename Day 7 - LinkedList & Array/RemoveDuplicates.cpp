#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(1).
int RemoveDuplicates(vector<int> arr){
    int n = arr.size();
    if(n==0 or n==1) return n;

    int i = 0, j=1, dup=0;

    while(i<n){
        // till element is same as previous one we move forward.
        while(j<n and arr[i]==arr[j]){
            j++;
            dup++;
        }
        // will move i based on duplicate elements we skipped.
        i = i+(j-i);
        j++;    // we have to make j = i+1;
    }

    return n-dup;   // new length = total - duplicate.
}

int main(){
    cout << RemoveDuplicates({1, 1, 1, 2, 2, 3, 3, 3, 4, 4});
    return 0;
}