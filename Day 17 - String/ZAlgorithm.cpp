#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time Complexity: O(M+N).
// Space Complexity: O(M+N).
int zAlgorithm(string str, string pat){
    string concated = pat + "#" + str;
    int n = concated.length();

    vector<int> zArr(n, 0);

    // at start window size is 0.
    int l=0, r=0;   

    for(int i=1; i<n; i++){
        // if current index is out of window.
        if(i > r){
            // set window size as 0.
            l=r=i;
            // increase the window, till we can get chars of prefix/pattern.
            while(r<n && concated[r-l]==concated[r])
                r++;
            // now r is pointing at char, which is not part of prefix.
            zArr[i] = r-l;
            // moving r one step back, so that now it only contains prefix string.
            r--;
        } else {    // if current index is inside window.
            // index of current char in the window. 
            int k = i-l;
            // if z of current index is less than remaining elements in window.
            if(zArr[k] < (r-i+1))
                zArr[i] = zArr[k];
            else{   // else we will update the window.
                l = i;
                while(r<n && concated[r-l]==concated[r])
                    r++;
                zArr[i] = r - l;
                r--;
            }
        }
    }

    // will count all elements that are equal to pattern length in Z array.
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(zArr[i]==pat.length())
            cnt++; 
    }

    return cnt;
}

int main(){
    cout << zAlgorithm("zzzzyz", "zz");
    return 0;
}