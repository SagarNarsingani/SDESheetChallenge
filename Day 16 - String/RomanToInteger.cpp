#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// dictionary to store integer value correspond to roman number.
unordered_map<char, int> map;

// Time Complexity: O(N).
// Space Complexity: O(1).
int RomanToInteger(string s){
    map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    // take first element as answer.
    int pre=map[s[0]], curr;
    int ans = pre;

    for(int i=1; i<s.length(); i++){
        curr = map[s[i]];
        // if previous less than current we need to add (current-previous) in answer.
        // as previous was already in answer, we will add (curr-2*pre) instead.
        if(curr > pre)
            ans = ans + (curr-2*pre);
        else    // else we need to add both pre and curr, pre is already added hence only need to add curr.
            ans = ans + curr;
        pre = curr;
    }

    return ans;
}