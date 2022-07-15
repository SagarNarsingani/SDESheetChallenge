#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class graphNode{
    public:
        int data;
        vector<graphNode*> nbrs;

        graphNode(int d){
            data = d;
        }

        ~graphNode(){
            for(auto i: nbrs){
                delete i;
            }
        }
};

void traverse(graphNode *root){
    queue<graphNode *> q;
    q.push(root);

    vector<bool> visited(100005, false);
    visited[root->data] = true;
    while(!q.empty()){
        graphNode *tmp = q.front();
        q.pop();

        cout << tmp->data << " ";
        for(auto i: tmp->nbrs){
            if(!visited[i->data]){
                q.push(i);
                visited[i->data] = true;
            }
        }
    }
}