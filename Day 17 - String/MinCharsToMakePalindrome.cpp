#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
int getNumofCharsNeeded(string s){
    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    // find longest prefix suffix of this concat string.
    string concat = s + "#" + reversed;
    int n = concat.length();
    
    vector<int> lps(n, 0);
    // calculating LPS...
    int i=1, len=0;
    while(i<n){
        if(concat[i]==concat[len]){
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len!=0){
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // the last entry in lps will show how many letters have already been handled.
    return (s.length() - lps.back());
}

int main(){
    cout << getNumofCharsNeeded("wererw");
    return 0;
}