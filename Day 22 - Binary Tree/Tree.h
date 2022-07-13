#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;

        Node(int x){
            data = x;
            left = right = NULL;
        }
};

class Tree {

    Node *fromLevelOrder(vector<int> &level){
        if(level.size()==0) return NULL;
        queue<Node*> q;
        int i=1;
        Node *root = new Node(level[0]);
        q.push(root);
        while(!q.empty()){
            Node *tmp = q.front();
            q.pop();

            if(level[i]==-1){
                i++;
                tmp->left = NULL;
            } else {
                Node *left = new Node(level[i++]);
                tmp->left = left;
                q.push(left);
            }

            if(level[i]==-1){
                i++;
                tmp->right = NULL;
            } else {
                Node *right = new Node(level[i++]);
                tmp->right = right;
                q.push(right);
            }

        }

        return root;
    }

    void traverseHelper(Node *node){
        if(!node) return;

        traverseHelper(node->left);
        cout << node->data << " ";
        traverseHelper(node->right);

        return;
    }

    public:
        Node *root=NULL;

        Tree(vector<int> in){
            root = fromLevelOrder(in);
        }

        Node *getRoot(){
            return root;
        }

        void traverse(){
            traverseHelper(root);
            cout << endl;
            return;
        }
};