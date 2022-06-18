#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(Log N).
// Space Complexity: O(1).
int GetIndex(vector<int> arr, int n, int key){
    // Here we consider array divided into two parts, from the point it is rotated.
    int s=0, e=n-1;
    int mid = (s+e)/2;
    while(s<=e){
        // if key found.
        if(arr[mid]==key) return mid;

        // checking if mid and start are in same part.
        if(arr[mid]>=arr[s]){
            // checking if key is between start and mid, so we are reducing end to mid-1.
            if(arr[s]<=key and arr[mid]>key)
                e = mid - 1;
            // it means key is not between start and mid, so we are increasing start to mid+1. 
            else
                s = mid + 1;
        // it means start and mid are on different parts.
        } else {
            // checking if key is between mid and end, so we are increasing s to mid+1.
            if(arr[mid]<key and arr[e]>=key)
                s = mid + 1;
            // it means key is not between mid and end, so we are reducing end to mid-1.
            else 
                e = mid - 1; 
        }
        mid = (s+e)/2;
    }

    return -1;
}

int main(){
    cout << GetIndex({4, 5, 1, 2, 3}, 5, 6);
    return 0;
}