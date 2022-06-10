#include <iostream>
using namespace std;

int UniquePaths(int m, int n){
    // as the number of right and down steps will be same for each path,
    // we just need to find permutations of the total number of steps which is m+n-2.
    // formula for permutation will be (m+n-2)!/(n-1)!(m-1)! -- denominator because right repeats (n-1) times and down (m-1) times.
    // how ever this formula is same as the (m+n-2)C(m-1) (or (m+n-2)C(n-1)) -- combinations
    int N = m+n-2;
    int r = m-1;
    double res = 1;

    // effecient way to find combination.
    for(int i=1; i<=r; i++){
        res = res * (N - r + i)/i;
    }

    return (int) res;
}

int main(){
    cout << UniquePaths(10, 5);
    return 0;
}