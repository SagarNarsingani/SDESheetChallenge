#include <iostream>
#include <vector>
using namespace std;

int GetKthNumber(vector<int> a, vector<int> b, int k){
    int n=a.size(), m=b.size();
    // if(k==(m+n)) return max(a[n-1], b[m-1]);
    if(m<n)
        return GetKthNumber(b, a, k);

    // if we take low=0 and high=n, and cut2 becomes more than m then we can get into problem.
    // by doing this we are ensuring (by setting low = k-m) that if k>m than we at-least take k-m elements from first array.
    // if low = k-m then high = n.
    // if low = 0 and k<n then high=k -- k/2 elements from both arrays.
    int low = max(0,k-m), high = min(k,n), ans=min(a[0], b[0]);
    while(low <= high){
        // finding mid of curr range.
        int cut1 = (high + low) / 2;
        // getting remaining elements from 2nd array.
        int cut2 = k - cut1;

        // if(cut1>n){
        //     high = cut1-1;
        //     continue;
        // } else if(cut2 > m){
        //     low = cut1+1;
        //     continue;
        // }

        // cout << cut1 << " : " << cut2 << endl;

        // l1 - end of partition of 1st array
        // l2 - end of partition of 2nd array
        // r1 - start of remaining part of 1st array
        // r2 - start of remaining part of 2nd array
        int l1 = (cut1==0) ? INT_MIN : a[cut1-1];   // if none of element is taken from array1 then l1=min!
        int l2 = (cut2==0) ? INT_MIN : b[cut2-1];   // if none of element is taken from array2 then l2=min!
        int r1 = (cut1==n) ? INT_MAX : a[cut1];     // if all elements from array1 are taken then r1=max!
        int r2 = (cut2==m) ? INT_MAX : b[cut2];     // if all elements from array2 are taken then r2=max!

        if((l1<=r2) and (l2<=r1)){      // checking if the partition is correct.
            ans = max(l1, l2);  // noting the answer and breaking the loop.
            break;
        } else if(l1 > r2){
            high = cut1-1;  // manging range (low to high), as per values of l1, l2, r1 and r2.
        } else {
            low = cut1 + 1;
        }
    }

    return ans;
}

int main(){
    cout << GetKthNumber({2, 3, 9, 9, 10, 11}, {1, 1, 2, 4, 5, 6, 7, 8, 8, 9, 9, 13}, 18);
    return 0;
}




