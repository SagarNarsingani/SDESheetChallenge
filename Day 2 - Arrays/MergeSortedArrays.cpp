#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// Time Complexity: O((n+m) * Log(n+m))
// Space Complexity: O(1)
void MergeSortedArrays(vector<int> &arr1, vector<int> arr2, int m, int n){
    
    // add all elements from arr2 to arr1 (in the reserved space).
    for(int i=0; i<n; i++){
        arr1[m+i] = arr2[i];
    }

    // average length of arrays.
    int gap = ceil((float)(m+n)/2);
    while(gap >= 1){
        int i=0, j=gap;
        while(j<(m+n)){
            if(arr1[i] > arr1[j]){
                swap(arr1[i], arr1[j]);
            }
            i++, j++;
        }
        if (gap==1) gap = 0;
        else gap = ceil((float) gap/2);
    }

    return;
}

// Time Complexity: O(m+n)
void Merge(vector<int> &arr1, vector<int> arr2, int m, int n){
    int i = m-1, j=n-1, k=m+n-1;
    while(i>=0 and j>=0){
        if(arr1[i]>=arr2[j]){
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }

    while(j>=0){
        arr1[k--] = arr2[j--];
    }
    while(i>=0){
        arr1[k--] = arr1[i--];
    }

    return;
}

int main(){
    vector<int> arr1 = {1, 4, 6, 10, 0, 0};
    vector<int> arr2 = {2,5};
    MergeSortedArrays(arr1, arr2, 4, 2);

    for(int i: arr1){
        cout << i << " ";
    }
    return 0;
}