#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> GetAllOcc(string str, string pat){
    int n=str.length();
    int m = pat.length();

    if(n<m) return {};

    vector<int> ans;

    for(int i=0; i<=n-m; i++){
        int k = i;
        for(int j=0; j<m; j++){
            if(str[k]!=pat[j])
                break;
            k++;
            if(j==(m-1)) ans.push_back(i);
        }
    }

    return ans;
}

vector<int> RabinKarp(string str, string pat){
    // to store answer.
    vector<int> ans;
    
    // prime number to take mod.
    const int q = 101;
    // total number of char possible -- taken as base in finding hash.
    const int d = 256;

    int N = str.length();
    int M = pat.length();

    // if string is itself less than pattern.
    if(N<M) return {};

    int p=0;    // will store hash of pattern.
    int t=0;    // will store hash of M chars of string (at a time).

    int h=1;    // highest power used in hash.
    for(int i=0; i<M-1; i++){
        h = (h*d)%q;
    }

    // finding hash of pattern and initial hash of string.
    // hash(str[i]...str[i+M]) = str[i]*(256^(M-1)) + str[i+1]*(256^(M-2)) + ... + str[i+M]*(256^0).
    int td = 1;
    for(int i=M-1; i>=0; i--){
        p = (p + pat[i] * td)%q;    // taking mod to ensure value doesn't go out of bound.
        t = (t + pat[i] * td)%q;
        td = (td*d)%q;
    }

    for(int i=0; i<=N-M; i++){
        // if hash of current string(of char M) matches with hash of pattern...
        if(t==p){
            // will confirm by matching string and pattern.
            int k = i;
            for(int j=0; j<M; j++){
                if(str[k]!=pat[j])
                    break;
                k++;
                // if match is successfull, will push i(start) in answer. 
                if(j==(M-1)) ans.push_back(i);
            }
        }
        
        // moving the window, changing the hash.
        t = (d*(t-str[i]*h) + str[i+M])%q;

        // str[i]*h can be bigger than q, where as t can't be hence (t-str[i]*h) will become negative.
        // however hash(pat) is always constant and positive.
        // this can cause problem, hence we need to make t positive.
        if(t<0)
            t = t + q;
    }

    return ans;

}

int main(){
    vector<int> ans = RabinKarp("MANGOMAN", "MAN");

    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}