#include <iostream>
#include <vector>
using namespace std;

// Finding out if current mid is appropriat barier or not.
// which means, can we divide books in n students with maximum number of pages as mid.
// this will take O(M) time.
bool canAllocateInMid(vector<int> books, long long mid, int n){
    long long i=1, allocated=0;
    for(int book: books){
        // if book itself has pages greater than mid.
        if(book>mid) return false;
        // if allocated pages to increses than mid.
        if(allocated+book > mid){
            i++;
            allocated=book;
            if(i>n) return false;
        } else {        // till allocated pages to increses than mid.
            allocated += book;
        }
    }

    // if we managed to alocate M books to N students, with  mid as bariear.
    return true;
}

long long GetMinimalAllocation(int n, int m, vector<int> books){
    // if number of students are greater than number of books.
    if(n>m) return -1;

    // defining the range for binary search.
    // best case: all books have same number of pages and number of student are equal to number of books.
    // worst case: number of student is 1.
    long long s=0, e=0;
    for(int book: books){
        s = min(s, (long long)book);
        e = e + book;         
    }

    // Binary Search through the solution space(best to worst case).
    long long res = INT_MAX;
    while(s<=e){
        long long mid = (e+s)>>1;
        // cout << "s: " << s << " mid: " << mid << " e: " << e << endl;
        // if we can allocate books with barier mid we will reduce the range as we want to find minimal number.
        if(canAllocateInMid(books, mid, n)){
            res = mid;
            e = mid-1;
        } else {    // else we will increase the range.
            s = mid+1;
        }
    }

    return res;
}

int main(){
    cout << GetMinimalAllocation(4, 6, {2, 7, 9, 10, 5, 4});
    return 0;
}