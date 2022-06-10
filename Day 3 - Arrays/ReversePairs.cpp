#include <iostream>
#include <vector>
using namespace std;

// Conqure
// Time Complexty: O(NLogN)
int merge(vector<int> &arr, int s, int e){
    int pairs=0, mid=(s+e)/2;
    int j=mid+1;

    vector<int> temp;

    // Main difference (remaining is normal mergesort only).
    // Note: if arr[i] > 2*arr[j] then it is also true that arr[i+1] > 2*arr[j], 
    // because here arr[i+1] will be greater than arr[i]. 
    // Time : O(N)
    for(int i=s; i<=mid; i++){
        while(j<=e and (arr[i] > 2*arr[j])){
            j++;
        }
        pairs += (j-(mid+1));
    }

    int i=s;
    j=mid+1;

    while(i<=mid and j<=e){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j++]);
        } else {
            temp.push_back(arr[i++]);
        }
    }

    while(i<=mid){
            temp.push_back(arr[i++]);
    }
    while(j<=e){
            temp.push_back(arr[j++]);
    }

    int k=0;
    for(int i=s; i<=e; i++){
        arr[i] = temp[k++];
    }

    return pairs;
}

// divide
int mergesort(vector<int> &arr, int s, int e){
    if(s>=e) return 0;

    int mid = (s+e)/2;
    int pairs = 0;

    pairs = pairs + mergesort(arr, s, mid);
    pairs = pairs + mergesort(arr, mid+1, e);

    pairs = pairs + merge(arr, s, e);

    return pairs;
}

int main(){
    vector<int> arr = {1, 2, 3, 2, 3, 1};
    cout << mergesort(arr, 0, 5);
    return 0;
}