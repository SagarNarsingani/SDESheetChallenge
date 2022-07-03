#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N). 
bool areAnagrams(string s1, string s2){
    
    int n = s1.length();
    int m = s2.length();

    if(n!=m) return false;

    unordered_map<char, int> cnt;

    // store count of first string in map.
    for(char i: s1){
        cnt[i]++;
    }

    // delete occurences of existing chars from map.
    // if char doesn't exist, we will return false.
    for(char i: s2){
        if(cnt.find(i)==cnt.end() || cnt[i]==0)
            return false;
        cnt[i]--;
    }

    return true;
}

int main(){
    cout << areAnagrams("Sagar", "ragSa");
    return 0;
}