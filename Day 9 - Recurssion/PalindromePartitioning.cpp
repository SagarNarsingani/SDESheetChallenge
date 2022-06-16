#include <iostream>
#include <vector>
#include <string>
using namespace std;

// O(N) Time
bool isPalindrome(string s, int i, int j){
    while(i<=j){
        if(s[i]==s[j]){
            i++, j--;
        } else {
            return false;
        }
    }

    return true;
}

void GetPartitions(string s, int i, int n, vector<vector<string>> &partitions, vector<string> partition){
    // if we reached to the end of string we will push all the partitons we have gathered.
    if(i==n){
        partitions.push_back(partition);
        return;
    }

    for(int j=i; j<n; j++){
        // if string from i to j is palindrome we will make partition at j+1.
        if(isPalindrome(s, i, j)){
            partition.push_back(s.substr(i, j - i +1)); // adding partiton into data structure.
            GetPartitions(s, j+1, n, partitions, partition);
            partition.pop_back();   // backtracking -- removing partition from data structure.
        }
    }
}

// Time Complexity: O(2^N) -- at each index we decide wether to make partition there or not.
// Space Complexity: O(k*x) -- where k is avg length of partitions and x is number of total partitions.
vector<vector<string>> GetPalindromePartitions(string s){
    int n = s.length();

    // O(k*x) Space.
    vector<vector<string>> partitions;
    // O(k) Space.
    vector<string> partition;

    GetPartitions(s, 0, n, partitions, partition);

    for(auto i: partitions){
        for(string j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return partitions;
}

int main(){
    GetPalindromePartitions("aabb");
    return 0;
}