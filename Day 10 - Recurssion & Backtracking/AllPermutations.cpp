#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void GetPermutations(string s, int i, int n, vector<string> &permutations){
    if(i==n){
        permutations.push_back(s);
        return;
    }

    for(int j=i; j<n; j++){
        swap(s[i], s[j]);
        GetPermutations(s, i+1, n, permutations);
        swap(s[i], s[j]);
    }

    return;
}


// Time Complexity: O(N * N!)
// Space Complexity: O(N!)
vector<string> GetAllPermutations(string s){
    int n = s.length();

    // O(N!) Space.
    vector<string> permutations;

    // O(N * N!) Time
    GetPermutations(s, 0, n, permutations);

    for(auto i: permutations){
        cout << i << endl;
    }

    return permutations;
}

int main(){
    GetAllPermutations("xyx");
    return 0;
}