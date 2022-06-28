#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node{
    public:
        Node *next, *prev;
        int freq;
        pair<int, int> node;

        Node(int key, int val, int f=1){
            node = {key, val};
            freq = f;
            next = NULL;
            prev = NULL;
        }
};

class LRUCache{

    public:
        Node *head, *tail;
        int size=0;

        LRUCache(){
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }

        Node *insertNode(int key, int val, int freq){
            Node* newNode = new Node(key, val, freq);
            newNode->prev = head;
            newNode->next = head->next;
            head->next->prev = newNode;
            head->next = newNode;
            size++;
            return newNode;
        }

        void deleteNode(Node* node){
            node->next->prev = node->prev;
            node->prev->next = node->next;
            node->prev = NULL;
            size--;
            node->next = NULL;
        }

};

class LFUCache{
    public:
        // map to track each node's address (based on key). 
        unordered_map<int, Node*> hash;

        // map to maintain LRU (based on frequencies).
        unordered_map<int, LRUCache> freqs;
        int capacity;
        int cs;
        int freq;

        LFUCache(int cap){
            capacity=cap;
            cs=0;   // current size.
            freq=0; // least frequency
        }

        int get(int key){
            if(hash.find(key)!=hash.end()){
                int currFreq = hash[key]->freq;
                int val = hash[key]->node.second;

                // as we are accessing a node, it's frequency will change hence removing that node from current LRU
                // and inserting it in LRU with curr+1 frequency.
                freqs[currFreq].deleteNode(hash[key]);
                Node *newNode = freqs[currFreq+1].insertNode(key, val, currFreq+1);

                // as we created new Node(with change in freq), it's address will also change in hashmap.
                hash[key] = newNode;

                // checking if LRU of current least freq is empty or not, if it is we will update least freq.
                while(freqs[freq].size==0){
                    freq = freq+1;   
                }

                return val;
            }
            return -1;
        }

        void put(int key, int val){
            // if node already exists.
            if(hash.find(key)!=hash.end()){
                // deleting node from LRU of currFreq and adding it into LRU with currFreq+1.
                int currFreq = hash[key]->freq;
                freqs[currFreq].deleteNode(hash[key]);
                Node *newNode = freqs[currFreq+1].insertNode(key, val, currFreq+1);
                // as we created new node (with different val and freq), we are changin the address of node in hashmap.
                hash[key] = newNode;
            } else if(cs==capacity) {   // if we already have used capacity of LFU.
                // will erase address of least recently used + least frequent used node.
                // also we will delete that node from LRU with freq as frequency.
                hash.erase(freqs[freq].tail->prev->node.first);
                freqs[freq].deleteNode(freqs[freq].tail->prev);

                // creating new node with (key and val) and 1 as frequency.
                Node *newNode = freqs[1].insertNode(key, val, 1);
                freq = 1;   // reset least freq.
                // storing address of new node.
                hash[key] = newNode;
            } else {
                // increase current size.
                cs++;
                // creating new node with (key and val) and 1 as frequency.
                Node *newNode = freqs[1].insertNode(key, val, 1);
                freq = 1;   // reset least freq.
                // storing address of new node.
                hash[key] = newNode;
            }

            // updating least freq.
            while(freqs[freq].size==0){
                freq = freq+1;   
            }

            return;
        }
};

int main(){
    LFUCache lfu = LFUCache(2);

    lfu.put(1, 7);
    lfu.put(2, 1);
    lfu.put(2, 6);
    
    cout << lfu.get(1) << " ";

    lfu.put(3, 10);
    lfu.put(4, 12);

    // lfu.put(2, 1);
    cout << lfu.get(3) << " ";
    cout << lfu.get(4) << " ";

    return 0;
}