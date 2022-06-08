#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int> arr, int i, vector<vector<int>> &perm){

    if(arr.size() == i){
		// cout << arr << endl;
        perm.push_back(arr);
		return;
	}

	// swapping current element with each one that appears after that.
	for(int j = i; j < arr.size(); j++){
		swap(arr[i], arr[j]);	// in the 1st iteration element will swapped by itself.
		nextPermutation(arr, i+1, perm);
		swap(arr[i], arr[j]);	// restoring the string as it was before -- backtracking.
	}

    return;
}

int main(){
    vector<int> arr = {3, 2, 1};
    vector<vector<int>> perm = {};
    nextPermutation(arr, 0, perm);
    for(int i: perm[1]){
        cout << i << " ";
    }
    return 0;
}