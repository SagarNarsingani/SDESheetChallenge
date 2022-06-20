#include <iostream>
#include <vector>
using namespace std;

bool canAllocateInMid(vector<int> books, long long mid, int n){
    long long i=1, allocated=0;
    for(int book: books){
        if(book>mid) return false;
        if(allocated+book > mid){
            i++;
            allocated=book;
            if(i>n) return false;
        } else {
            allocated += book;
        }
    }

    return true;
}

long long GetMinimalAllocation(int n, int m, vector<int> books){

    if(n>m) return -1;
    long long s=0, e=0;

    for(int book: books){
        s = min(s, (long long)book);
        e = e + book;         
    }

    long long res = INT_MAX;
    while(s<=e){
        long long mid = (e+s)>>1;
        // cout << "s: " << s << " mid: " << mid << " e: " << e << endl;
        if(canAllocateInMid(books, mid, n)){
            res = mid;
            e = mid-1;
        } else {
            s = mid+1;
        }
    }

    return res;
}

int main(){
    cout << GetMinimalAllocation(4, 6, {2, 7, 9, 10, 5, 4});
    return 0;
}