#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(1).
int Atoi(string s){
    int n = s.length();

    // mapping each char form of number to int form.
    unordered_map<char, int> nums;
    nums = {
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9}
    };

    // calculating the number.
    int ans=0, base=1;
    for(int i=n-1; i>=0; i--){
        if(nums.find(s[i])!=nums.end()){
            ans = ans + (nums[s[i]]*base);
            base = base * 10;
        }
    }


    // if first char in string is, - we need to make answer negative.
    if(s[0]=='-')
        ans = 0-ans;
    
    return ans;
}

int main(){
    cout << Atoi("12tr45") << endl;
    return 0;
}