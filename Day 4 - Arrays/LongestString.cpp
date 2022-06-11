#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Time Complexity: O(2*N).
// Space Complexity: O(N).
int LongestString(string str){
    // map will keep track of last index at which each char occured.
    unordered_map<char, int> map;
    int len=0, maxLen=1, s=0;   // s is used in erasing.
    int n = str.length();
    for(int i=0; i<n; i++){
        // if element has not occured yet.
        if(map.find(str[i])==map.end()){
            // cout << str[i] << " ";
            len++;
        } else {
            // cout << str[i] << " : " << len << endl;
            maxLen = max(len, maxLen);  // calculating max length.
            len = i - map[str[i]];      // taking next char inside and leaving repeating one outside.
            while(s<=map[str[i]]){
                map.erase(str[s]);      // all elements that were present before repeating char will be removed from hashmap.
                s++;
            }
        }
        // adding curr char in hash.
        map[str[i]] = i;
    }
    
    // one last comperision.
    return max(maxLen, len);
}

int main(){
    cout << LongestString("abcabcbb");
    return 0;
}