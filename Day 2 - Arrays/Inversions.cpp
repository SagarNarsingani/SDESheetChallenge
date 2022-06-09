#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<long long> &arr, int s, int e){
    int mid = (s+e)/2;
    long long inv=0;
    vector<long long> temp;
    int i = s, j = mid+1;

    while((i <= mid) and (j <= e) ){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        } else {
            // elements from (i to mid) are smaller than arr[j]. (+1 because of 0 based index)  
            inv = inv + (mid+1-i);
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }

    while(j <= e){
        temp.push_back(arr[j++]);
    }

    int k=0;
    for(int i=s; i<=e; i++){
        arr[i] = temp[k++];
    }

    return inv;
}

// we are using basic merge sort.
long long mergesort(vector<long long> &arr, int s, int e){
    if(s>=e) return 0;

    long long inv = 0;

    int mid = (s+e)/2;
    inv = inv + mergesort(arr, s, mid);
    inv = inv + mergesort(arr, mid+1, e);

    inv = inv + merge(arr, s, e);

    return inv;
}

int main(){
    vector<long long> arr = {1, 2, 3, 4, 5, 6};
    cout << mergesort(arr, 0, 4);
    return 0;
}