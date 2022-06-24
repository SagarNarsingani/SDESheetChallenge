#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// represents each node of Trie.
class Node{
    public:
        char data;
        unordered_map<char, Node*> next;
        bool isTerminal;

        Node(char d, bool ter){
            data = d;
            isTerminal = ter;
        }   
};

// Main Trie Class.
class Trie{
    public:
        // Creating root node. 
        Node *root = new Node('\0', true);

        // insert given word in current Trie.
        void insert(string word){
            // if there were no words before in this Trie.
            if(root->isTerminal) 
                root->isTerminal = false;
            int n = word.length();
            Node *temp = root;
            int i=0;
            // Will move to the point from where insertion should be done.
            // e.g., if app exists and word is apple, we will move to second p from this while loop.
            while(temp->next.find(word[i])!=temp->next.end()){
                temp = temp->next[word[i]];
                i++;
                if(i==n) break;
            }

            // will insert remaining 'le' of word apple using this for loop.
            for(int j=i; j<n; j++){
                Node *next = new Node(word[j], false);
                temp->next[word[j]] = next;
                temp = next;
            }

            // making last node as terminal.
            temp->isTerminal = true;
            return;
        }

        // To search if word exists in Trie.
        bool search(string word){
            if(root->isTerminal) 
                return false;
            int n = word.length();
            Node *temp = root;

            // searching using this while loop.
            int i=0;
            while(temp->next.find(word[i])!=temp->next.end()){
                temp = temp->next[word[i]];
                i++;
                if(i==n){
                    if(temp->isTerminal) return true;
                    else return false;
                }
            }

            return false;
        }

        bool startsWith(string prefix){
            int n = prefix.length();
            Node *temp = root;

            int i=0;
            while(temp->next.find(prefix[i])!=temp->next.end()){
                temp = temp->next[prefix[i]];
                i++;
                if(i==n){
                    return true;
                }
            }

            return false;
        }
};

int main(){
    Trie *obj = new Trie();
    obj->insert("Sagar");
    cout << obj->search("Dhruvil") << endl;
    cout << obj->startsWith("Sag") << endl;
    return 0;
}