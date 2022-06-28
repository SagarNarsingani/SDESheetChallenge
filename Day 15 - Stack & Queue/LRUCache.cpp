#include <iostream>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

/* ------------------ LRU Cache Using Doubly Linked List and HashMap ------------------ */
class Node{
    public:
        Node *next;
        Node *prev;
        pair<int, int> node;
    
        Node(int key, int val){
            node = {key, val};
            next = NULL;
            prev = NULL;
        }
};

// Time Complexity: O(Q) -- Q is number of Queries.
// Space Complexity: O(cap) -- cap is capacity of LRU.
// The node nearest to tail is considered as LRU.
// hence each time we will insert new node right after head.
class LRUCache{

    void deleteNode(int key){
        Node *tmp = hash[key];
        Node *tmpPrev = tmp->prev;
        Node *tmpNext = tmp->next;
        tmpPrev->next = tmpNext;
        tmpNext->prev = tmpPrev;
        tmp->next = NULL;
        tmp->prev = NULL;
        delete tmp;
    }

    Node* insertNode(int key, int val){
        Node *newNode = new Node(key, val);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        return newNode;
    }

    public:
        Node* head = new Node(-1, -1);
        Node* tail = new Node(-1, -1);
        unordered_map<int, Node*> hash;
        int capacity, cs;

        LRUCache(int cap){
            capacity = cap;
            head->next = tail;
            tail->prev = head;
            cs = 0;
        }

        int get(int key){
            if(hash.find(key)!=hash.end()){
                int val = hash[key]->node.second;
                deleteNode(key);
                Node* newNode = insertNode(key, val);
                hash[key] = newNode;
                return val;
            }
            return -1;
        }

        void put(int key, int val){
            if(hash.find(key)!=hash.end()){
                deleteNode(key);
            } else if(cs==capacity){
                int lru = tail->prev->node.first;
                deleteNode(lru);
                hash.erase(lru);
            } else {
                cs++;
            }

            Node *tmp = insertNode(key, val);
            hash[key] = tmp;
        }


};

/* -------------------- LRU Cache Using Queue and HashMap ------------------- */
// this takes more time because of "push_key_back" operation.
class LRUCacheQ{
    // O(N) Time.
    void push_key_back(int key){
        queue<int> temp;
        while(!q.empty()){
            int frnt = q.front();
            q.pop();
            if(frnt==key){
                continue;    
            }
            temp.push(frnt);
        }
        q = temp;
        q.push(key);
        return;
    }

    public:
        unordered_map<int, int> map;
        queue<int> q;
        int capacity;
        int cs;

        LRUCacheQ(int cap){
            capacity = cap;
            cs=0;
        }

        // O(N) Time.
        int get(int key){
            if(map.find(key)!=map.end()){
                push_key_back(key);
                return map[key];
            } else return -1;
        }

        // O(N) Time.
        void put(int key, int val){
            if(map.find(key)!=map.end()){
                map[key] = val;
                push_key_back(key);
                return;
            }

            // if capacity reached, we delete the least recently used key.
            if(q.size()==capacity){
                map.erase(q.front());
                q.pop();
            }

            q.push(key);
            map[key] = val;
            return;
        }
};

void ResolveQueries(int cap, vector<vector<int>> qs){
    LRUCache lru = LRUCache(cap);

    for(auto q: qs){
        if(q[0]==0){
            cout << lru.get(q[1]) << " ";
        } else {
            lru.put(q[1], q[2]);
        }
    }
}

int main(){
    int cap, n;
    vector<vector<int>> qs = {
        {1, 1, 1},
        {1, 2, 2},
        {0, 2},
        {1, 3, 3},
        {0, 3},
        {0, 1}
    };

    cin >> cap;

    // for(int i=0; i<n; i++){
    //     vector<int> tmp(3, 0);
    //     int qt;
    //     cin >> qt;
    //     if(qt==0){
    //         tmp[0] = 0;
    //         cin >> tmp[1];
    //     } else {
    //         tmp[0] = 1;
    //         cin >> tmp[1] >> tmp[2];
    //     }
    //     qs.push_back(tmp);
    // }

    ResolveQueries(cap, qs);

    return 0;
}