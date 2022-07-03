#include <iostream>
#include <string>
using namespace std;

// Time Complexity: O(N^2).
// Space Complexity: O(1).
string CountNSay(int n){
    string s = "1"; // 1st sequence.
    while(n>1){
        int i=0;
        int len = s.length();
        string tmp = "";
        // find count of contiguos same integers.
        while(i<len){
            int cnt=0;
            char curr = s[i];
            while(s[i]==curr){
                cnt++;
                i++;
            }
            tmp = tmp + to_string(cnt) + curr;
        }
        // moving to next iteration.
        s = tmp;
        n--;
    }

    return s;
}

int main(){
    int n;
    cin >> n;
    cout << CountNSay(n);
    return 0;
}