#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(1).
// Byer Moore's Voting Algorithm (extension).
vector<int> ByerMooreVotingAlgo(vector<int> arr){
    int num1=-1, num2=-1, cnt1=0, cnt2=0, n=arr.size();
    vector<int> ans;
    // there will be at max 2 elements that can occur strictly more than N/3 time.
    // Hence 2/3part of array is filled with majority and this fact can be used to nuetrilize the minority elements.
    // Initially we assume that there exists 2 major elements.
    for(int i: arr){
        if(i==num1){
            cnt1++;
        } else if(i==num2){
            cnt2++;
        } else if(cnt1==0){
            cnt1++;
            num1=i;
        } else if(cnt2==0){
            cnt2++;
            num2=i;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    // checking for loop: checks if num1 and num2(which were assumed to be majors) are majority elements or not.
    cnt1=cnt2=0;
    for(int i: arr){
        if(i==num1) cnt1++;
        else if(i==num2) cnt2++;    
    }

    if(cnt1>floor(n/3)) ans.push_back(num1);
    if(cnt2>floor(n/3)) ans.push_back(num2);

    return ans;
}

int main(){
    vector<int> ans = ByerMooreVotingAlgo({3, 2, 2, 1, 5, 2, 3});
    for(int i: ans){
        cout << i << " ";
    }

    return 0;
}