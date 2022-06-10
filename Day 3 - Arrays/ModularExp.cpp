#include <iostream>
using namespace std;

// Time Complexity: O(Log n),
// Space Complexity: O(1).
// Types of variables is the main thing to watch out for.
int ModularExp(int x, int n, int m){
    long long ans=1;
    long long base = (long long) x;
    base = base%m;

    if(base==0) return 0;

    while(n>0){
        // if N is odd in X^N, we will handle X seprately and X^N-1 (N-1 will be even) saprately.
        if(n&1)
            ans = (ans*base)%m;
        
        base = (base*base)%m;
        n = n >> 1;
    }

    return (int) ans%m;
}

int main(){
    cout << ModularExp(10000000, 2, 10000001);
    return 0;
}