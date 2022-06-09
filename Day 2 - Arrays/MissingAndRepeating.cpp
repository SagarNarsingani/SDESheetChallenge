#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> MissingAndRepeating(vector<int>arr){
    int n = arr.size(), repeat, missing;
    vector<int> cnt(n, 0);
    for(int i=0; i<n; i++){
        cnt[arr[i]-1]++;
        if(cnt[arr[i]-1]==2){
            repeat = arr[i];
        }
    }

    for(int i=0; i<n; i++){
        if(cnt[i]==0){
            missing = i+1;
            break;
        }
    }

    return {missing, repeat};

}

int main(){
    pair<int, int> mr = MissingAndRepeating({1, 2, 2, 3, 5, 6});
    cout << mr.first << " " << mr.second;
    return 0;
}
