#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Node{
    public:
        char data;
        unordered_map<char, Node*> next;
        int cnt, occ;

        Node(char d){
            data = d;
            cnt = 0;    // it will be increased if string is ending at this node.
            occ=1;      // shows the occurence of this node.
        }

        ~Node(){
            for(auto p: this->next){
                delete p.second;
            }
        }
};

class Trie{
    public:
        Node* root = new Node('\0');

        void insert(string word){
            int n = word.length();

            int i=0;
            Node *tmp = root;
            while(tmp->next.find(word[i])!=tmp->next.end()){
                tmp = tmp->next[word[i]];
                // increasing occurence of nodes that are already present.
                tmp->occ++;
                i++;
                if(i==n) break;
            }

            // inserting remaining letters.
            for(int j=i; j<n; j++){
                Node *temp = new Node(word[j]);
                tmp->next[word[j]] = temp;
                tmp = temp;
            }

            // increasing cnt attribute of last node.
            tmp->cnt++;

            return;
        }

        int countWordsEqualTo(string word){
            int n = word.length();
            int i=0;
            Node *tmp = root;
            // we go till given word is there in trie.
            while(tmp->next.find(word[i])!=tmp->next.end()){
                tmp = tmp->next[word[i]];
                cout << tmp->data << " ";
                i++;
                // will return cnt, which shows how many strings ended on this node.
                if(i==n) return tmp->cnt;
            }

            return 0;
        }

        int countWordsStartingWith(string word){
            int n = word.length();
            int i=0;
            Node *tmp = root;
            // reaching till the end of given word in the trie.
            while(tmp->next.find(word[i])!=tmp->next.end()){
                tmp = tmp->next[word[i]];
                i++;
                // if reached will return number of times last letter was occurred.
                if(i==n){
                    return tmp->occ;
                }
            }
            return 0;
        }

        void erase(string word){
            int n = word.length();
            int i=0;
            Node *tmp = root;
            // reducing occurence of each letter of given word.
            while(tmp->next.find(word[i])!=tmp->next.end()){
                tmp = tmp->next[word[i]];
                tmp->occ--;
                i++;
                if(i==n) {
                    tmp->cnt--;
                    break;
                }
            }

            // making memory free.
            i=0;
            tmp = root;
            while(tmp->next.find(word[i])!=tmp->next.end()){
                tmp = tmp->next[word[i]];
                i++;
                if(tmp->occ==0) {
                    delete tmp;
                    return;
                }
            }
            return;
        }
};

int main(){
    Trie *obj = new Trie();
    obj->insert("edqw");
    obj->insert("few");
    obj->insert("few");
    // // cout << "here";



    obj->erase("few");
    cout << obj->countWordsEqualTo("few") << endl;
    cout << obj->countWordsStartingWith("fe");

    return 0;
}