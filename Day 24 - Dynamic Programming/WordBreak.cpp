#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include <unordered_set>
using namespace std;

class Node{
    public:
        char data;
        bool isTerminal;
        unordered_map<char, Node*> next;
    
        Node(char ch){
            data = ch;
            isTerminal = false;
        }
};

class Trie{
    public:
        Node *root = new Node('\0');        
    
        void insert(string s){
            Node *tmp = root;

            int i=0, n=s.length();
            while(i<n && tmp->next.find(s[i])!=tmp->next.end()){
                tmp = tmp->next[s[i]];
                i++;
            }

            while(i<n){
                tmp->next[s[i]] = new Node(s[i]);
                tmp = tmp->next[s[i]];
                i++; 
            }

            tmp->isTerminal = true;
        }

        bool checkWord(string word){
            int i=0, n=word.length();

            Node *tmp = root;

            while(i<n && tmp->next.find(word[i])!=tmp->next.end()){
                tmp = tmp->next[word[i]];
                i++;
            }

            if(i==n && tmp->isTerminal)
                return true;
            else if(!tmp->isTerminal)
                return false;
            return checkWord(word.substr(i, n));
        }

};


// Time Complexity: O(N*N*N) 
// Space Complexity: O(N) + O(N) + O(W) -- Auxilary + DP array + Set.
// -- one for loop.
// -- each time comparing left string to right.
// -- N time calling the function.
unordered_set<string> str;
bool isThereWord(string word, int pos, vector<int> &dp){
    int n = word.length();

    // base case: if string is empty.
    if(pos == n)
        return dp[pos] = true;
    
    if(dp[pos]!=-1)
        return dp[pos];

    for(int i=pos; i<n; i++){
        // we make partition at each point and check if string on left exists in dictionary or not.
        // if yes, we move on forward (i+1) position and if that returns true, we return true from here.
        if(str.find(word.substr(pos, i-pos+1))!=str.end()){
            // note that we are just changing pos, word is still the same in next function call.
            if(isThereWord(word, i+1, dp)){
                return dp[pos] = true;
            }
        }
    }
    // if we can't make any partition or remaining string on right side return false.
    return dp[pos] = false;
}


bool isWordPresent(vector<string> &strs, string w){
    int n = w.size();

    /* ------------------------------- Using Trie ------------------------------- */
    // Time Complexity: O(N*W) + O(w).
    // -- W is avg length of word.
    // -- w is length of word we need to find.
    // Trie t = Trie();
    // for(string s: strs){
    //     t.insert(s);
    // }
    // return t.checkWord(w);

    /* --------------------------- Dynamic Programming -------------------------- */
    for(string s: strs){
        str.insert(s);
    }

    /* ------------------------------- Memoization ------------------------------ */
    
    // vector<int> dp(n+1, -1);
    // return isThereWord(w, 0, dp);

    /* ------------------------------- Tabulation ------------------------------- */
    
    // Time Complexity: O(N*N*N).
    // Space Complexity: O(N*N).
    // dp[i][j] signifies, whether string starting from i and ending at j, can be made be made from dictionary.
    // with 0 based indexing.
    vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
    // iterating for length of window.
    for(int i=1; i<=n; i++){
        // sliding window.
        int s=1, e=i;
        while(e<=n){
            // take substring.
            string tmp = w.substr(s-1, i);
            // check if substr is part of dictionary or not.
            if(str.find(tmp)!=str.end())
                dp[s][e]=true;  // if yes store true at indices.
            else {
                // else we need to check by making partitions at all points in current window.
                bool flag = false;
                for(int k=s; k<e; k++){
                    if(dp[s][k] and dp[k+1][e]){
                        flag = true;
                        break;
                    }
                }
                // store final value in current indices.
                dp[s][e] = flag;
            }
            // moving window forward.
            s++;
            e++;
        }
    }

    return dp[1][n];
}

int main(){
    vector<string> strs = {"ab", "cd"};
    cout << isWordPresent(strs, "abcd");
    return 0;
}