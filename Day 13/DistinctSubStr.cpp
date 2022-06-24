#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Node{
    public:
        char data;
        int len;
        unordered_map<char, Node*> next;

        Node(char d):data(d), len(0){};
};

class Trie{
    Node *root = new Node('\0');

    void dfs(Node *root, int &cnt){
        if(root->len!=0){
            // if branch is a->b->c then len=3;
            // as the substrings will be also 3: a, ab, abc. 
            // we are adding len to the cnt when we reach at the end.
            cnt = cnt + root->len;
            return;
        }

        for(auto pair: root->next){
            dfs(pair.second, cnt);
        }

        return;
    }
    public:
        void insert(string word){
            int n = word.length();
            int len = n;
            Node *temp = root;

            int i=0;
            while(i < n){
                if(temp->next.find(word[i])!=temp->next.end()){
                    temp = temp->next[word[i]];
                    i++;
                    len--;
                } else break;
            }

            for(int j=i; j<n; j++){
                Node *tmp = new Node(word[j]);
                temp->next[word[j]] = tmp;
                temp = tmp;
            }

            // len basically counts distinct number of letters in each branch.
            // distinct letters are those who are not part of any other branch.
            temp->len = len;
        }

        // Time Complexity: O(N^2).
        // Space Complexity: O(N^2).
        int GetDistinctSubStr(){
            int cnt = 0;

            dfs(root, cnt);

            return cnt;
        }
};

int main(){
    string s;
    cin >> s;
    int n = s.length();

    Trie *trie = new Trie();
    // each time will remove one letter from start and insert it in Trie.
    for(int i=0; i<n; i++){
        trie->insert(s.substr(i, n));
    }

    cout << trie->GetDistinctSubStr() << endl;

    return 0;
}