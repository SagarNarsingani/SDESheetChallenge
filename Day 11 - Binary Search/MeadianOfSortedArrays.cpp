#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(min(LogN, LogM)).
// Space Complexity: O(1).
double GetMeadian(vector<int> a, vector<int> b){
    int n=a.size(), m=b.size();
    if(m<n)
        return GetMeadian(b, a);
    
    int low=0, high=n;
    // as we want one based index, we are adding one here.
    int meadPos = ((m+n+1)/2);
    while(low<=high){
        // basically we want to find the partitions of both arrays that constructs the left half of merged array.
        // initially at the mid of minimum array we will make cut1.
        int cut1 = (low + high) / 2;
        // taking remaining element from array 2.
        int cut2 = meadPos - cut1;

        cout << cut1 << " : " << cut2 << endl;

        // l1 - end of partition of 1st array
        // l2 - end of partition of 2nd array
        // r1 - start of remaining part of 1st array
        // r2 - start of remaining part of 2nd array
        int l1 = (cut1==0) ? INT_MIN : a[cut1-1];   // here we want one based indexing hence 1 was added in meadPos.
        int l2 = (cut2==0) ? INT_MIN : b[cut2-1];
        int r1 = (cut1==n) ? INT_MAX : a[cut1];
        int r2 = (cut2==m) ? INT_MAX : b[cut2];

        if((l1<=r2) and (l2<=r1)){  // if this is true than only partitions are okay.
            if((m+n)&1) return max(l1, l2);
            else return (max(l1, l2) + min(r1, r2))/(double)2;
        } else if(l1>r2){ // it basically means we need to take more elements from array 2 and less from array 1.
            high = cut1-1;
        } else {    // it basically means we need to take more elements from array 1 and less from array 2.
            low = cut1+1;
        }
    }

    return 0.0;
}

int main(){
    cout << GetMeadian({1, 4, 7, 8}, {10, 11, 14, 17, 19});
    return 0;
}


