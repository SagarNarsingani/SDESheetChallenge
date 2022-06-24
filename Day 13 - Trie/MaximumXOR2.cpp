#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node{
    public:
        int data;
        bool isTerminal;
        Node* next[2];  // each node only have two neighbours 0 and 1.

        Node(int d, bool ter=false){
            data = d;
            isTerminal = ter;
            next[0] = NULL, next[1] = NULL;
        }
};

class Trie{
    public:
     Node *root;

     Trie(){
        root = new Node(-1, true);
     }

     void insert(int num){
        if(root->isTerminal)
            root->isTerminal = false;
        Node *tmp = root;
        for(int i=31; i>=0; i--){
            int curr = ((num>>i) & 1);
            if(tmp->next[curr]){
                tmp = tmp->next[curr];
            } else {
                Node* temp = new Node(curr);
                tmp->next[curr] = temp;
                tmp = temp;
            }
        }
        // tmp->isTerminal = true;
        // cout << "here1";
        return;
     }

     bool empty(){
        return root->isTerminal;
     }

     int GetMaxXOR(int x){
        Node *tmp = root;
        int ans = 0;
        for(int i=31; i>=0; i--){
            int curr = ((x>>i) & 1);

            if(tmp->next[(!curr)]!=NULL){
                tmp = tmp->next[!curr];
                ans = (ans | (1<<i));

            } else {
                tmp = tmp->next[curr];
            }
        }

        return ans;
     }
};

bool compare(vector<int> a, vector<int> b){
    return b[1] > a[1];
}

// Approach: Sort the queries based on the second element, which is limit.
// only insert those elements which are under limit.
// then find maximum XOR.
// we also need to maintain indices of each query as we need to return answer in that order.
vector<int> GetSolution(vector<int> arr, vector<vector<int>> queries){
    int q = queries.size();
    int n = arr.size();

    for(int i=0; i<q; i++){
        queries[i].push_back(i);
    }

    // O(NLogN) + O(QLogQ) Time
    sort(arr.begin(), arr.end());
    sort(queries.begin(), queries.end(), compare);

    vector<int> ans(q, -1);
    if(n==1) return ans;

    Trie *trie = new Trie();
    int i=0;
    // O(Q*32) + O(N)
    for(auto qi: queries){
        // this will run only for N times.
        while(i<n and arr[i] <= qi[1]){
            trie->insert(arr[i]);
            i++;
        }

        // only check XOR if trie is not empty.
        // each time this will run 32 times.
        if(!trie->empty()){
            ans[qi[2]] = trie->GetMaxXOR(qi[0]);
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {0, 0, 0, 0, 0};

    vector<vector<int>> qs = {
        {1, 0},
        {1 ,1}
    };

    vector<int> ans = GetSolution(arr, qs);

    for(int i: ans){
        cout << i << " ";
    }
    
    return 0;
}