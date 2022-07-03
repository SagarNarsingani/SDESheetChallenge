#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(max(a, b)).
// Space Complexity: O(1).
int compareVersions(string a, string b){
    int i=0, j=0, lna = a.length(), lnb = b.length();
    // till both versions end.
    while(i<lna || j<lnb){
        // default values of current part (string seprated by '.' are considered as parts).
        long long int n1=0, n2=0;
        // finding value of current part of version a, if present.
        while(i<lna && a[i]!='.'){
            n1 = n1*10 + (a[i]-'0');
            i++;
        }

        // finding value of current part of version b, if present.
        while(j<lnb && b[i]!='.'){
            n2 = n2*10 + (b[i]-'0');
            j++;
        }

        // comparing current part.
        if(n1>n2){
            return 1;
        } else if(n1<n2){
            return -1;
        }

        // a[i] and b[j] are at '.' or at the end here, so we will move one step forward.
        i++;
        j++;
    }

    return 0;
    
}

int main(){
    cout << compareVersions("3", "3.1.0");
    return 0;
}