#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost::algorithm;

// Time Complexity: O(N!).
void GetSentances(string curr, string s, vector<string> &ans, unordered_set<string> dict){
    int n = s.length();

    // we are checking for each substring if it exists in dictionary.
    for(int i=1; i<=n; i++){
        // taking string from 0 to i.
        string temp = s.substr(0, i);
        // checking if string (taken in previous line) exists in dictionary or not.
        if(dict.find(temp)!=dict.end()){
            // if i==n, it means we are already at the end of string and hence we will return(after noting answer) from here.
            if(i==n){
                ans.push_back((curr + (curr.length()==0 ? "" : " ") + temp));
                return;
            }
            // if i!=n we will recursively call the same function.
            // with different curr value -- we will now add temp to curr.
            // different s value -- we will remove part from 0 to i.
            GetSentances(curr + (curr.length()==0 ? "" : " ") + temp, s.substr(i, n-i), ans, dict);
        }
    }

    return;
}

// Time Complexity: O(N!).
// Space Complexity: O(S) -- size of dictionary.
vector<string> GetAllSentances(vector<string> dict, string s){
    string temp= "";
    vector<string> ans;
    unordered_set<string> dictionary(dict.begin(), dict.end());
    GetSentances(temp, s, ans, dictionary);

    for(auto i: ans){
        cout << i << endl;
    }

    return ans;
}

int main(){
    GetAllSentances({"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa", "aaaaaaaaaaa", "aaaaaaaaaaaa", "aaaaaaaaa"}, "aaaaaaaaa");
    return 0;
}