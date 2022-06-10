#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
int getMajorityElement(vector<int> arr){
    unordered_map<int, int> hash;
    int N = arr.size();
    for(int i: arr){
        hash[i]++;
        if(hash[i] >= floor(N/2)) return i;
    }

    return -1;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Moore's Voting Algorithm.
int MooreVotingAlgo(vector<int> arr){
    int ele, cnt=0, N=arr.size();
    // Minimum Count of Majority element is N/2 and hence Minority elements can be from N/2 to 0.
    // hence majority element has potential to neutralize the minority ones.
    for(int i: arr){
        if(cnt==0) ele=i;

        if(i==ele) cnt++;
        else cnt--;
    }

    cnt=0;
    // Checking for loop.
    for(int i: arr){
        if(i==ele) cnt++;
        if(cnt>floor(N/2)) return ele;
    }
    return -1;
}

int main(){
    cout << getMajorityElement({1, 2, 2, 2, 3, 4}) << endl;
    cout << MooreVotingAlgo({1, 2, 2, 2, 3, 4});
    return 0;
}

