#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void GetPermutation(string &num, int i, int n, vector<string> &permutations){
    if(i==n) {
        permutations.push_back(num);
        return;
    }

    // O(N * N!) -- outer loop is running for N times and inner one is running for N! times.
    for(int j=i; j<n; j++){
        swap(num[i], num[j]);
        GetPermutation(num, i+1, n, permutations);
        swap(num[i], num[j]);
    }

    return;
}

// Time Complexity: O(N! Log N!) + O(N * N!).
// Space Complexity: O(N!).
string kthPermutation(int n, int k){
    string num= "";
    for(int i=1; i<=n; i++){
        num = num + to_string(i);
    }

    // O(N!) Space.
    vector<string> permutations;

    GetPermutation(num, 0, n, permutations);

    // O(N! Log N!) Time.
    sort(permutations.begin(), permutations.end());

    return permutations[k-1];
}

// using inbuilt function.
string kthPermutationInbuilt(int n, int k){
    string num= "";
    for(int i=1; i<=n; i++){
        num = num + to_string(i);
    }

    k = k-1;
    while(k--){
        next_permutation(num.begin(), num.end());
    }

    cout << num << endl;

    return num;
}


// Space Complexity: O(N).
// Time Complexity: O(N^2).
// Most Optimized.
string kthPermutationOpt(int n, int k){
    vector<int> nums;
    int fact = 1;       // this will basicaly used as (n-1)! as we are fixing one element in each iteration.
    for(int i=1; i<n; i++){
        nums.push_back(i);
        fact = fact * i;
    }
    nums.push_back(n);

    k = k-1; // as we are working with 0-based indexing.

    string ans = ""; 
    // this will run for N(till all numbers get selected) times hence -- O(N^2).
    while(true){
        ans = ans + to_string(nums[(k/fact)]);   // fact shows number of elements in each block and hence k/fact will give us block number.

        // O(N) Time.
        nums.erase(nums.begin() + (k/fact));    // removing already selected number.

        if(nums.size()==0) break;   // till all numbers are used.

        k = k%fact; // we are going inside the block that we found earlier, in which k will be k%fact.

        fact = fact / nums.size();  // fact was (n-1)! and now nums.size() is also (n-1) as we erased one element, hence this will result in (n-2)!
    }

    return ans;
}

int main(){
    cout << kthPermutationInbuilt(3, 6);
    return 0;
}