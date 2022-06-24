#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Node{
    public:
        char data;
        bool isTerminal;
        unordered_map<char, Node*> next;

        Node(char d, bool ter=false):data(d), isTerminal(ter){};
};

class Trie{
    Node *root = new Node('\0');

    public: 
        void insert(string word){
            Node *tmp = root;
            int i=0;
            int n=word.length();

            while(i<n){
                if(tmp->next.find(word[i])!=tmp->next.end()){
                    tmp = tmp->next[word[i]];
                    i++;
                } else break;
            }

            for(int j=i; j<n; j++){
                Node *temp = new Node(word[j]);
                tmp->next[word[j]] = temp;
                tmp = temp;
            }

            tmp->isTerminal = true;
        }

        // Time Complexity: O(N*k) -- N is number of string and k is avg length of all strings.
        // Space Complexity: O(N*k) -- Storing all strings in Trie.
        string CompleteString(vector<string>a){
            int n = a.size();
            // Initially set ans as "None", so that if there doesn't exist any answer, we will return "None".
            string ans = "None";
            // iterating through all words.
            for(string s: a){
                // standing at root.
                Node *tmp = root;
                int i=0, k=s.length();
                // iterating through each letter of current word.
                for(;i<k; i++){
                    // will move ahead with string only if there exist a node for next letter.
                    // otherwise will move to next word.
                    if(tmp->next.find(s[i])!=tmp->next.end()){
                        tmp = tmp->next[s[i]];
                        // each letter should be a terminal.
                        // then only we can say all prefix of current words are present in array.
                        if(!tmp->isTerminal) break;
                    } else break;
                }
                // if we reached to the end of word.
                // it means all prefix exists of current word in array.
                if(i==k){
                    // if ans is "None" we don't need to check length here.
                    // else we compare length and only change ans if length of curr word 
                    // is strictly greater than ans.
                    if(ans=="None" || (ans.length() < s.length())){
                        ans = s;
                    }
                }
            }
            return ans;
        }

};

int main(){
    vector<string> s = {"ab", "bc"};

    Trie *trie = new Trie();

    sort(s.begin(), s.end());

    for(string str: s){
        trie->insert(str);
    }

    cout << trie->CompleteString(s) << endl;
    return 0;
}