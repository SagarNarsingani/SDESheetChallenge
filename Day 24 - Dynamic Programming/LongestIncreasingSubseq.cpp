#include <iostream>
#include <vector>
using namespace std;

// Dynamic Programming.
// Time Complexity: O(N^2).
// Space Complexity: O(N).
int getMaxSubSeq(vector<int> seq, int n){
    int maxLen = 1;

    // dp[i] will show max length of subsequence we can form using ith element.
    vector<int> dp(n, 1);

    for(int i=1; i<n; i++){
        // based on the subsequences made by previous elements,
        // we extand those subsequences using current element.
        for(int j=0; j<i; j++){
            if(seq[j] < seq[i]){
                dp[i] = max(dp[i], dp[j]+1);
                maxLen = max(maxLen, dp[i]);
            }
        }
    }

    return maxLen;
}

// Time Complexity: O(N * N) -- on average.
// Space Complexity: O(N).
int getLongestIncSubseqLen(vector<int> arr, int n){
    vector<int> tmp;
    tmp.push_back(arr[0]);

    int len = 1;

    for(int i=1; i<n; i++){
        if(arr[i] > tmp.back()){
            tmp.push_back(arr[i]);
            len++;
        } else {
            int index = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
            tmp[index] = arr[i];
        }
    }

    return len;
}

int main(){
    vector<int> seq = {5, 4, 11, 1, 16, 8};
    cout << getLongestIncSubseqLen(seq, seq.size());
    return 0;
}