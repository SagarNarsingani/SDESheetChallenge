#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N)
int LongestSeq(vector<int> seq){
    unordered_set<int> s;
    for(int i: seq){
        s.insert(i);
    }

    int len, maxLen=INT_MIN;
    for(int i: seq){
        // if previous element is not present in the array, we start creating chain.
        if(s.find(i-1)==s.end()){
            int temp = i+1, len=1;
            while(s.find(temp)!=s.end()){
                len++;
                temp++;
            }
            // tracking max length of chain.
            maxLen = max(len, maxLen);
        } else continue;
    }

    return maxLen;
}

int main(){
    cout << LongestSeq({9,5,4,9,10,10,6});
    return 0;
}