#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int> &arr){
    vector<int> cnt(3, 0);
    for(int i: arr){
        cnt[i]++;
    }

    for(int i=0; i<arr.size();){
        for(int j=0; j<cnt.size(); j++){
            while(cnt[j]--){
                arr[i] = j;
                i++;
            }
        }
    }

    return;
}

int main(){
    vector<int> arr = {0, 1, 2, 2, 1, 0};
    Sort(arr);
    for(int i: arr){
        cout << i << " ";
    }
}