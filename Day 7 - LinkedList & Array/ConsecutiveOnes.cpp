#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(No. of Zeroes).
int ConsecutiveOnes(vector<int> arr, int k){
    int n = arr.size();
    if(n==0) return 0;
    int zeros = count(arr.begin(), arr.end(), 0);
    if(zeros<=k) return n;
    if(zeros>=k and k>=n) return n;

    // storing indices of zeros.
    vector<int> zeroes;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            zeroes.push_back(i);
        }
    }

    // j points at first index of zero.
    int tmp = k, maxLen=INT_MIN, len=0, j=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            if(tmp){
                tmp--;
                len++;
            } else {
                // moving to next zero by discarding previous one.
                len = (i-zeroes[j++]);
            }
        } else {
            len++;
        }
        
        // tracking the maximum length.
        maxLen = max(len, maxLen);
    }

    return maxLen;
}

int main(){
    cout << ConsecutiveOnes({1, 1, 0, 1, 1}, 2);
    return 0;
}