#include <iostream>
#include <string>
using namespace std;

// Time Complexity: O(N^2).
// Space Complexity: O(1).
string getLargestPalindrome(string s){
    int n = s.length();
    int high, low;
    int maxLength = 1, start=0;
    for(int i=0; i<n; i++){
        // from i=0 to i=n-1, we are keeping each character in the middle one by one.
        high = i+1;
        low = i-1;

        // skipping all the character on right side that are same as middle char.
        while(high<n and s[high]==s[i]){
            high++;
        }

        // skipping all the character on left side that are same as middle char.
        while(low>=0 and s[low]==s[i]){
            low--;
        }
        
        // will move in both directions till same characters occur.
        while(high<n and low>=0 and s[low]==s[high]){
            high++;
            low--;
        }

        // length of palindrome string we got in this iteration.
        int newLen = high-low-1;
        // if it is greater than max, we will update the max.
        if(newLen>maxLength){
            maxLength = newLen;
            start = low+1;  // to find palindrome string.
        }
    }

    return s.substr(start, maxLength);
}

int main(){
    string s;
    cin >> s;
    cout << getLargestPalindrome(s);
}