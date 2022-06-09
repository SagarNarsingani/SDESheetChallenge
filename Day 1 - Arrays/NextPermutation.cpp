#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &arr){
    int n = arr.size();
    int i, j, k;
    // find an element(i) which is less than it's next element.
    for(k=n-2; k>=0; k--){
        if(arr[k]<arr[k+1]){
            i=k;
            break;
        }
    }

    // if there is no such element(i) exists.
    if(k<0){
        reverse(arr.begin(), arr.end());
        return;
    }

    // from backwards find an element(j) which is greater than element(i).
    for(k=n-1; k>=0; k--){
        if(arr[k]>arr[i]){
            j=k;
            break;
        }
    }

    // swap i and j.
    swap(arr[i], arr[j]);

    // reverse array after ith index (making array lower in permutation).
    reverse(arr.begin()+i+1, arr.end()); 

    return;
}

int main(){
    vector<int> arr = {1, 2, 4, 5, 3};
    nextPermutation(arr);
    for(int i: arr){
        cout << i << " ";
    }
    return 0;
}