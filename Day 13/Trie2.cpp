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
            cnt = 0;
            occ=1;
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
                tmp->occ++;
                i++;
                if(i==n) break;
            }

            for(int j=i; j<n; j++){
                Node *temp = new Node(word[j]);
                tmp->next[word[j]] = temp;
                tmp = temp;
            }

            tmp->cnt++;

            return;
        }

        int countWordsEqualTo(string word){
            int n = word.length();
            int i=0;
            Node *tmp = root;
            while(tmp->next.find(word[i])!=tmp->next.end()){
                tmp = tmp->next[word[i]];
                cout << tmp->data << " ";
                i++;
                if(i==n) return tmp->cnt;
            }

            return 0;
        }

        int countWordsStartingWith(string word){
            int n = word.length();
            int i=0;
            int cnt=0;
            Node *tmp = root;
            while(tmp->next.find(word[i])!=tmp->next.end()){
                tmp = tmp->next[word[i]];
                i++;
                if(i==n){
                    return tmp->occ;
                }
            }


            return cnt;
        }

        void erase(string word){
            int n = word.length();
            int i=0;
            Node *tmp = root;
            while(tmp->next.find(word[i])!=tmp->next.end()){
                tmp = tmp->next[word[i]];
                tmp->occ--;
                i++;
                if(i==n) {
                    tmp->cnt--;
                    break;
                }
            }


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