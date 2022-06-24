#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
    public:
        char data;
        bool isTerminal;
        unordered_map<char, Node*> next;

        Node(char d, bool ter=false){
            data = d;
            isTerminal = ter;
        }
};

class Trie{
    public:
        Node *root = new Node('\0');

        void insert(string bitstr){
            Node *tmp = root;
            int i=0;
            int n=bitstr.length();

            while(i<n){
                if(tmp->next.find(bitstr[i])!=tmp->next.end()){
                    tmp = tmp->next[bitstr[i]];
                    i++;
                } else break;
            }

            for(int j=i; j<n; j++){
                Node *temp = new Node(bitstr[j]);
                tmp->next[bitstr[j]] = temp;
                tmp = temp;
            }

            tmp->isTerminal = true;
        }

        int GetMaxXor(string x){
            int ans = 0, pow=31;
            int i=0;

            Node *tmp = root;
            while(i<=31){
                if(x[i]=='0'){
                    if(tmp->next.find('1')!=tmp->next.end()){
                        tmp = tmp->next['1'];
                        ans = (ans | (1 << pow));
                    } else {
                        tmp = tmp->next['0'];
                    }
                } else {
                    if(tmp->next.find('0')!=tmp->next.end()){
                        ans = (ans | (1 << pow));
                        tmp = tmp->next['0'];
                    } else {
                        tmp = tmp->next['1'];

                    }
                }

                i++;
                pow--;
            }

            return ans;
        }
};

// converting decimal into binary string.
// Time Complexity: O(32) ~ O(1).
string DecimalToBinary(int dec){
    string bin = "";
    for(int i=0; i<32; i++)
        bin = bin + "0";
    
    int i=31;
    while(dec){
        if(dec&1) 
            bin[i] = '1';

        dec = (dec >> 1);

        i--;
    }
    return bin;
}

// Time Complexity: O(32*N).
// Space Complexity: O(32*N).
int main(){
    vector<int> arr = {1, 2, 3, 4};

    Trie *trie = new Trie();

    // Time Complexity: O(32*N).
    // Space Complexity: O(32*N).
    for(int i: arr){
        trie->insert(DecimalToBinary(i));
    }

    int maxXOR = INT_MIN;
    // Time Complexity: O(32*N).
    for(int i: arr){
        int x = trie->GetMaxXor(DecimalToBinary(i));
        maxXOR = max(maxXOR, x);
    }

    cout << "ans: " << maxXOR;

    return 0;
}