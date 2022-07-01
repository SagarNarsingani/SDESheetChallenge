#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
    public:
        char data;
        bool terminal;
        Node* next;

        Node(char d, bool ter=false){
            data = d;
            terminal = ter;
            next = NULL;
        }
};

class Trie{
    public:
        Node* root;
        int size;
        Trie(){
            root = new Node('\0', true);
            size = 0;
        }

        void insert(string s){
            Node *tmp = root;
            int n = s.length();
            // will only run when trie is empty.
            if(root->terminal && size==0){
                for(int i=0; i<n; i++){
                    tmp->next = new Node(s[i]);
                    tmp = tmp->next;
                }
                root->terminal = false;
            } else {    // otherwise
                int i=0;
                // this will run till we can found the characters of current string.
                while(i<n && tmp->next!=NULL && tmp->next->data==s[i]){
                    tmp = tmp->next;
                    i++;
                }
            }
            // will make last common character as terminal.
            tmp->terminal = true;
            size++;
        }

        // O(L) -- where L is maximum length possible of string.
        string GetLargestPrefix(){
            if(root->terminal) return "";
            Node* tmp = root->next;
            string res = "";
            // will go till nearest terminal -- longest prefix.
            while(!tmp->terminal){
                res = res + tmp->data;
                tmp = tmp->next;
            }

            res = res + tmp->data;

            return res;
        }
};

// Time Complexity: O(N*L) -- in worst case we can have N strings of max length L and all of strings are same.
// Space Complexity: O(L). 
string getLongestPrefix(vector<string> arr, int n){
    Trie t = Trie();

    // inserting all strings.
    for(string i: arr){
        t.insert(i);
    }

    // getting the Longest Prefix.
    return t.GetLargestPrefix();
}

int main(){
    vector<string> arr = {"kimrekacsf", "kimrettrwa", "kimreeybfg", "timrewwmnr", "kimretjxjl", "kimrejecjw"};


    cout << getLongestPrefix(arr, 6) << endl;
    return 0;
}