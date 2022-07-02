#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Knuth–Morris–Pratt algorithm.
// Time Complexity: O(N+M).
// Space Complexity: O(M).
bool KMPAlgorithm(string str, string pat){
    int m = pat.length();
    // longest prefix suffix.
    vector<int> lps(m, 0);

    // calculating lps for pattern string.
    int i=1, len=0;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i] = len;
            i++; 
        } else {
            // don't make len 0 directly.
            // suppose in pattern aaacaaaac, you are at index i=6 at this time len=3.
            // now if you make len = 2 the lps[6] = 3 instead of 0(in case you make len=0).
            if(len!=0){
                len = lps[len-1];
            } else {
                // len is 0 already, we can't do anything.
                lps[i] = 0;
                i++;
            }
        }
    }

    i=0;    // pointing to pattern.
    int j = 0;  // pointing to str.
    int n = str.length();
    while(j<n){
        // in case of match.
        if(str[j]==pat[i]){
            i++;
            j++;
            if(i==m) return true;
        } else {
            // in case of mismatch, we won't go back in str, we only go back in pat, if i!=0.
            if(i!=0)
                i = lps[i-1];
            else    // else move forward in str.
                j++;
        }
    }

    return false;
}

int main(){
    cout << KMPAlgorithm("cgfgfc", "cfg");
    return 0;
}