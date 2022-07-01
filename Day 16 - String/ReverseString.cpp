#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// Different thing...
string ReverseString(string s){
    stack<char> st;
    int n = s.length();
    string ans = "";

    for(int i=0; i<n; i++){
        if(!st.empty() and s[i]==' '){
            while(!st.empty()){
                ans = ans + st.top();
                st.pop();
            }
        }

        if(s[i]!=' ' && ans!="" && st.empty())
            ans = ans + ' ';

        if(s[i]!=' ')
            st.push(s[i]);
        
    }

    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }

    return ans;
}

// Space Complexity: O(1)
// Time Complexity: O(N).
string ReverseWords(string s){
    int n = s.length();
    string ans = "";
    string tmp = "";

    for(int i=0; i<n; i++){
        if(s[i]!=' ')
            tmp = tmp + s[i];
        else if(s[i]==' '){
            if(ans!=""){
                if(tmp=="") continue;
                ans = tmp + ' ' + ans;
            } else
                ans = tmp;
            tmp = "";
        }
    }

    if(tmp!=""){
        if(ans!="")
            ans = tmp + ' ' + ans;
        else
            ans = tmp;
    }

    return ans;
}

// Space Complexity: O(N).
// Time Complexity: O(N).
string ReverseWordsStack(string s){
    stack<string>st;
    int n = s.size();
    string tmp="";
    for(int i=0; i<n; i++){
        if(s[i]!=' '){
            tmp = tmp + s[i];
        } else {
            if(tmp!=""){
                st.push(tmp);
                tmp="";
            }
        }
    }
    if(tmp!="")
        st.push(tmp);
    
    string ans = "";
    while(!st.empty()){
        if(st.size()>1)
            ans = ans + st.top() + " ";
        else
            ans = ans + st.top();
        st.pop();
    }

    return ans;
}

// Space Complexity: O(N).
// Time Complexity: O(N).
string ReverseWordsVector(string s){
    vector<string> arr;
    int start = 0,count = 0;
    for( int i=0; i<s.length(); i++ )
    {
        start = i;
        if(s[i] != ' ')
        {
            count = 0;
            while(s[i] != ' ')
            {
                count++;
                i++;
            }
            arr.push_back(s.substr(start,count));
        }
    }
    
    string s;
    
    for( int i=arr.size()-1; i>=0; i-- )
    {
        s.append(arr[i]);
        s.append(" ");   
    }
    return s;
}

int main(){
    string s = "I am Sagar  Narsingani";
    cout << ReverseWordsStack(s);
    return 0;

}